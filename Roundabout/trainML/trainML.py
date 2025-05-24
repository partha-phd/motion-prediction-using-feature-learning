# TRAINING OF MACHINE LEARNING ALGORITHMS TO MAP AOGs TO POGs

# Import the necessary libraries
import tensorflow as tf
import numpy as np
import scipy.io as sio
import matplotlib.pyplot as plt
import os.path
from sklearn.ensemble import RandomForestRegressor
import pickle
import os
import pathlib
from joblib import Parallel, delayed
import multiprocessing


# Respective classes
class AOG:
    def __init__(self):
        # Loading a mat file
        data = os.getcwd() + "\\generatedData\\AOG_Training_1"
        data_file = sio.loadmat(data)
        train_input_1 = data_file["AOG_Training_1"]
        data = os.getcwd() + "\\generatedData\\AOG_Training_2"
        data_file = sio.loadmat(data)
        train_input_2 = data_file["AOG_Training_2"]
        self.train_input = np.concatenate((train_input_1, train_input_2))
        self.num_train_examples = 0
        self.train_epoch_completed = 0
        self.train_index_in_epoch = 0

    def next_train_batch(self, images, batch_size):
        start = self.train_index_in_epoch
        self.train_index_in_epoch += batch_size
        if self.train_index_in_epoch > self.num_train_examples:
            self.train_epoch_completed += 1
            start = 0
            self.train_index_in_epoch = batch_size
            assert batch_size <= self.num_train_examples
        end = self.train_index_in_epoch
        return images[start:end]

    def load_train_data(self, batch_size):
        input_train_np = self.next_train_batch(self.train_input, batch_size)
        return input_train_np


class POG:
    def __init__(self):
        # Loading a mat file
        data = os.getcwd() + "\\generatedData\\POG_Training_1"
        data_file = sio.loadmat(data)
        train_input_1 = data_file["POG_Training_1"]
        data = os.getcwd() + "\\generatedData\\POG_Training_2"
        data_file = sio.loadmat(data)
        train_input_2 = data_file["POG_Training_2"]
        data = os.getcwd() + "\\generatedData\\POG_Training_3"
        data_file = sio.loadmat(data)
        train_input_3 = data_file["POG_Training_3"]
        data = os.getcwd() + "\\generatedData\\POG_Training_4"
        data_file = sio.loadmat(data)
        train_input_4 = data_file["POG_Training_4"]
        data = os.getcwd() + "\\generatedData\\POG_Training_5"
        data_file = sio.loadmat(data)
        train_input_5 = data_file["POG_Training_5"]
        data = os.getcwd() + "\\generatedData\\POG_Training_6"
        data_file = sio.loadmat(data)
        train_input_6 = data_file["POG_Training_6"]
        self.train_input = np.concatenate((train_input_1, train_input_2, train_input_3, train_input_4,
                                           train_input_5, train_input_6))
        self.train_input = self.train_input[..., np.newaxis]
        self.num_train_examples = 0
        self.train_epoch_completed = 0
        self.train_index_in_epoch = 0

    def next_train_batch(self, images, batch_size):
        start = self.train_index_in_epoch
        self.train_index_in_epoch += batch_size
        if self.train_index_in_epoch > self.num_train_examples:
            self.train_epoch_completed += 1
            start = 0
            self.train_index_in_epoch = batch_size
            assert batch_size <= self.num_train_examples
        end = self.train_index_in_epoch
        return images[start:end]

    def load_train_data(self, batch_size):
        input_train_np = self.next_train_batch(self.train_input, batch_size)
        return input_train_np


# Variational AutoEncoder - 1
def variational_autoencoder_AOG(input_shape=None, n_latent=None):
    # Initialise input to the network
    if n_latent is None:
        n_latent = [None]
    if input_shape is None:
        input_shape = [None, 140, 180, 5]
    x = tf.placeholder(tf.float32, input_shape, name='x')

    # Encoder-----------------------------------------------------------------------------------------------------------
    # Convolution
    conv_1 = tf.layers.conv2d(inputs=x, filters=32, kernel_size=(4, 4),
                              padding='same', strides=(2, 2), activation=tf.nn.leaky_relu)
    conv_2 = tf.layers.conv2d(inputs=conv_1, filters=64, kernel_size=(4, 4),
                              padding='same', strides=(2, 2), activation=tf.nn.leaky_relu)
    conv_3 = tf.layers.conv2d(inputs=conv_2, filters=128, kernel_size=(4, 4),
                              padding='same', strides=(1, 1), activation=tf.nn.leaky_relu)

    # Reshaping
    dense_1 = tf.contrib.layers.flatten(conv_3)
    dense_2 = tf.layers.dense(inputs=dense_1, units=2000, activation=tf.nn.leaky_relu)

    # Sampling----------------------------------------------------------------------------------------------------------
    # Mean and standard deviation
    latent_space_mn = tf.layers.dense(inputs=dense_2, units=n_latent)
    latent_space_sd = 0.5 * tf.layers.dense(inputs=dense_2, units=n_latent)
    # Random sampling from normal distribution
    epsilon = tf.random_normal(tf.stack([tf.shape(dense_2)[0], n_latent]))
    z = (latent_space_mn + tf.multiply(epsilon, tf.exp(latent_space_sd)))

    # Decoder-----------------------------------------------------------------------------------------------------------
    # Fully connected layer
    dense_3 = tf.layers.dense(inputs=z, units=2000, activation=tf.nn.leaky_relu)
    dense_4 = tf.layers.dense(inputs=dense_3, units=4725, activation=tf.nn.leaky_relu)
    reshape_1 = tf.reshape(dense_4, [-1, 35, 45, 3])
    # Transposed Convolution
    deconv_1 = tf.layers.conv2d_transpose(inputs=reshape_1, filters=128, kernel_size=(4, 4),
                                          strides=(2, 2), padding='same', activation=tf.nn.leaky_relu)
    deconv_2 = tf.layers.conv2d_transpose(inputs=deconv_1, filters=64, kernel_size=(4, 4),
                                          strides=(2, 2), padding='same', activation=tf.nn.leaky_relu)
    deconv_3 = tf.layers.conv2d_transpose(inputs=deconv_2, filters=5, kernel_size=(4, 4),
                                          strides=(1, 1), padding='same')

    # Reconstruction
    y = deconv_3

    # Cost
    img_loss = tf.reduce_sum(tf.square(y - x))
    latent_loss = -0.5 * tf.reduce_sum(1.0 + latent_space_sd - tf.square(latent_space_mn)
                                       - tf.exp(latent_space_sd), 1)
    cost = tf.reduce_mean(img_loss + latent_loss)

    # return the desired output (input, latent representation, mean, standard deviation,
    #                            reconstructed output and cost)
    return {'x': x, 'z': z, 'latent_space_mn': latent_space_mn, 'latent_space_sd': latent_space_sd,
            'y': y, 'cost': cost}


# Variational Autoencoder - 2
def variational_autoencoder_POG(input_shape=None, n_latent=None):
    # Initialise input to the network
    if n_latent is None:
        n_latent = [None]
    if input_shape is None:
        input_shape = [None, 140, 180, 1]
    x = tf.placeholder(tf.float32, input_shape, name='x')

    # Encoder-----------------------------------------------------------------------------------------------------------
    # Convolution
    conv_1 = tf.layers.conv2d(inputs=x, filters=32, kernel_size=(4, 4),
                              padding='same', strides=(2, 2), activation=tf.nn.leaky_relu)
    conv_1_bn = tf.layers.batch_normalization(inputs=conv_1)
    conv_2 = tf.layers.conv2d(inputs=conv_1_bn, filters=64, kernel_size=(4, 4),
                              padding='same', strides=(2, 2), activation=tf.nn.leaky_relu)
    conv_2_bn = tf.layers.batch_normalization(inputs=conv_2)
    conv_3 = tf.layers.conv2d(inputs=conv_2_bn, filters=128, kernel_size=(4, 4),
                              padding='same', strides=(1, 1), activation=tf.nn.leaky_relu)
    conv_3_bn = tf.layers.batch_normalization(inputs=conv_3)
    # Reshaping
    dense_1 = tf.contrib.layers.flatten(conv_3_bn)
    dense_2 = tf.layers.dense(inputs=dense_1, units=1000, activation=tf.nn.leaky_relu)
    dense_2_bn = tf.layers.batch_normalization(inputs=dense_2)
    # Sampling----------------------------------------------------------------------------------------------------------
    # Mean and standard deviation
    latent_space_mn = tf.layers.dense(inputs=dense_2_bn, units=n_latent)
    latent_space_sd = 0.5 * tf.layers.dense(inputs=dense_2_bn, units=n_latent)
    # Random sampling from normal distribution
    epsilon = tf.random_normal(tf.stack([tf.shape(dense_2_bn)[0], n_latent]))
    z = (latent_space_mn + tf.multiply(epsilon, tf.exp(latent_space_sd)))
    # Decoder-----------------------------------------------------------------------------------------------------------
    # Fully connected layer
    dense_3 = tf.layers.dense(inputs=z, units=1000, activation=tf.nn.leaky_relu)
    dense_4 = tf.layers.dense(inputs=dense_3, units=3150, activation=tf.nn.leaky_relu)
    reshape_1 = tf.reshape(dense_4, [-1, 35, 45, 2])
    # Transposed Convolution
    deconv_1 = tf.layers.conv2d_transpose(inputs=reshape_1, filters=128, kernel_size=(4, 4),
                                          strides=(2, 2), padding='same', activation=tf.nn.leaky_relu)
    deconv_1_bn = tf.layers.batch_normalization(inputs=deconv_1)
    deconv_2 = tf.layers.conv2d_transpose(inputs=deconv_1_bn, filters=64, kernel_size=(4, 4),
                                          strides=(2, 2), padding='same', activation=tf.nn.leaky_relu)
    deconv_2_bn = tf.layers.batch_normalization(inputs=deconv_2)
    deconv_3 = tf.layers.conv2d_transpose(inputs=deconv_2_bn, filters=1, kernel_size=(4, 4),
                                          strides=(1, 1), padding='same')

    # Reconstruction
    y = deconv_3

    # Cost
    recon_loss = tf.reduce_sum(tf.square(y - x))
    latent_loss = -0.5 * tf.reduce_sum(1.0 + latent_space_sd - tf.square(latent_space_mn)
                                       - tf.exp(latent_space_sd), 1)
    cost = tf.reduce_mean(recon_loss + latent_loss)

    # return the desired output (input, latent representation, mean, standard deviation,
    #                            reconstructed output and cost)
    return {'x': x, 'z': z, 'latent_space_mn': latent_space_mn, 'latent_space_sd': latent_space_sd,
            'y': y, 'cost': cost}


# Random Forest
def predict_RF_output(no_of_pixels, test_input, t_val):
    file_name = os.getcwd() + '\\trainedModel\\trainedModel_RF\\' + t_val + '\\' + str(no_of_pixels)
    trained_model = pickle.load(open(file_name, 'rb'))
    test_output = trained_model.predict(test_input)
    return test_output


def train_random_forest(no_of_pixels, train_input, train_output, t_val):
    regression_model = RandomForestRegressor(n_estimators=50, min_samples_split=10, min_samples_leaf=5, random_state=0)
    regression_model.fit(train_input, train_output)
    file_name = os.getcwd() + '\\trainedModel\\trainedModel_RF\\' + t_val + '\\' + str(no_of_pixels)
    pickle.dump(regression_model, open(file_name, 'wb'))


if __name__ == '__main__':
    # Information about the dataset
    num_trainData = 1582

    print('START: Training of VAE-1')
    # Load the dataset
    DATASET = AOG()
    DATASET.num_train_examples = num_trainData
    # Hyper-parameters for training
    batch_size = 113
    n_latent_AOG = 1000
    n_epochs = 50
    learning_rate = 0.0005
    global_step = tf.Variable(0, name='global_step', trainable=False)

    # Calling the autoencoder
    vae_AOG = variational_autoencoder_AOG(n_latent=n_latent_AOG)

    # Define the optimization function
    optimizer = tf.train.AdamOptimizer(learning_rate).minimize(vae_AOG['cost'])

    # Add ops to save and restore all the variables
    saver = tf.train.Saver()

    # We create a session to use the graph
    sess = tf.Session()
    trainedModel = pathlib.Path("trainedModel\\model_VAE_AOG.ckpt.data-00000-of-00001")
    if trainedModel.exists():
        saver.restore(sess, "trainedModel\\model_VAE_AOG.ckpt")
        print("Restoring previously trained model of VAE_AOG")
    else:
        sess.run(tf.global_variables_initializer())
        print("Training VAE_AOG from scratch")

    # Performing the training
    for epoch_i in range(n_epochs):
        for batch_i in range(DATASET.num_train_examples // batch_size):
            train = DATASET.load_train_data(batch_size)
            sess.run(optimizer, feed_dict={vae_AOG['x']: train})
            features_train, recon_train = sess.run([vae_AOG['z'], vae_AOG['y']], feed_dict={vae_AOG['x']: train})
            if batch_i == 0:
                features_AOG_save = features_train
                recon_AOG_save = recon_train
                AOG_save = train
            else:
                features_AOG_save = np.concatenate((features_AOG_save, features_train))
                recon_AOG_save = np.concatenate((recon_AOG_save, recon_train))
                AOG_save = np.concatenate((AOG_save, train))
        print('Training Epoch: ', epoch_i, 'Training Cost: ', sess.run(vae_AOG['cost'],
                                                                       feed_dict={vae_AOG['x']: train}))

    # Saving the trained model
    save_path = saver.save(sess, "trainedModel\\model_VAE_AOG.ckpt")

    # Save the latent representation and the reconstructed AOG as a mat file
    output_VAE_1 = {'featuresAOG_Training': features_AOG_save}
    saveDir = os.getcwd() + '\\generatedData\\featuresAOG_Training'
    sio.savemat(saveDir, output_VAE_1)

    # Plot an example reconstruction of the data
    fig = plt.figure()
    a = fig.add_subplot(1, 2, 1)
    plt.imshow(recon_AOG_save[0, :, :, 0])
    a.set_title('Reconstructed AOG')
    a = fig.add_subplot(1, 2, 2)
    plt.imshow(AOG_save[0, :, :, 0])
    a.set_title('Ground truth AOG')
    fig.show()
    plt.draw()
    plt.waitforbuttonpress()

    print('END: Training of VAE-1')
    # ------------------------------------------------------------------------------------------------------------------
    print('START: Training of VAE-2')
    # Load the dataset
    DATASET = POG()
    DATASET.num_train_examples = num_trainData*50

    # Hyper-parameters for training
    batch_size = 100
    n_latent_POG = 100
    n_epochs = 0
    learning_rate = 0.0001
    global_step = tf.Variable(0, name='global_step', trainable=False)

    # Calling the autoencoder
    vae_POG = variational_autoencoder_POG(n_latent=n_latent_POG)

    # Define the optimization function
    optimizer = tf.train.AdamOptimizer(learning_rate).minimize(vae_POG['cost'])

    # Add ops to save and restore all the variables
    saver = tf.train.Saver()

    # We create a session to use the graph
    sess = tf.Session()
    trainedModel = pathlib.Path("trainedModel\\model_VAE_POG.ckpt.data-00000-of-00001")
    if trainedModel.exists():
        saver.restore(sess, "trainedModel\\model_VAE_POG.ckpt")
        print("Restoring previously trained model of VAE_POG")
    else:
        sess.run(tf.global_variables_initializer())
        print("Training VAE_POG from scratch")

    # Performing the training
    for epoch_i in range(n_epochs):
        for batch_i in range(DATASET.num_train_examples // batch_size):
            train = DATASET.load_train_data(batch_size)
            sess.run(optimizer, feed_dict={vae_POG['x']: train})
            features_train, recon_train = sess.run([vae_POG['z'], vae_POG['y']], feed_dict={vae_POG['x']: train})
            if batch_i == 0:
                features_POG_save = features_train
                recon_POG_save = recon_train
                POG_save = train
            else:
                features_POG_save = np.concatenate((features_POG_save, features_train))
                recon_POG_save = np.concatenate((recon_POG_save, recon_train))
                POG_save = np.concatenate((POG_save, train))
        print('Training Epoch: ', epoch_i, 'Training Cost: ', sess.run(vae_POG['cost'],
                                                                       feed_dict={vae_POG['x']: train}))

    # Saving the trained model
    save_path = saver.save(sess, "trainedModel\\model_VAE_POG.ckpt")

    # Save the latent representation and the reconstructed POG as a mat file
    output_VAE_2 = {'featuresPOG_Training': features_POG_save}
    saveDir = os.getcwd() + '\\generatedData\\featuresPOG_Training'
    sio.savemat(saveDir, output_VAE_2)

    # Plot an example reconstruction of the data
    fig = plt.figure()
    a = fig.add_subplot(1, 2, 1)
    plt.imshow(recon_POG_save[0, :, :, 0])
    a.set_title('Reconstructed POG')
    a = fig.add_subplot(1, 2, 2)
    plt.imshow(POG_save[0, :, :, 0])
    a.set_title('Ground truth POG')
    fig.show()
    plt.draw()
    plt.waitforbuttonpress()

    print('END: Training of VAE-2')
    # ------------------------------------------------------------------------------------------------------------------
    print('START: Training of set of RFs')
    num_cores = multiprocessing.cpu_count()
    data_id = np.arange(13, 50, 12)
    str_array = ["t_05", "t_10", "t_15", "t_20"]
    try:
        os.makedirs("trainedModel\\trainedModel_RF\\t_05")
    except FileExistsError:
        print("Directory already exists")
    try:
        os.makedirs("trainedModel\\trainedModel_RF\\t_10")
    except FileExistsError:
        print("Directory already exists")
    try:
        os.makedirs("trainedModel\\trainedModel_RF\\t_15")
    except FileExistsError:
        print("Directory already exists")
    try:
        os.makedirs("trainedModel\\trainedModel_RF\\t_20")
    except FileExistsError:
        print("Directory already exists")
    # Set of RFs trained to predict POGs from 0 to 2s with step size of 0.5s
    for j in range(4):
        train_id = np.arange(data_id[j], num_trainData * 50, 50)
        t_val_str = str_array[j]
        print(train_id)
        Parallel(n_jobs=num_cores)(delayed(train_random_forest)(i, features_AOG_save, features_POG_save[train_id, i],
                                                                t_val_str) for i in range(n_latent_POG))
        # predicted_output = np.transpose(
        #    Parallel(n_jobs=num_cores)(delayed(predict_RF_output)(i, features_AOG_save, t_val_str)
        #                               for i in range(n_latent_POG)))
        # if j == 0:
        #    predicted_output_save = predicted_output
        # else:
        #    predicted_output_save = np.concatenate((predicted_output_save, predicted_output))
    # output_RF = {'features_POG_predicted': predicted_output_save}
    # saveDir = os.getcwd() + '\\generatedData\\featuresPOG_Predicted'
    # sio.savemat(saveDir, output_RF)
    print('END: Training of set of RFs')
    # ------------------------------------------------------------------------------------------------------------------

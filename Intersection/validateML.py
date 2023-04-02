# VALIDATION OF MACHINE LEARNING ALGORITHMS TO MAP AOGs TO POGs

# Import the necessary libraries
import tensorflow as tf
import numpy as np
import scipy.io as sio
import matplotlib.pyplot as plt
import os.path
import time
import pickle
import os
from joblib import Parallel, delayed
import multiprocessing


# Respective classes
class AOG:
    def __init__(self):
        # Loading a mat file
        data = os.getcwd() + "\\generatedData\\AOG_Validation_1"
        data_file = sio.loadmat(data)
        test_input_1 = data_file["AOG_Validation_1"]
        data = os.getcwd() + "\\generatedData\\AOG_Validation_2"
        data_file = sio.loadmat(data)
        test_input_2 = data_file["AOG_Validation_2"]
        self.test_input = np.concatenate((test_input_1, test_input_2))
        self.num_test_examples = 0
        self.test_epoch_completed = 0
        self.test_index_in_epoch = 0

    def next_test_batch(self, images, batch_size):
        start = self.test_index_in_epoch
        self.test_index_in_epoch += batch_size
        if self.test_index_in_epoch > self.num_test_examples:
            self.test_epoch_completed += 1
            start = 0
            self.test_index_in_epoch = batch_size
            assert batch_size <= self.num_test_examples
        end = self.test_index_in_epoch
        return images[start:end]

    def load_test_data(self, batch_size):
        input_test_np = self.next_test_batch(self.test_input, batch_size)
        return input_test_np


class POG:
    def __init__(self):
        # Loading a mat file
        data = os.getcwd() + "\\generatedData\\POG_Validation_1"
        data_file = sio.loadmat(data)
        test_input_1 = data_file["POG_Validation_1"]
        data = os.getcwd() + "\\generatedData\\POG_Training_2"
        data_file = sio.loadmat(data)
        test_input_2 = data_file["POG_Training_2"]
        data = os.getcwd() + "\\generatedData\\POG_Training_3"
        data_file = sio.loadmat(data)
        test_input_3 = data_file["POG_Training_3"]
        self.test_input = np.concatenate((test_input_1, test_input_2, test_input_3))
        self.test_input = self.test_input[..., np.newaxis]
        self.num_test_examples = 0
        self.test_epoch_completed = 0
        self.test_index_in_epoch = 0

    def next_test_batch(self, images, batch_size):
        start = self.test_index_in_epoch
        self.test_index_in_epoch += batch_size
        if self.test_index_in_epoch > self.num_test_examples:
            self.test_epoch_completed += 1
            start = 0
            self.test_index_in_epoch = batch_size
            assert batch_size <= self.num_test_examples
        end = self.test_index_in_epoch
        return images[start:end]

    def load_test_data(self, batch_size):
        input_test_np = self.next_test_batch(self.test_input, batch_size)
        return input_test_np


# Variational AutoEncoder - 1
def variational_autoencoder_AOG(input_shape=None, n_latent=None):
    # Initialise input to the network
    if n_latent is None:
        n_latent = [None]
    if input_shape is None:
        input_shape = [None, 100, 160, 5]
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
    dense_4 = tf.layers.dense(inputs=dense_3, units=3000, activation=tf.nn.leaky_relu)
    reshape_1 = tf.reshape(dense_4, [-1, 25, 40, 3])
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


# Variational AutoEncoder - 2
def variational_autoencoder_POG(input_shape=None,  n_latent=None):
    # Initialise input to the network
    if n_latent is None:
        n_latent = [None]
    if input_shape is None:
        input_shape = [None, 100, 160, 1]
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
    dense_4 = tf.layers.dense(inputs=dense_3, units=2000, activation=tf.nn.leaky_relu)
    reshape_1 = tf.reshape(dense_4, [-1, 25, 40, 2])
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


if __name__ == '__main__':
    num_validation = 994
    prediction_time = np.zeros([num_validation, 1])
    # Load the dataset
    INPUT_DATASET = AOG()
    OUTPUT_DATASET = POG()
    INPUT_DATASET.num_test_examples = num_validation
    OUTPUT_DATASET.num_test_examples = 50*num_validation

    # Hyper-parameters
    batch_size = 1
    n_latent_AOG = 1000
    n_latent_POG = 100
    num_cores = multiprocessing.cpu_count()

    # Perform the validation
    for k in range(num_validation):
        if k == 0:
            # Calling the autoencoder
            vae_AOG = variational_autoencoder_AOG(n_latent=n_latent_AOG)
            # Add ops to save and restore all the variables
            sess1 = tf.Session()
            saver = tf.train.Saver()
            saver.restore(sess1, "trainedModel\\model_VAE_AOG.ckpt")

        print('START: Prediction')
        # Performing the validation
        test_input = INPUT_DATASET.load_test_data(batch_size)
        test_output = OUTPUT_DATASET.load_test_data(batch_size*50)

        recon_AOG = sess1.run(vae_AOG['y'], feed_dict={vae_AOG['x']: test_input})
        start = time.time()
        features_AOG = sess1.run(vae_AOG['z'], feed_dict={vae_AOG['x']: test_input})
        end = time.time()
        VAE_1_time = end-start

        if k == 0:
            recon_AOG_save = recon_AOG
            features_AOG_save = features_AOG
            test_input_save = test_input
            test_output_save = test_output

        else:
            recon_AOG_save = np.concatenate((recon_AOG_save, recon_AOG))
            features_AOG_save = np.concatenate((features_AOG_save, features_AOG))
            test_input_save = np.concatenate((test_input_save, test_input))
            test_output_save = np.concatenate((test_output_save, test_output))

        # ------------------------------------------------------------------------------------------------------------------

        data_id = np.arange(13, 50, 12)
        str_array = ["t_05", "t_10", "t_15", "t_20"]
        # Set of RFs trained to predict POGs from 0 to 3s with step size of 0.5s
        RF_time = 0
        for j in range(4):
            train_id = np.arange(data_id[j], 1 * 50, 50)
            t_val_str = str_array[j]
            start = time.time()
            predicted_output = Parallel(n_jobs=num_cores)(delayed(predict_RF_output)(i, features_AOG, t_val_str)
                                                          for i in range(n_latent_POG))
            predicted_output = np.transpose(np.stack(predicted_output, axis=0))
            if j == 0:
                predicted_output_save = predicted_output
            else:
                predicted_output_save = np.concatenate((predicted_output_save, predicted_output), axis=0)
            end = time.time()
            RF_time = RF_time + (end-start)
        if k == 0:
            features_POG_save = predicted_output_save
        else:
            features_POG_save = np.concatenate((features_POG_save, predicted_output_save))

    # ------------------------------------------------------------------------------------------------------------------
    # Calling the autoencoder
        if k == 0:
            vae_POG = variational_autoencoder_POG(n_latent=n_latent_POG)
            # Add ops to save and restore all the variables
            saver = tf.train.Saver()

            # We create a session to use the graph
            sess2 = tf.Session()
            saver.restore(sess2, "trainedModel\\model_VAE_POG.ckpt")

        diff_vec = np.zeros([4, n_latent_POG])
        latent_input = np.zeros([50, n_latent_POG])
        counter = 0
        # Projection of the current state in the latent space
        vae_POG_input = test_input[0, :, :, 0]
        vae_POG_input = vae_POG_input[np.newaxis, ..., np.newaxis]
        latent_initial = sess2.run([vae_POG['z']], feed_dict={vae_POG['x']: vae_POG_input})
        latent_initial = np.squeeze(np.asarray(latent_initial), axis=0)
        predicted_output_save = np.concatenate((latent_initial, predicted_output_save), axis=0)
        # Interpolation in latent space
        for i in range(4):
            diff_vec[i, :] = np.subtract(predicted_output_save[i+1, :], predicted_output_save[i, :])
            if i == 0:
                for j in range(13):
                    latent_input[counter, :] = predicted_output_save[i, :]+(diff_vec[i, :]*j*0.0769)
                    counter = counter+1
            elif i == 3:
                for j in range(13):
                    latent_input[counter, :] = predicted_output_save[i, :] + (diff_vec[i, :] * j * 0.0833)
                    counter = counter + 1
            else:
                for j in range(12):
                    latent_input[counter, :] = predicted_output_save[i, :] + (diff_vec[i, :] * j * 0.0833)
                    counter = counter + 1

        # Performing the validation
        start = time.time()
        recon_POG = sess2.run([vae_POG['y']], feed_dict={vae_POG['z']: latent_input})
        end = time.time()
        VAE_2_time = end-start
        if k == 0:
            recon_POG_save = recon_POG
            latent_save = latent_input
        else:
            recon_POG_save = np.concatenate((recon_POG_save, recon_POG))
            latent_save = np.concatenate((latent_save, latent_input))
        print('END: Prediction')
        prediction_time[k] = VAE_1_time + RF_time + VAE_2_time
        print('Prediction time: ', prediction_time[k])
    # ------------------------------------------------------------------------------------------------------------------

    # Saving the required variables
    # Save the latent representation and the reconstructed AOG as a mat file
    output_VAE_1 = {'featuresAOG_Validation': features_AOG_save, 'reconAOG_Validation': recon_AOG_save,
                    'AOG_Validation': test_input_save}
    saveDir = os.getcwd() + '\\generatedData\\featuresAOG_Validation'
    sio.savemat(saveDir, output_VAE_1)
    # Save the output from the RF as a mat file
    output_RF = {'featuresPOG_Validation': features_POG_save, 'reconPOG_Validation': recon_POG_save,
                 'POG_Validation':test_output_save}
    saveDir = os.getcwd() + '\\generatedData\\featuresPOG_Validation'
    sio.savemat(saveDir, output_RF)
    recon_test_save = np.asarray(recon_POG_save)
    # Save the prediction time
    output_Prediction = {'Prediction_Time': prediction_time}
    saveDir = os.getcwd() + '\\generatedData\\Prediction_time'
    sio.savemat(saveDir, output_Prediction)

    # Plot an example reconstruction of the data (AOG and POG)
    exampleID = 1
    fig = plt.figure()
    a = fig.add_subplot(1, 3, 1)
    plt.imshow(test_input_save[exampleID, :, :, 0])
    a.set_title('Initial configuration')
    a.axis('off')
    a = fig.add_subplot(1, 3, 2)
    plt.imshow(np.squeeze(recon_POG_save[exampleID, 49, :, :]))
    a.set_title('Reconstructed POG')
    a.axis('off')
    a = fig.add_subplot(1, 3, 3)
    plt.imshow(np.squeeze(test_output_save[49*(exampleID+1), :, :, 0]))
    a.set_title('Ground truth POG')
    a.axis('off')
    fig.show()
    plt.draw()
    plt.waitforbuttonpress()



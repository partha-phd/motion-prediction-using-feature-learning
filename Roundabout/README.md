# 🛣️ Roundabout

This folder contains the files for the motion prediction on roundabout scenarios.  
![Estimation of Predicted Occupancy Grid Maps](https://github.com/user-attachments/assets/e28881ed-ee49-4535-9c1d-4b107c07f984)


## Overview

The `Roundabout` directory contains code, scripts, and data related to the motion prediction of traffic participants based on a roundabout in Ingolstadt, Germany.  
The source code for the extraction and generation of predicted Occupancy Grid Maps (pOGMs) based on model-based and machine learning-based approaches is provided.

## 📁 Folder Structure

- `dataExtraction/`: Source code files for the extraction of relevant data from the drone footage of the roundabout. 
- `dataGeneration/`: Source code files for the generation of pOGMs from the highD dataset based on the model-based approach.  
- `trainML/`: Source code files for the training and validation of machine learning algorithms. 

## 🚀 Getting Started

1. **Prerequisites**  
   - Matlab (tested on v2023.b)
   - Python (3.12)
   - Tensorflow and related libraries (Refer to [requirements.txt](requirements.txt))
2. **Usage**  
   - Navigate to the folder [dataExtraction](dataExtraction/).
   - Run the script `extractData.m` in the Matlab environment.
   - The script will generate a `roundaboutScenario.mat` file that contains the necessary information for the generation of augmented Occupancy Grid Maps and predicted Occupancy Grid Maps.
   - Navigate then to the folder [dataGeneration](dataGeneration/). 
   - Run the script `generateData.m` in the Matlab environment.
   - This will generate the data (augmented Occupancy Grid Maps and predicted Occupancy Grid Maps) based on the model-based approach in a folder named `generatedData/`.
   - Navigate to the [trainML](trainML/) folder. 
   - Run the script `python trainML.py` to train the machine learning algorithms.
   - After training, run the script `python validateML.py` to validate the machine learning algorithms on a test set. 

## Contributing

Contributions are welcome!  
Please open an issue or submit a pull request if you have suggestions or improvements.

## Contact

For questions or feedback, please contact [partha92](https://github.com/partha92) or create an issue in the main repository.

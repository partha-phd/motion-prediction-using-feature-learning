# 🛣️ Intersection

This folder contains the files for the motion prediction on intersection scenarios. 
![Estimation of Predicted Occupancy Grid Maps](https://github.com/user-attachments/assets/aa593016-cb39-41c0-b699-c27412c128c8)

## Overview

The `Intersection` directory contains code, scripts, and data related to the motion prediction of traffic participants based on the data generated from a T-junction scenario at the CARISSMA Outdoor test track facility.  
The source code for the extraction and generation of predicted Occupancy Grid Maps (pOGMs) based on model-based and machine learning-based approaches is provided.

## 📁 Folder Structure

- `dataGeneration/`: Source code files for the generation of pOGMs from the highD dataset based on the model-based approach.  
- `trainML/`: Source code files for the training and validation of machine learning algorithms. 

## 🚀 Getting Started

1. **Prerequisites**  
   - Matlab (tested on v2023.b)
   - Python (3.12)
   - Tensorflow
   - Related libraries (Refer to [requirements.txt](requirements.txt))
     
2. **Usage**  
   - The data for the generation of augmented Occupancy Grid Maps and predicted Occupancy Grid Maps is available in the [data](dataGeneration/data/) folder. 
   - Run the script `generateData.m` in the Matlab environment.
   - This will generate the data based on the model-based approach in a folder named `generatedData/`.
   - Navigate to the [trainML](trainML/) folder. 
   - Run the script `python trainML.py` to train the machine learning algorithms to estimate the pOGMs for different time instances using aOGMs as input.
   - After training, run the script `python validateML.py` to validate the machine learning algorithms on a test set. 

## Contributing

Contributions are welcome!  
Please open an issue or submit a pull request if you have suggestions or improvements.

## Contact

For questions or feedback, please contact [partha92](https://github.com/partha92) or create an issue in the main repository.

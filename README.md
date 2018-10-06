# Plate Number Recognition (PNR)
## Intorduction to PNR
The main implement of PNR is __`image segmentation`__ and __`feature extraction`__, **`pattern recognition`**, and two main pattern 
recgonition algorithm **`Support Vector Machine`** and 
**`Artificial Neural Networks`**.

The two main parts of PNR are: 
* Plate detction
* Plate recognition


## Plate detection
All the processes involved in plate detection
* Sobel filter
* Threshold operation
* Close morphologic operation
* Mask of one filled area
* Possible detected plates marked in red (features images)
* Detected places after the SVM classifier

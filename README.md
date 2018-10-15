# Plate Number Recognition (PNR)

Building the project using CMake from the command-line:

```
Linux:
    export OpenCV_DIR="~/OpenCV/build"
    mkdir build
    cd build
    cmake -D OpenCV_DIR=$OpenCV_DIR ..
    make 
```

Running the project
```
./APNR <picture_file>
```
## 1 Intorduction to PNR
The main implement of PNR is __`image segmentation`__ and __`feature extraction`__, **`pattern recognition`**, and two main pattern 
recgonition algorithm **`Support Vector Machine`** and 
**`Artificial Neural Networks`**.

The two main parts of PNR are: 
* Plate detction
* Plate recognition


## 2 Plate detection
All the processes involved in plate detection
* Sobel filter
* Threshold operation
* Close morphologic operation
* Mask of one filled area
* Possible detected plates marked in blue (features images)
* Detected places after the SVM classifier

Our SVM classifier trained with 75 license plate images and 35 images without license plates of 144 \* 33  pixels. This dataset is sufficient enough to get decent results, although it is not large.


![Image of Detiecon](https://github.com/alalba221/pic/blob/master/PNR/dataset.png)
The next images show the all the results of the processes


![Image of Detiecon](https://github.com/alalba221/pic/blob/master/PNR/PlateDetection.png)

 ## 3 Plate recognition
This step is to retrieve the characters of the license plate with optical character recognition (OCR).
 For each detected plate, we proceed to segment the plate for each character, and use an Artificial Neural
 Network (ANN) machine-learning algorithm to recognize the character.
 ### 3.1 OCR segmentation
 We obtain  plate image patch as the input to the segmentation __`OCR function`__ with an equalized histogram, we then need to apply a threshold filter and use this threshold image as the input of a __`Find contours`__ algorithm.
 
  <img width="210" height="300" src="https://github.com/alalba221/pic/blob/master/PNR/OCRSegmentation.png"/>
 
 If a segmented character is verified, we have to process it to set the same size and position for all characters and save it in a vector with auxiliasry _CharSegment_ class. This class saves the segmented character image and the position that we need to order the characters because the Find Contous algorithm does not return the contours in the required order.
 
 ### 3.2 Feature extraction
 This step for each segmented character is to extract the features for training and classifying the Artificial Neural Network algorithm. The features used in here contain `horizontal and vertical accumulation histograms` and `low-resolution image sample`.

<img width="250" height="250" src="https://github.com/alalba221/pic/blob/master/PNR/Feature.png"/>

 ### 3.3 OCR classification
 In the classification step, we use a `Multi-Layer Perceptron (MLP)`, which is the most commonly used ANN algorithm. Our 
 Classifier represents 3-layer perceptron.
 
 the ANN's `predict` function returns a row with the size equal to the number of classes with the probability of belonging to the 
 input feature of each class.
 
 <img width="320" height="220" src="https://github.com/alalba221/pic/blob/master/PNR/OCRClassify.png"/>

 <img width="320" height="280" src="https://github.com/alalba221/PlateNumberRecognition/blob/master/screenshot%202.png"/>

 <img width="320" height="320" src="https://github.com/alalba221/PlateNumberRecognition/blob/master/screenshot%203.png"/>
 

import cv2
import numpy as np
img=cv2.imread('D:\Coding\OpenCV\IMG&MP4\Cat.jpg')
# cv2.imshow('img',img)
# cv2.waitKey(0)

#灰階圖片
grayImg = cv2.cvtColor(img ,cv2.COLOR_BGR2GRAY)
# cv2.imshow('img',grayImg)
# cv2.waitKey(0)

#高斯模糊
blurImg = cv2.GaussianBlur(img,(9,9),5) #(要處理的圖片, Kernel大小(要奇數), 標準差)
# cv2.imshow('img', blurImg)
# cv2.waitKey(0)

#邊緣
cannyImg = cv2.Canny(img, 50 ,100) #(要處理的圖片, 要被省略的分數, 要看成邊緣的分數)
# cv2.imshow('img', cannyImg)
# cv2.waitKey(0)

#邊緣膨脹
kernel = np.ones((5,5),np.uint8)
dilateImg = cv2.dilate(cannyImg, kernel, iterations=1) #(要處理的圖片, kernel大小(二維陣列), 膨脹次數)
# cv2.imshow('img', dilateImg)
# cv2.waitKey(0)

#邊緣變細
erodeImg = cv2.erode(dilateImg, kernel, iterations=1) #跟膨脹一樣
cv2.imshow('img', erodeImg)
cv2.waitKey(0)


import numpy as np
import cv2

catimg = cv2.imread('D:\Coding\OpenCV\IMG&MP4\Cat.jpg') #imread 回傳的值是三維矩陣，一二維是大小，第三維是RGB顏色
#print(np.shape(img)) 

#用矩陣創建自定義圖像(np.uint8代表0-255的正整數)
myimg = np.empty((500,500,3),np.uint8) 
for row in range(500):
    for col in range(500):
        myimg[row][col] = [np.random.randint(0,255),0,0]
# cv2.imshow('img',myimg)
# cv2.waitKey(0)

#切割圖像
newimg = catimg[:300,150:300] 
cv2.imshow('img',newimg)
cv2.waitKey(0)
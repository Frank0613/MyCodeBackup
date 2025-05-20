import cv2
import numpy as np
import Show_Img as SI

catImg = cv2.imread('D:\Coding\OpenCV\IMG&MP4\Oriange.jpg')
catImg = cv2.resize(catImg,(0,0),fx=0.5,fy=0.5)

#先轉成HSV
hsv = cv2.cvtColor(catImg, cv2.COLOR_BGR2HSV)

#新增控制條
def empty():
    pass

cv2.namedWindow('Trackbar') #視窗名稱
cv2.resizeWindow('Trackbar',400,500) #視窗大小

#新增拉桿
cv2.createTrackbar('Hue Min', 'Trackbar', 0, 179,empty)
cv2.createTrackbar('Hue Max', 'Trackbar', 179, 179,empty) 
cv2.createTrackbar('Sat Min', 'Trackbar', 0, 255,empty) 
cv2.createTrackbar('Sat Max', 'Trackbar', 255, 255,empty) 
cv2.createTrackbar('Value Min', 'Trackbar', 0, 255,empty) 
cv2.createTrackbar('Value Max', 'Trackbar', 255, 255,empty) 

#即時取得拉桿數值&結果
while True:
    Hue_Min = cv2.getTrackbarPos('Hue Min', 'Trackbar')
    Hue_Max = cv2.getTrackbarPos('Hue Max', 'Trackbar')
    Sta_Min = cv2.getTrackbarPos('Sat Min', 'Trackbar')
    Sta_Max = cv2.getTrackbarPos('Sat Max', 'Trackbar')
    Val_Min = cv2.getTrackbarPos('Value Min', 'Trackbar')
    Val_Max = cv2.getTrackbarPos('Value Max', 'Trackbar')
    print(Hue_Min,Hue_Max,Sta_Min,Sta_Max,Val_Min,Val_Max)

    #過濾顏色
    Min = np.array([Hue_Min,Sta_Min,Val_Min])
    Max = np.array([Hue_Max,Sta_Max,Val_Max])
    mask = cv2.inRange(hsv,Min,Max) #Min,Max是陣列
    res = cv2.bitwise_and(catImg,catImg,mask=mask) #把IMG上的每個bit做AND運算，再套上mask遮罩(這裡等於把catImg複製到res中再套上遮罩)

    cv2.imshow('mask',mask)
    cv2.imshow('res', res)
    cv2.imshow('Cat', catImg)
    cv2.waitKey(1)

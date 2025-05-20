import cv2
import numpy as np

vid = cv2.VideoCapture(0) #抓鏡頭

PenHSV = [[87,63,63,96,255,255],[41,101,0,139,247,255]] #存綠、藍HSV顏色數據(用Detect_Color找數值)

PenColor=[[0,255,0],[255,0,0]] #存藍、綠RGB顏色數值

DrawPoint = [] #存滑過的路徑

#找到筆位置
def FindPen(img):
    #偵測顏色
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    for i in range(2):
        Min = np.array(PenHSV[i][:3])
        Max = np.array(PenHSV[i][3:6])
        mask = cv2.inRange(hsv,Min,Max)
        res = cv2.bitwise_and(img,img,mask=mask)
        pointX, pointY = FindContour(mask) #找到顏色後找輪廓
        cv2.circle(ContourImg,(pointX,pointY),10,PenColor[i],cv2.FILLED) #找到筆尖
        cv2.imshow('Pen' ,res)
        #確定有找到輪廓，才存路徑
        if pointY !=-1:
            DrawPoint.append([pointX, pointY,i])
#找輪廓
def FindContour(img):
    Contours, hierarchy =  cv2.findContours(img, cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_NONE)
    
    x,y,w,h=-1,-1,-1,-1 #沒偵測到時
    for cnt in Contours:
        Area = cv2.contourArea(cnt) 
        if Area>100:
            Side_Len = cv2.arcLength(cnt , True)
            Vertices = cv2.approxPolyDP(cnt, Side_Len*0.01, True)
            x,y,w,h = cv2.boundingRect(Vertices)

    return x+w//2, y #回傳筆尖位置
#畫圖
def Draw(drawpoint):
    for point in drawpoint:
        cv2.circle(ContourImg,(point[0],point[1]),5,PenColor[point[2]],cv2.FILLED)


while True:
    ret, frame = vid.read()
    frame = cv2.flip(frame,1)
    if ret:
        ContourImg = frame.copy()
        Draw(DrawPoint)
        FindPen(frame)
        cv2.imshow('Contour' , ContourImg)
    else:
        break
    if cv2.waitKey(1) == ord('q'):
        break

import cv2
import numpy as np
import Show_Img as SI

img = cv2.imread('D:\Coding\OpenCV\IMG&MP4\shape.jpg')
ContourImg = img.copy()
gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
canny = cv2.Canny(gray,100,200)

#找輪廓 (處理的圖片, 模式(內輪廓或外輪廓), 壓縮模式) -->回傳輪廓、階層
Contours, hierarchy =  cv2.findContours(canny, cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_NONE)

#畫出來 (要畫在哪, 輪廓圖, 第幾個點(全部就-1), 顏色, 粗細)
for cnt in Contours:
    cv2.drawContours(ContourImg, cnt, -1, (255,0,0), 4)

#寫字函數
def ShowText(name):
    cv2.putText(ContourImg, name, (x+5,y), cv2.FONT_HERSHEY_COMPLEX, 1 ,(0,0,255),2)


#輪廓資訊
for cnt in Contours:
    Area = cv2.contourArea(cnt) #取得面積
    if Area>500: #過濾
        Side_Len = cv2.arcLength(cnt , True) #取得邊長(第二參數是是否為閉合圖形)
        Vertices = cv2.approxPolyDP(cnt, Side_Len*0.01, True) #輪廓逼近函數(逼近精度參數,是否閉合))
        corners = len(Vertices) #頂點數

        #把每個圖框起來
        x,y,w,h = cv2.boundingRect(Vertices)
        cv2.rectangle(ContourImg,(x,y),(x+w,y+h),(0,255,0),1)

        #顯示字
        if corners == 3:
            ShowText('Triangle')
        elif corners == 4:
            ShowText('Rectangle')
        elif corners == 5:
            ShowText('Pentagon')
        else:
            ShowText('Circle')

SI.ShowImg('Img',ContourImg,0)

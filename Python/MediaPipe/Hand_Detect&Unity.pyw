import cv2
from cvzone.HandTrackingModule import HandDetector
import mediapipe as mp
import socket

#設定視窗大小
width = 1280
height = 720
cap = cv2.VideoCapture(0)
cap.set(3, width) #3是寬度索引
cap.set(4, height) #3是高度索引

#偵測設定
detector = HandDetector(maxHands=1, detectionCon=0.7)

#傳輸設定
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
serverAddress = ('127.0.0.1', 5502)

#畫面
while True:
    success,img = cap.read()
    img = cv2.flip(img, 1) #鏡像翻轉
    Hands, img=detector.findHands(img) #手部資訊、標記圖片
    data = []

    if success:
        #座標獲取
        if Hands:
            firstHand = Hands[0] #第一隻手
            lmList = firstHand['lmList']
            for lm in lmList:
                data.extend([lm[0],height - lm[1],lm[2]])
            # print(data)
            sock.sendto(str.encode(str(data)), serverAddress) #傳輸檔案
        #顯示
        img = cv2.resize(img, (0, 0),None, 0.5, 0.5)
        cv2.imshow('Camera', img)
        if cv2.waitKey(1) == ord('q'):
            break


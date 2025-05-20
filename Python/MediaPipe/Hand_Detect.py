import cv2
import mediapipe as mp
import time
#手部偵測模組裡的方法
cap = cv2.VideoCapture(0) #鏡頭
mphands = mp.solutions.hands #手部偵測模組
hands = mphands.Hands( static_image_mode = True ,max_num_hands = 2, model_complexity = 1 ,min_detection_confidence=0.5, min_tracking_confidence=0)
mpDraw = mp.solutions.drawing_utils #畫出點
handsPointStyle = mpDraw.DrawingSpec(color=(0, 0, 255), thickness=8)
handsLineStyle = mpDraw.DrawingSpec(color=(0, 255, 0), thickness=12)
ctime = 0
ptime = 0


while True:
    ret, img = cap.read()
    if ret:
        RGBimg = cv2.cvtColor(img, cv2.COLOR_BGR2RGB) #模型偵測RGB圖，
        results = hands.process(RGBimg) #偵測函式
        #print(results.multi_hand_landmarks)

        #如果有偵測到手，把點畫出來
        imgHeight = img.shape[0]
        imgWidth = img.shape[1]

        if results.multi_hand_landmarks:
            for handAmount in results.multi_hand_landmarks:
                mpDraw.draw_landmarks(img,handAmount,mphands.HAND_CONNECTIONS, handsPointStyle, handsLineStyle)
                for i,pos in enumerate(handAmount.landmark): #i是偵測到的手，pos是每個點的座標
                    #轉換座標
                    pos_x = int(pos.x * imgWidth)
                    pos_y = int(pos.y * imgHeight)
                    # cv2.putText(img, str(i), (pos_x-25, pos_y+5), cv2.FONT_HERSHEY_COMPLEX, 0.4, (0, 0, 255),1) #標記數字    
                    if i == 4:
                        cv2.circle(img, (pos_x, pos_y), 10, (113, 25, 60), cv2.FILLED)        
                    print(i,pos_x,pos_y)


        ctime = time.time()
        fps = 1/(ctime - ptime)
        ptime = ctime
        cv2.putText(img, f'FPS = {int(fps)}', (10, 30), cv2.FONT_HERSHEY_COMPLEX, 0.4, (255, 0, 0),1)

        cv2.imshow('Cam', img)




    if cv2.waitKey(1) == ord('q'):
        break


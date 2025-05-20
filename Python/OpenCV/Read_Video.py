import cv2


vid = cv2.VideoCapture('D:\Coding\OpenCV\IMG&MP4\Cat.mp4') #影片連結
vid = cv2.VideoCapture(0) #視訊鏡頭

#用迴圈把影片一幀一幀印出來
while True:
    ret, frame = vid.read() #回傳兩個值：ret是否取得成功，frame影片第一幀
    frame = cv2.resize(frame,(0,0),fx=0.4,fy=0.4) #修改影片大小
    if ret:
        cv2.imshow('video' , frame)
    else:
        break
    if cv2.waitKey(1) == ord('q'): #當按下q停止播放
        break


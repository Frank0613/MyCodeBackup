import cv2
import Show_Img as si

img = cv2.imread('D:\Coding\Python\OpenCV\IMG&MP4\Oriange.jpg')
gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
FaceCascade = cv2.CascadeClassifier('D:\Coding\OpenCV\Model\CatFace_Detect.xml')

#原理：會有一個格子一格一格掃描圖片，並偵測有臉的地方，
# 一輪完之後縮小圖片然後再做一次，次數是指掃描到幾次會偵測為臉
FaceRec = FaceCascade.detectMultiScale(gray, 1.1, 3) #(圖片, 縮小比例, 次數)
for x,y,w,h in FaceRec:
    cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),2)
    cv2.putText(img, 'Cat', (x+50,y), cv2.FONT_HERSHEY_COMPLEX, 3 ,(0,0,255),2)

si.ShowImg('cat', img, 0)
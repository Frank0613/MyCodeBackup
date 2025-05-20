import cv2

img = cv2.imread('D:\Coding\OpenCV\IMG&MP4\Cat.jpg') #讀取路徑
#改變圖片大小
img = cv2.resize(img,(300,300)) #改變像素
img = cv2.resize(img,(0,0),fx=2,fy=2) #縮放比例

cv2.imshow('Img', img ) #顯示(視窗標題, 圖片)
cv2.waitKey(0)       #等待時間(當時間內按下任何鍵，回傳鍵值並停止程式) --> 0是無限久



import cv2

def ShowImg(nameStr, Img, times):
    cv2.imshow(nameStr, Img ) 
    cv2.waitKey(times)       
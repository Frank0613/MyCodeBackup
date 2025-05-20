import cv2
import numpy as np

#畫布
Canvas = np.zeros((500,500,3),np.uint8)
#線(畫布,起始點,終點,顏色,粗細)
cv2.line(Canvas, (0,0),(Canvas.shape[1],Canvas.shape[0]),(0,200,0),2)
#方形(畫布,起始點,對角點,顏色,粗細)
cv2.rectangle(Canvas, (0,0),(250,250),(150,0,0),2)
#圓形(畫布,圓心,半徑,顏色,粗細)
cv2.circle(Canvas, (250,250), 30 ,(0,0,150),cv2.FILLED)
#文字(畫布, 文字, 位置, 字型, 大小, 顏色, 粗度)
cv2.putText(Canvas,'Dick', (300,400), cv2.FONT_HERSHEY_COMPLEX_SMALL, 3 ,(255,255,255),1)

cv2.imshow('Canvas',Canvas)
cv2.waitKey(0)
li=[4,945,6,17,59,101]
num=len(li)
for i in range(len(li)):
  maxVal=max(li[0:num])
  tmp=li[-(i+1)]
  li[-(i+1)]=maxVal
  li[li.index(maxVal)]=tmp
  num-=1
print(li)
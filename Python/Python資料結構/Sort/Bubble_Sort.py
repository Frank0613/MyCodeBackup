li=[4,7,1,5,60,3]
#寫法1
for j in range(len(li)-1):
   for i in range(len(li)-1):
     if(li[i]>li[i+1]):
       li[i],li[i+1]=li[i+1],li[i]
print(li)

#寫法2
sort=False
while not sort:
    sort=True
    for i in range(len(li)-1):
        if li[i] > li[i+1]:
            li[i],li[i+1]=li[i+1],li[i]
            sort=False
print(li)
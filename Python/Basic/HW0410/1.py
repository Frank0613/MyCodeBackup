#data後移
num='12345'
size=len(num)
for i in range(size):
    print(num[size-i:],num[0:size-i],sep="")
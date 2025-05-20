
file='456.txt'
data=['a\n','b\n','c\n'] #加換行才會一個一行
with open(file,'w') as f:
    f.writelines(data) #第一種
#讀取
count=0
re=open(file,'r')
for i in re:
    count+=1
    print(f"{count}：{i}")
re.close()
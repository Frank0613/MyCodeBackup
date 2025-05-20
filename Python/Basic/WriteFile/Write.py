file='123.txt' #如果檔案不存在就新增檔案
f=open(file,'w') #w是可寫入
f.write('寫入123') #寫入
f.write('45678')
f.close() #關閉

#簡寫、寫入陣列
file='123.txt'
data=['apple\n','banana\n','guava\n'] #加換行才會一個一行
with open(file,'w') as f:
    f.writelines(data) #第一種
    for i in data: #第二種
        f.write(i)

    

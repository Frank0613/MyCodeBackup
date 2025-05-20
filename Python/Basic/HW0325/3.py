#請將下列字串(msg)中的中文，與其他英數字分開。
msg = "早安的英文是Good morning, milk則是牛奶"
print('chinese：',end='')
for i in msg:
    if(ord(i)<31 or ord(i)>123):       
        print(i,end="")
print('\nother：',end='')
for i in msg:
    if(ord(i)>31 and ord(i)<123 ):       
        print(i,end="")

#print(ord("a"),ord("z"),ord("A"),ord("Z"),ord(" "),ord(","))
#print(f"chinese:{i}",end="")
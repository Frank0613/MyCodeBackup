#印出 ASCII code 32 ~ 127 所對應的所有字元，且每列最多顯示 10 個。
count=0
for i in range(30,128):
    count+=1
    if(i<32):
        print(" "*7,end="")
    else:
        print(f"{i}:'{chr(i)}' ",end="")
        if(count%10==0):
            print('\n')

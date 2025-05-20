phones = "0930654321, 0924-135-246, 0922  132456, 0938 258-369"
ph1=phones.replace(' ','')#刪掉空白
ph2=ph1.replace('-','')#刪掉"-"
phonelist=ph2.split(",")
for i in range(len(phonelist)):
    print(f'{phonelist[i][:4]}-{phonelist[i][5:]}')


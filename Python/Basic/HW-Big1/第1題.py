#攝氏與華氏溫度的轉換
sum=0
print('攝氏華氏轉換：','1) 攝氏轉華氏(C -> F)','2) 華氏轉攝氏(F -> C)',sep='\n')
choose=input('你的選擇：')
print('------------------------')
if choose=='1':
    c=float(input('請輸入攝氏溫度：'))
    sum=(9/5)*c+32
    print(f'=>華氏{sum}度')
elif choose=='2':
    f=float(input('請輸入華氏溫度：'))
    sum=(f-32)/(9/5)
    print(f'=>攝氏{sum}度')
else:
    print('無效的數字')


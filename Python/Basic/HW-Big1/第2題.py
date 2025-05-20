#BMI轉換器
height=float(input('請輸入身高(cm)：'))/100
Weight=float(input('請輸入體重(kg)：'))
bmi=Weight/(height**2)
print(f"您的BMI是：{round(bmi,1)}")

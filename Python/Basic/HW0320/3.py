#請寫 Python 程式計算一元二次方程式(quadratic equation)的解。
#請輸入下列係數，
#a = 1, b = 4, c = 13，
#並印出如下形式的複數解(至多到小數第一位)，
#x1 = -2.0 - 3.0j
#x2 = -2.0 + 3.0j
import cmath
a=1
b=4
c=13
x1=(-b-cmath.sqrt(b**2-4*a*c))/(2*a)
x2=(-b+cmath.sqrt(b**2-4*a*c))/(2*a)
#print(int(x1.real),int(x1.imag),"j\n",int(x2.real),'+',int(x2.imag),"j\n")
print(f"{int(x1.real)}{int(x1.imag)}j\n{int(x2.real)}+{int(x2.imag)}j")
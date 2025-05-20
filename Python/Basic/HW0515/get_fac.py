#Input=input('輸入階乘：')
#num=int(Input)
def get_fac(n):
    if(n==1):
        return n
    return n*get_fac(n-1)

for a in range(1,26):
    if a < 10:
        print(f" {a}的階乘為：{get_fac(a)}")
    else:
        print(f"{a}的階乘為：{get_fac(a)}")

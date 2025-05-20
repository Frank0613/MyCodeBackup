factxt='fac.txt'
fac=open(factxt,'w')

def get_fac(n):
    if(n==1):
        return n
    return n*get_fac(n-1)

for a in range(1,26):
    if a < 10:
        fac.write(f" {a}的階乘為：{get_fac(a)}\n")
    else:
        fac.write(f"{a}的階乘為：{get_fac(a)}\n")
fac.close()
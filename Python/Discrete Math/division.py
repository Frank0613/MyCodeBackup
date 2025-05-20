#11(a)/3(b) = 3(q)...2(r)

def Division_Algo(a,b):
    q=0
    r=abs(a)
    while r>=b:
        r=r-b #直到餘數<=除數
        q+=1
    if a<0 and r>0:
        r = b-a
        q=-(q+1)
    return(q,r)
print(Division_Algo(11,3))
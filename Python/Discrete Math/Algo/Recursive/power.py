def Power(a,n):
    if(n==0):
        return 1
    else:
        return a*Power(a,n-1)

print(Power(2,2))


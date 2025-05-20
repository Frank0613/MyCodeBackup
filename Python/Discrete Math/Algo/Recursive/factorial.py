def Factorial(a):
    if(a==0):
        return 1
    else:
        return a*Factorial(a-1)

print(Factorial(8))
    
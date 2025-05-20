import math
def gcd(a,b):
    if(a>b):
        return "Invalid a,b"
    else:
        if a==0:
            return b
        else:
            return gcd(b % a, a)
print(gcd(3,10))

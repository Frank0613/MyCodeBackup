import math
#以10為底，從 1 ~ 10 的對數表
for i in range(1,11):
    print("log(",i,")=",f"{math.log10(i):0.4f}")
    i=i+1
print('\n')
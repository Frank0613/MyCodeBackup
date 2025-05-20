import math
j=0
for i in range(1,21):
    if i <=9:
        print(' ',end='')
    print(f'{i}!=',end='')
    print(" " * (19-(len(str(math.factorial(i))))), end='')
    print(f"{math.factorial(i)}",end='\n')
    j+=1


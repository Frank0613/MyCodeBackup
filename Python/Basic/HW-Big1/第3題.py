#隨機生成、統計
import random
from collections import Counter
li=[0]*25
result=[]
for i in range(len(li)):
    li[i]=random.randint(1, 9)
result=Counter(li)
print("list =",li)
for i in range(1,10):
    if result[i]==0:
        continue
    else:
        print(f"{i} -> {result[i]}",end=', ')
    



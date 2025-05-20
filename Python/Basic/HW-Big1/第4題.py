#姓氏有幾個、幾種姓氏
from collections import Counter
namestr = "葉聿欣, 李清蓁, 王品宸, 吳佩谷, 蔡睿典, 謝佳迪, 洪至儀, 孫俊毅, " \
          + "歐陽彥美, 陳明易, 張祐怡, 張家豪, 蔡宜星, 高彥廷, 王子辰, 宋苡凱, " \
          + "郭阿民, 陳欣潔, 許嘉書, 李明映, 黃冠一, 邱雅惠, 陳姿琬, 張秀美, " \
          + "蕭佳玲, 藍月純, 張慧萍, 涂宏延, 陳俊瑋, 楊萬延, 呂怡慧, 陳昀寶, " \
          + "蔡新信, 陳欣怡, 吳靜怡, 劉子欣, 林耿順, 徐嘉岑, 黃皓, 方如成, " \
          + "張國美, 程登達, 陳俊琳, 楊萱州, 吳山邦, 林宛亦, 楊瓊文, 蔡雅玲, " \
          + "林恭軒, 張俊定"
namelist=namestr.split(', ')
namelist.sort()
firstname=[]
list1=[]
list2=[]
for name in namelist:
    firstname.append(name[0])
result=dict(Counter(firstname))
for a in result.keys():
    list1.append(a)
for b in result.values():
    list2.append(b)
print(f'共有{len(list1)}種姓氏\n-------------------')
for i in range(len(list1)):
    print(f'{list1[i]}{list2[i]}個')


    

    















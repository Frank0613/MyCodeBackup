#請使用 Names-50.txt 中的人名，並為每個人生成三個科目的成績，分數的範圍在 0~99，列出所有人名與成績，並為其附加上三科的總分。
import random
namelist=['葉聿欣', '李清蓁', '王品宸', '吳佩谷', '蔡睿典', '謝佳迪', '洪至儀', '孫俊毅', '張俊定', '歐陽彥美', '陳明易', '張祐怡', '張家豪', '蔡宜星', '高彥廷', '王子辰', '宋苡凱', '郭阿民', '陳欣潔', '許嘉書', 
      '李明映', '黃冠一', '邱雅惠', '陳姿琬', '張秀美', '蕭佳玲', '藍月純', '張慧萍', '涂宏延', '陳俊瑋', '楊萬延', '呂怡慧', '陳昀寶', '蔡新信', '陳欣怡','吳靜怡', '劉子欣', '林耿順', '徐嘉岑', '黃皓', '方如成', 
      '張國美', '程登達', '陳俊琳', '楊萱州', '吳山邦', '林宛亦', '楊瓊文', '蔡雅玲', '郭道申']
#------------------------------------------------------------
print('[',end='')
for i in namelist:
    
    score1=random.randint(0,100)
    score2=random.randint(0,100)
    score3=random.randint(0,100)
    sum=score1+score2+score3
    print(f"['{i}', {score1}, {score2}, {score3}, {sum}]",end=',\n')
print(']',end='\n')
#------------------------------------------------------------第一種
all=[]
for i in range(len(namelist)):
    score=[]
    score.insert(0,namelist[i])
    score.insert(1,random.randint(0,100))
    score.insert(2,random.randint(0,100))
    score.insert(3,random.randint(0,100))
    sum=score[1]+score[2]+score[3]
    score.insert(4,sum)
    all.append(score)
print(all)





















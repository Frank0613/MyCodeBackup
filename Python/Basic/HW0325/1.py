#姓名隱私化
namelist=['葉聿欣', '李清蓁', '王品宸', '吳佩谷', '蔡睿典', '謝佳迪', '洪至儀', '孫俊毅', '張俊定', '歐陽彥美', '陳明易', '張祐怡', '張家豪', '蔡宜星', '高彥廷', '王子辰', '宋苡凱', '郭阿民', '陳欣潔', '許嘉書', 
      '李明映', '黃冠一', '邱雅惠', '陳姿琬', '張秀美', '蕭佳玲', '藍月純', '張慧萍', '涂宏延', '陳俊瑋', '楊萬延', '呂怡慧', '陳昀寶', '蔡新信', '陳欣怡','吳靜怡', '劉子欣', '林耿順', '徐嘉岑', '黃皓', '方如成', 
      '張國美', '程登達', '陳俊琳', '楊萱州', '吳山邦', '林宛亦', '楊瓊文', '蔡雅玲', '林恭軒']
count=0
def name_privacy(name):
    if len(name)==2:
        return name[0]+"O"
    else:
        return name[0]+"O" * (len(name)-2) + name[-1]
  
for i in namelist:
    count+=1
    print(name_privacy(i),end=', ')
    if(count%10==0):
        print(end="\n")

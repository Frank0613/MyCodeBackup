def markline(length=15, mark='-'):
    print('\n', mark*length, sep='')
def csv_split(msg):
    msgLen = len(msg)
    items = []
    beg = 0
    index = 0
    while(index < msgLen):
        if msg[index] == ',':
            items.append(msg[beg:index])
            beg = index + 1
        elif msg[index] == '"':
            beg = index + 1
            while(True):
                index += 1
                if (msg[index] == '"'):
                    items.append(msg[beg:index])
                    beg = index + 2
                    index += 1
                    break
        index += 1
        
    if beg < msgLen:  # index已過了字串結尾！
        items.append(msg[beg:])
    elif beg >= msgLen and msg[-1]!='"':  # 結束是: ',' or '"'。 
        items.append(msg[beg:])
    #print(items)
    return items
#----------------------------------------------------------------   
fname = ['108_student.csv','109_student.csv','110_student.csv','111_student.csv']
field = [2,3,4,5,8,9]  # 指定欄位的索引值。
field108=[2,3,4,8,9,10,11,12,13,14,15]
grade=['一年級','二年級','三年級','四年級']
years=108
for file in fname:
    print(f'民國{years}年：',end='')
    with open(file, "r", encoding='utf-8') as fp:
        strdata = fp.read()
        lines = strdata.strip().split('\n')
        index = 0  # for printing first line
        for line in lines:
            items = csv_split(line)
            
            if index==0 or items[1] == '國立臺北科技大學':
                index += 1
                if years==108:
                    for f in field108:
                        print(items[f-1], end=",")
                    
                else:
                    for f in field:
                        print(items[f-1], end=",")
                markline()
    
    years+=1
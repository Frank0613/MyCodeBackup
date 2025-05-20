import csv
result='result.html'
res=open(result,'w') #w是可寫入
dict_stu={}
with open('111_student.csv', newline='', encoding='utf-8') as csvfile:
    file = csv.reader(csvfile)
    data = list(file)
    
    for i in range(len(data)):
        if i ==0:
            continue
        else:
            student=int(data[i][4].replace(',',''))
            if data[i][1] in dict_stu:
                dict_stu[data[i][1]]+=student
            else:
                dict_stu[data[i][1]]=student
            

    res.write(f'<table border=1><tr><th>學校名稱</th><th>學生人數</th></tr>')        
    for district, count in dict_stu.items():
        res.write(f'<tr><th>{district}</th><th>{count}</th></tr>') #寫入學校名稱
    res.write('</table>')       
    res.close()    






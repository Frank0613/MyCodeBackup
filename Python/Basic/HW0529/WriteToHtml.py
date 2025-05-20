import csv
result='web.html'
res=open(result,'w') #w是可寫入

with open('u1_new.csv', newline='', encoding='utf-8') as csvfile:
    file = csv.reader(csvfile)
    data = list(file)
    
    for i in range(len(data)):
        if i ==0:
            continue
        else:
            res.write(f'<a href="{data[i][6]}" target=_blank>{data[i][1]}</a><br>{data[i][4][5:]}-{data[i][5]}。<br>'+'\n') #寫入學校名稱
            #print(f'<a href="{data[i][6]}" target=_blank>{data[i][1]}</a>')
    res.close()    






import csv
filename='D:\Coding\Python\Python基礎\FinalExam\see.html'
file=open(filename,'w') #w是可寫入

with open('u1_new.csv', newline='', encoding='utf-8') as csvfile:
    files = csv.reader(csvfile)
    data = list(files)
    
    file.write(f'<h2>互動二-110AC1011-顏維廷</h2>\n<h2>高雄市</h2>\n')
    for i in range(len(data)):
        if data[i][3][4:7]=='高雄市':
            file.write(f'<a href="{data[i][6]}" target=_blank>{data[i][1]}</a><br>{data[i][4][5:]}-{data[i][5]}。<br>'+'\n')
        
    file.close()    

import csv

with open('StudentScore.csv',newline='',encoding='Big5') as csvfile:
    file=csv.reader(csvfile)
    data=list(file)
    #str
    for element in data:
        print(element)  
    print(f'=> 分數部分資料型態為：{type(element[2])}')
    #int
    for element in data:
        element[2:] = [int(score) for score in element[2:]] #score裡的element經過int(score)後返回
        print(element)
    print(f'=> 分數部分資料型態為：{type(element[2])}')
            
        


import csv
sumli=[]
result=0
with open('StudentScore.csv',newline='',encoding='Big5') as csvfile:
    file=csv.reader(csvfile)
    data=list(file)
    print('原始資料：')
    for element in data:
        element[2:] = [int(score) for score in element[2:]] #score裡的element經過int(score)後返回
        print(element)   

    print('填入總分的結果：')
    for element in data:
        element[2:] = [int(score) for score in element[2:]] #score裡的element經過int(score)後返回
        sumli=element[2:]
        element.insert(2,sum(sumli)) 
        print(element)  
    
            
        


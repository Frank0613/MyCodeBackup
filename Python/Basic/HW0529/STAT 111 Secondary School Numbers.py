import csv

dict_count = {}

with open('111_basej.csv', newline='\n', encoding='utf-8') as csvfile:
    file = csv.reader(csvfile)
    data = list(file)

    for i in range(len(data)):
        if data[i][1] == '臺北市':
            dict_tpi = data[i][2] #用變數dict_tpi存每個區
            if dict_tpi in dict_count:
                dict_count[dict_tpi] += 1 #假設字典裡已經有相同的key，就把他的Value值+1
            else:
                dict_count[dict_tpi] = 1 #假設字典裡沒有，就新增這個key然後Value值=1

for district, count in dict_count.items(): #dict_count.items()會return每組(key,value)，然後用district, count分別存
    print(f"臺北市{district}有{count} 間國中")
    

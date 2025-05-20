name = "台北科大資工系王大同"
length = len(name)
for i in range(length-1,-1,-1):
    print(name[:i],end='')
    print(name[i]*(length-i),end='')
    print(end='\n')


import random
namestr = '黃育恒-曾佳穎-王雅婷-沈嘉鳳-孫家華-甄佳穎-徐盈君-李政祥-陳心怡-阮宏喜'
namelst=namestr.split("-")

for i in range(len(namelst)):
    score1=random.randint(0,100)
    score2=random.randint(0,100)
    score3=random.randint(0,100)
    sum=score1+score2+score3
    if i >=9:
        print(f"['你的班級-0{i+1}', '{namelst[i]}', {sum}, {score1}, {score2}, {score3}]")
    else:
        print(f"['你的班級-00{i+1}', '{namelst[i]}', {sum}, {score1}, {score2}, {score3}]")

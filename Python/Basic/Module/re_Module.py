import re
str = 'cat, cbt, cct, cdt, c0t, c2t, cyzt'

print('\n搜尋\n==============================================')
#搜尋
items = re.search('cat',str)
print(items) #<re.Match object; span=(0, 3), match='cat'> ----> <表示正規表示式, 在字串的0~3位置(不包括3的字串), 實際匹配到的>
print('span():', items.span()) # (0, 3)
print('string:', items.string) # cat, cbt, cct, cdt, c0t, c2t, cyzt
print('group():', items.group()) # group(): cat

print('\n找到所有\n==============================================')
#找到所有
print(re.findall("c[ab]t", str)) #['cat', 'cbt']
print(re.findall("cat|cbt", str)) #['cat', 'cbt']
print(re.findall("c[abcd]t", str)) #['cat', 'cbt', 'cct', 'cdt']
print(re.findall("c[a-d]t", str)) #['cat', 'cbt', 'cct', 'cdt']

print('\n取代\n==============================================')
#取代
print(re.sub("c[ab]t", "貓", str)) #貓, 貓, cct, cdt, c0t, c2t, cyzt
print(re.sub("c[a-z]t", "貓", str)) #貓, 貓, 貓, 貓, c0t, c2t, cyzt
print(re.sub("c[0-9]t", "貓", str)) #cat, cbt, cct, cdt, 貓, 貓, cyzt
print(re.sub("c\dt", "貓", str)) #同上，\d代表所有數字
print(re.sub("c.t", "貓", str)) #貓, 貓, 貓, 貓, 貓, 貓, cyzt，.代表任意單個字符
print(re.sub("c.{1,2}t", "貓", str)) #貓, 貓, 貓, 貓, 貓, 貓, 貓，代表任意字符1~2個都可
print(re.sub("c.+t", "貓", str)) #貓，從第一個符合的到最後一個符合的，全部視為一個替換

print('\n拆解\n==============================================')
#拆解
msg = "a, b,   c,  d,    e"
print(re.split(",", msg)) #['a', ' b', '   c', '  d', '    e']，逗點拆分
print(re.split(",\s", msg)) #['a', 'b', '  c', ' d', '   e']，逗點和一個空白拆分
print(re.split(",\s+", msg)) #['a', 'b', 'c', 'd', 'e']，逗點和多個空白拆分

print('\n電話號碼拆解\n==============================================')
#電話號碼拆解
msg = "0930 919231, 0930919321, 0930 654-321, 0930-234561, 0930 135 246, 0930-246-351"
items=re.sub("\s+|-",'',msg)
splitItems= re.findall("([0-9]{4})([0-9]{6})", items)

for i in splitItems:
    print(f'{i[0]}-{i[1]}')


msg = '''
<table border=1>
    <tr> <th>1</th> <th>2</th> <th>3</th> </tr>
    <tr> <th>4</th> <th>5</th> <th>6</th> </tr>
</table>
'''
result = re.sub("<th>", "", msg)
result = re.sub("<.+>", "", msg)
result = re.sub("<.+?>", "", msg)
print(result)
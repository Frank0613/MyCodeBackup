import re

phones = "0227712171, (02)86621234, 02 2771-7321, (02)  2771-1357, 02-8662-2468"
items=re.sub(r"\(|\)|-|\s+",'',phones)

splitItems= re.findall("([0-9]{2})([0-9]{4})([0-9]{4})", items)

for i in splitItems:
    print(f'({i[0]}) {i[1]}-{i[2]}')

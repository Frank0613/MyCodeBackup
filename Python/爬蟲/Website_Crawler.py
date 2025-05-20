import requests
from bs4 import BeautifulSoup
num=1
response=requests.get('https://travel.ettoday.net/category/%E5%8F%B0%E5%8C%97/?from=travel_MainMenu_PC')
soup=BeautifulSoup(response.text,'html.parser') #html.parser是Python內建的HTML解析器，可用於解析HTML文檔。

result=soup.find_all('h3',itemprop="headline",limit=20) #回傳陣列
for i in result:
    title=i.select_one("a").get("title")
    url=i.select_one('a').get('href')
    print(f"景點{num}：{title}\n網址：{url}")
    num+=1
    print('\n')
#print(soup.prettify()) #prettify() 方法会在 HTML 或 XML 文件的各个节点处增加换行符、缩进等字符，以使输出结果具有良好的可读性。
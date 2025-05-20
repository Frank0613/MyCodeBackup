#請模擬產生樂透的號碼。
#假設樂透的規則是: 從 1~42 隨機選出六個不重複的數字。
import random
lotto=[x for x in range(1,43)]
result=random.sample(lotto,6)
result.sort(reverse=False)
print(result)
#因為直接把api寫在Code裡很危險，先用.env檔儲存，再用dotenv讀取

from dotenv import dotenv_values
data = dotenv_values('.env')
apikey = data['Api_Key']
print(apikey)
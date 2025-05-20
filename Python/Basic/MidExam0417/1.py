get=[]
for i in range(5):
    get.append(int(input(f'請輸入數字{i+1}：')))
print(f"------------\n總和是：{sum(get)}\n最大值：{max(get)}\n最小值：{min(get)}")
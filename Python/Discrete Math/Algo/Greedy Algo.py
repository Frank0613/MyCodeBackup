Copper_plate_combination = [25,10,5,1] # must be decrease list

def Greedy_Algorithm(total_money):
    remain = total_money
    i=0
    result = []
    while i < len(Copper_plate_combination):
        quantity  = 0
        quantity,remain = divmod(remain,Copper_plate_combination[i])
        result.append( f"{Copper_plate_combination[i]}分：{quantity}個")
        i+=1
    return ", ".join(result)
    
# 測試用例
print(Greedy_Algorithm(63))
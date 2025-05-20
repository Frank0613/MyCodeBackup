def PickPossibility(n, m):
    if m == 0:  # 遞迴終止條件：當 m 為 0 時，返回 1
        return 1
    count = 0
    for i in range(1, n + 1):  # 修正範圍，應包含 n 本身
        count += PickPossibility(i, m - 1)  # 遞迴計算剩餘的可能性
    return count

# 測試範例
n = 3  # 總共有 n 個元素
m = 2  # 挑選 m 個元素
result = PickPossibility(n, m)
print(f"總共有 {result} 種可能性")

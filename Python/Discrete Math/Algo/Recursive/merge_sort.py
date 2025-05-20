def MergeSort(a):
    if len(a) > 1:
        m = len(a) // 2  # 中間點
        a1 = a[:m]       # 左半部分
        a2 = a[m:]       # 右半部分

        # 遞迴排序左右兩部分
        a1 = MergeSort(a1)
        a2 = MergeSort(a2)


        # 合併兩部分
        a = []
        while len(a1) > 0 and len(a2) > 0:
            if a1[0] < a2[0]:
                a.append(a1.pop(0))
            else:
                a.append(a2.pop(0))

        # 將剩下的元素加入
        a.extend(a1)
        a.extend(a2)
    print(a)
    return a
MergeSort([8, 2, 4, 6, 9, 7, 10, 1, 5, 3])
# 呼叫範例



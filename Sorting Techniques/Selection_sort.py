def selectionSort(alist):
    for j in range(0, len(alist)):
        min = alist[j]
        for i in range(j, len(alist)):
            if alist[i]<min:
                min = alist[i]
                min_pos = i
        # swap min with value at position j
        temp = alist[j]
        alist[j] = min
        alist[min_pos] = temp


a = [29, 10, 14, 30, 37, 14, 18]
selectionSort(a)
print(a)
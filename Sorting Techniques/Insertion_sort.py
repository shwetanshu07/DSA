def insertionSort(alist):
    for i in range(1, len(alist)):
        curr_val = alist[i]
        j = i-1
        while(j>=0 and alist[j]>curr_val):
            alist[j+1] = alist[j]
            j = j-1
        alist[j+1] = curr_val

a = [2, 1, 9, 78, 4]
insertionSort(a)
print(a)
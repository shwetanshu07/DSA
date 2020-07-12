def swap(array, p, q):
    temp = array[p]
    array[p] = array[q]
    array[q] = temp

def bubbleSort(alist):
    for j in range(len(alist)):
        print("Starting of cycle", j)
        for i in range(len(alist) - 1):
            print(alist, alist[i], alist[i+1])
            if (alist[i] > alist[i + 1]):
                swap(alist, i, i + 1)
        print("End of cycle", j)


a = [29, 10, 14, 30, 37, 14, 18]
bubbleSort(a)
print(a)
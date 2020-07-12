def swap(array, p, q):
    temp = array[p]
    array[p] = array[q]
    array[q] = temp


def bubbleSort(alist):
    for j in range(len(alist)):
        no_swap = False     # using an indicator for whether a swap was made in a cycle
        for i in range(len(alist) - 1):
            print(alist, alist[i], alist[i+1])
            if (alist[i] > alist[i + 1]):
                swap(alist, i, i + 1)
                no_swap = True
        if no_swap == False:
            break


a = [29, 10, 14, 30, 37, 14, 18]
bubbleSort(a)
print(a)
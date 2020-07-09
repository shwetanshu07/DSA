def merge(alist, lefthalf, righthalf):
    i = 0   # pointer for left half
    j = 0   # pointer for right half
    k = 0   # pointer for original array
    while(i<len(lefthalf) and j<len(righthalf)):
        if lefthalf[i]<righthalf[j]:
            alist[k] = lefthalf[i]
            i = i+1
        else:
            alist[k] = righthalf[j]
            j = j+1
        k=k+1
    while(i<len(lefthalf)):
        alist[k] = lefthalf[i]
        i = i+1
        k = k+1
    while(j<len(righthalf)):
        alist[k] = righthalf[j]
        j = j+1
        k = k+1

def mergeSort(alist):
    if (len(alist)>1):
        mid = len(alist)//2
        lefthalf = alist[:mid]
        righthalf = alist[mid:]

        mergeSort(lefthalf)
        mergeSort(righthalf)
        merge(alist, lefthalf, righthalf)

a = [54,26,93,17,77,31,44,55,20]
print("Unsorted List: ",a)
mergeSort(a)
print("Sorted List: ", a)
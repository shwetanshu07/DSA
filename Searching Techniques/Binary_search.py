def binarySearch(alist, n):
    left_ptr = 0
    right_ptr = len(alist) - 1
    found_cond = False
    while left_ptr <= right_ptr:
        mid = int((left_ptr+right_ptr)/2)
        if n > alist[mid]:
            # move left pointer up
            left_ptr = mid+1
        elif n < alist[mid]:
            # move right pointer down
            right_ptr = mid-1
        else:
            print("FOUND at index", mid)
            found_cond = True
            break
    if found_cond == False:
        print("Not Found")

a = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
binarySearch(a, n)

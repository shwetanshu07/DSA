class kStacks:
  def __init__(self, cap, k):
    # cap is the capacity of the array
    # k is the number of Stacks
    self.arr = [None]*cap
    self.next = [None]*cap
    self.top = [-1]*k
    self.free_top = 0
    for i in range(0, cap-1):
      self.next[i] = i+1
    self.next[cap-1] = -1

  def display(self):
    # displays  - array, next, top, freetop
    print("Array: ", self.arr)
    print("Next:  ", self. next)
    print("Top:   ", self.top)
    print("Free Top: ", self.free_top)
  
  def push(self, x, si):
    # x ix the number to be pushed
    # si is the stack index
    print("\nPushing ",x," in stack ",si)
    i = self.free_top
    self.free_top = self.next[i]
    self.next[i] = self.top[si]
    self.top[si] = i
    self.arr[i] = x

    # displaying after Pushing
    self.display()

  def pop(self, si):
    i = self.top[si]
    self.top[si] = self.next[i]
    self.next[i] = self.free_top
    self.free_top = i

    # additional step for visualisation - not required
    self.arr[i] = None
    print("\nPop from stack ",si)
    self.display()




# main
obj = kStacks(10, 3)
obj.display()
obj.push(11, 0)
obj.push(12, 0)
obj.push(13, 0)
obj.push(21, 1)
obj.push(22, 1)
obj.pop(0)
obj.push(61, 2)
obj.push(62, 2)

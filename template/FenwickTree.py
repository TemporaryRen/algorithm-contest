class FenwickTree:
    # init with a list
    def __init__(self, nums: list[int]):
        self.arr_len = len(nums)
        self.bit_array = [0] * self.arr_len
        self.origin_array = nums
        for i,x in enumerate(nums):
            self.add(i,x)

    # init with a lenght of array
    def __init__(self, arr_len: int):
        self.arr_len = arr_len
        self.bit_array = [0] * arr_len
        self.origin_array = [0] * arr_len

    # update the value of index in the array to val
    def update(self, index: int, val: int) -> None:
        self.add(index,val - self.origin_array[index])
        self.origin_array[index] = val

    # lowbit
    def lowbit(self,n):
        return n & -n

    # calculate the sum between [left,right]
    def range_sum(self, left: int, right: int) -> int:
        def sum(k):
            i = k + 1
            s = 0
            while i > 0:
                s += self.bit_array[i-1]
                i -= self.lowbit(i)
            return s
        return sum(right) - sum(left-1)

    # add x to the value of the k-index in the array
    def add(self,k,x):
        start = k + 1
        while start <= self.arr_len:
            self.bit_array[start-1] += x
            start += self.lowbit(start)
    

    # calculate the sum between [min,k]
    def sum_from_left(self, k):
        return self.range_sum(0,k)
    
    # calculate the sum between [k,max]
    def sum_to_right(self, k):
        return self.range_sum(k,self.arr_len-1)

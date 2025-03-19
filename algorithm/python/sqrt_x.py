class Solution:
    def binarySearch(self, x: int, start: int, end: int):
        mid = ((end - start) // 2)
        if (start >= end) : return end
        if (mid * mid > x) : return self.binarySearch(x, start, mid)
        if (mid * mid == x) : return mid
        if (mid * mid < x) : return self.binarySearch(x, mid, end)
        return end
        
    def mySqrt(self, x: int) -> int:
        if x == 1: return 1
        if x == 0: return 0
        return self.binarySearch(x, 0, x)

s = Solution()
print(s.mySqrt(2147395599))
        
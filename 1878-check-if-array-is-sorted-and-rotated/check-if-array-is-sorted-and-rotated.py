class Solution:
    def check(self, nums: list[int]) -> bool:
        cnt=0
        n=len(nums)
        for i in range(n):
            if nums[i]>nums[(i+1)%n]:
                cnt=cnt+1
        return cnt<=1
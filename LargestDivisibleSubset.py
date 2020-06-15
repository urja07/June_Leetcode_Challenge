class Solution:
    def largestDivisibleSubset(self, nums):
        if len(nums) == 0: return []
        nums.sort()
        l = [[i] for i in nums]
        for i in range(len(nums)):
            for j in range(i):
                if nums[i] % nums[j] == 0 and len(l[i]) < len(l[j]) + 1:
                    l[i] = l[j] + [nums[i]]
        return max(l, key=len)

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        nums.sort()
        n = len(nums)
        res = set()
        
        for i in range(n-2):
            j = i + 1
            k = n-1
            while j < k:
                
                s = nums[i] + nums[j] + nums[k]
                if s == 0:
                    ans = [nums[i], nums[j], nums[k]]
                    if tuple(ans) not in res:
                        res.add(tuple(ans))
                    j += 1
                if s < 0:
                    j += 1
                elif s > 0:
                    k -= 1

        return list(res)
                    
        
        
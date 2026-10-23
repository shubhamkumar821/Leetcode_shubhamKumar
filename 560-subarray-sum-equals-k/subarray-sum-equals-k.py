class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        mp={}
        mp[0]=1
        cnt=0
        sum=0
        for i in nums:
            sum+=i
            cnt+=mp.get(sum-k,0)
            mp[sum]=mp.get(sum,0)+1


        return cnt    
        
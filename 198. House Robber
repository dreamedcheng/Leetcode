/*
This is a DP problem.
Let maxP[i] be the maximum money we can rob when the number of house is i.
the relation is maxP[i] = max(maxP[i-2] + nums[i], maxP[i-1])
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
            
        vector<int> maxP(n, 0);
        
        maxP[0] = nums[0];
        maxP[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) {
            maxP[i] = max(maxP[i-2] + nums[i], maxP[i-1]);
        }
        
        return maxP[n-1];
    }
};

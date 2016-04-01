class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans = INT_MAX, sum = 0;
        int pre = 0, cur = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum >= s) {
                while (sum >= s) {
                    if (i - pre + 1 < ans)
                        ans = i - pre + 1;
                    sum -= nums[pre++];
                }
            }
        }
        
        if (ans == INT_MAX)
            return 0;
        
        return ans;
    }
};

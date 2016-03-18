class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<bool> mark(n, false);
        
        for (int i = 2; i * i < n; i++) {
            if (!mark[i]) {
                for (int j = i; j *i < n; j++) {
                    mark[i*j] = true;
                }
            }
        }
        
        for (int i = 2; i < n; i++)
            if (!mark[i])
                ans += 1;
        
        return ans;
    }
};

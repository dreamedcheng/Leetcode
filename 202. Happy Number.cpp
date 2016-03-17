class Solution {
public:
    bool isHappy(int n) {
        if (n == 0)
            return false;
            
        int cur = n;
        unordered_map<int, char> hm;
        
        while (hm.find(cur) == hm.end()) {
            int sum = 0;
            hm.insert(pair<int, char>(cur, 'A'));
            while (cur != 0) {
                sum += (cur % 10) * (cur % 10);
                cur /= 10;
            }
            cur = sum;
            if (cur == 1)
                return true;
        }
        
        return false;
    }
};

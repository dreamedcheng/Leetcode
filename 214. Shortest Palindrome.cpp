class Solution {
public:

    string shortestPalindrome(string s) {
        int len = s.size();
        string new_s = "";
        string ans;
        vector<int> p(2*len + 2);
        int pos = 0;
        
        new_s += '$';
        for (int i = 0; i < len; i++) {
            new_s += '#';
            new_s += s[i];
        }
        new_s += '#';
        
        int mx = 0, id;
        for (int i = 1; i < 2*len + 2; i++) {
            if (mx > i) p[i] = min(p[2*id-i], mx-i);
            else p[i] = 1;
            for(; new_s[i+p[i]] == new_s[i-p[i]]; p[i]++)
            
            if(p[i] + i > mx) {
               mx = p[i] + i;
               id = i;
            }
            
            if (p[i] == i) pos = max(pos, i);
        }
        
        for (int i = len - 1; i >= pos - 1; i--) {
            ans.push_back(s[i]);
        }
        
        return ans + s;
        
    }
};

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        if (n != m)
            return false;
        
        if (n == 0)
            return true;
            
        unordered_map<char, char> hm;
        
        for (int i = 0; i < n; i++) {
            if (hm.find(s[i]) == hm.end()) {
                hm[s[i]] = t[i];
            }
            else if (hm[s[i]] != t[i])
                return false;
        }
        
        hm.clear();
        
        for (int i = 0; i < n; i++) {
            if (hm.find(t[i]) == hm.end()) {
                hm[t[i]] = s[i];
            }
            else if (hm[t[i]] != s[i])
                return false;
        }
        
        return true;
    }
};

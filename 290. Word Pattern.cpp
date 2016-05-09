class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int len = pattern.size();
        
        if (len == 0 && str.size() == 0) return true;
        if ((len == 0 && str.size() != 0) || (len != 0 && str.size() == 0)) return false;
        
        int pos_p = 0;
        int pos_s = 0;
        unordered_map<char, string> mp;
        
        while (pos_p < len) {
            char ch = pattern[pos_p++];
            
            string temp = "";
            
            while (pos_s < str.size() && str[pos_s] != ' ') {
                temp += str[pos_s++];
            }
            pos_s++;
            
            if (temp.size() == 0) return false;
            
            if (mp.find(ch) == mp.end()) {
                for (auto & itr : mp) {
                    if (itr.second == temp) return false;
                }
                mp.insert(pair<char, string>(ch, temp));
            }
            else {
                if (mp[ch] != temp) return false;
            }
        }
        
        if (pos_p == len && pos_s >= str.size()) return true;
        
        return false;
    }
};

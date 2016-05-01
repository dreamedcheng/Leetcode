class Solution {
public:
    string itoa(int num) {
        if (num == 0) return "0";
        
        string ret = "";
        long long n = num;
        stack<char> st;
        
        if (num < 0) {
            ret += '-';
            n = -n;
        }
        
        long long tmp = n;
        
        while (tmp != 0) {
            char ch = tmp % 10 + '0';
            st.push(ch);
            tmp /= 10;
        }
        
        while (!st.empty()) {
            ret += st.top();
            st.pop();
        }
        
        return ret;
    } 

    vector<string> summaryRanges(vector<int>& nums) {
        int pre, cur, len;
        vector<string> ans;
        
        len = nums.size();
        if (len == 0) return ans;
        else if (len == 1) {
            ans.push_back(itoa(nums[0]));
            return ans;
        }
        pre = nums[0];
        
        for (int i = 1; i < len; i++) {
            cur = nums[i];
            if (cur - nums[i-1] != 1) {
                string start = itoa(pre);
                string end = itoa(nums[i-1]);
                //cout << start << " " << end << endl; 
                if (pre != nums[i-1]) {
                    string tmp = start + "->" + end;
                    ans.push_back(tmp);
                }
                else {
                    ans.push_back(start);
                }
                pre = cur;
                if (i == len - 1) {
                    start = itoa(cur);
                    ans.push_back(start);
                }
            }
            else if (i == len - 1) {
                string start = itoa(pre);
                string end = itoa(cur);
                string tmp = start + "->" + end;
                ans.push_back(tmp);
            }
        }
        
        return ans;
    }
};

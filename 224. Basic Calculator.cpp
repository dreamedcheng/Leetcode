class Solution {
public:
    int calculate(string s) {
        stack<char> op_st;
        stack<int> num_st;
        
        s += '#';
        int len = s.size();
        
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') continue;
            
            int sum = 0, flag = 0;
            while (s[i] <= '9' && s[i] >= '0') {
                sum *= 10;
                sum += (s[i] - '0');
                flag = 1;
                i++;
            }
            
            if (flag) {
                i--;
                num_st.push(sum);
            }
            else {
                //cout << s[i] << endl;
                if (op_st.size() == 0 || s[i] == '(')
                    op_st.push(s[i]);
                else {
                    while (!op_st.empty() && op_st.top() != '(') {
                        int num1 = num_st.top();
                        num_st.pop();
                        int num2 = num_st.top();
                        num_st.pop();
                        if (op_st.top() == '+') {
                            num_st.push(num2+num1);
                        }
                        else {
                            num_st.push(num2-num1);
                        }
                        op_st.pop();
                    }
                    if (s[i] == ')') op_st.pop();
                    else op_st.push(s[i]);
                }
            }
        }
        
        return num_st.top();
    }
};

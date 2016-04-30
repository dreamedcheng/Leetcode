class Solution {
public:
    int calculate(string s) {
        s += "#";
        int len = s.size();
        stack<int> num_st;
        stack<char> op_st;
        unordered_map<char, int> priority;
        
        priority['+'] = 1;
        priority['-'] = 1;
        priority['*'] = 2;
        priority['/'] = 2;
        priority[')'] = 0;
        priority['('] = -1;
        priority['#'] = -2;
        
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') continue;
            //cout << "size: " << num_st.size() << endl;
            int sum = 0, flag = 0;
            while (s[i] <= '9' && s[i] >= '0') {
                sum *= 10;
                sum += (s[i] - '0');
                flag = 1;
                i++;
            }
            
            if (flag) {
                num_st.push(sum);
                i--;
            }
            else {
                //cout << s[i] << endl;
                if (op_st.empty() || s[i] == '(' || (priority[s[i]] > priority[op_st.top()])) {
                    op_st.push(s[i]);
                }
                else {
                    while (!op_st.empty() && priority[op_st.top()] >= priority[s[i]]) {
                        int num1 = num_st.top();
                        num_st.pop();
                        int num2 = num_st.top();
                        num_st.pop();
                            
                        if (op_st.top() == '+') {
                            num_st.push(num2 + num1);
                        }
                        else if (op_st.top() == '-') { 
                            num_st.push(num2 - num1);
                        }
                        else if (op_st.top() == '*') {
                            num_st.push(num2 * num1);
                        }
                        else if (op_st.top() == '/') {
                            num_st.push(num2 / num1);
                        }
                        op_st.pop();
                    }
                    if (s[i] == ')')
                        op_st.pop();
                    else
                        op_st.push(s[i]);
                }
            }
        }
        
        
        return num_st.top();
    }
};

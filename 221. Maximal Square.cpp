class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        int ans = 0;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '0') continue;
                int k = 0;
                while (i + k < row && j + k < col && matrix[i+k][j+k] == '1') {
                    k++;
                }
                int min = k;
                
                for (int l = i; l < i+min; l++) {
                    for (int t = j; t < j+min; t++) {
                        if (matrix[l][t] == '0') {
                            if (max(l-i, t-j) < min) min = max(l-i, t-j);
                        }
                    }
                }
                
                
                if (min*min > ans)
                    ans = min * min;
            }
        }
        
        return ans;
    }
};

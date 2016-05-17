class NumMatrix {
public:
    int ** record;

    NumMatrix(vector<vector<int>> &matrix) {
        int row = matrix.size();
        int col = 0;
        if (row != 0) col = matrix[0].size();
        
        record = new int*[row];
        
        for (int i = 0; i < row; i++) {
            record[i] = new int[col];
            for (int j = 0; j < col; j++) {
                if (j == 0) record[i][j] = matrix[i][j];
                else record[i][j] = record[i][j-1] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ret = 0;
        
        for (int i = row1; i <= row2; i++) {
            if (col1 == 0) ret += record[i][col2];
            else ret += record[i][col2] - record[i][col1-1];
        }
        
        return ret;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

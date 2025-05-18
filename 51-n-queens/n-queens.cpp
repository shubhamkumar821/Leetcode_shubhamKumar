class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> queens(n, string(n, '.')); 
        rec(0, queens, n, ans);
        return ans; 
    }

    void rec(int level, vector<string>& queens, int n, vector<vector<string>>& ans) {
        if (level == n) {
            ans.push_back(queens);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (check(level, col, queens, n)) {
                queens[level][col] = 'Q';
                rec(level + 1, queens, n, ans);
                queens[level][col] = '.';
            }
        }
    }

    bool check(int row, int col, vector<string>& queens, int n) {
        
        for (int r = 0; r < row; r++) {
            if (queens[r][col] == 'Q') {
                return false;
            }
        }
        
    
        for (int r = row, c = col; r >= 0 && c >= 0; r--, c--) {
            if (queens[r][c] == 'Q') {
                return false;
            }
        }
        
    
        for (int r = row, c = col; r >= 0 && c < n; r--, c++) {
            if (queens[r][c] == 'Q') {
                return false;
            }
        }
        
        return true;
    }
};
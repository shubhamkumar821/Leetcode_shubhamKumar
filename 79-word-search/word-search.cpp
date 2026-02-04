class Solution {
public:
    string t;
    int m, n;
    vector<vector<char>> board;

    bool exist(vector<vector<char>>& Board, string word) {
        board = Board;
        t = word;
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rec(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool rec(int i, int j, int k) {
        // ✅ base case
        if (k == t.size()) {
            return true;
        }

        // ✅ boundary + mismatch check FIRST
        if (!check(i, j, k)) {
            return false;
        }

        // ✅ mark visited AFTER checking
        char temp = board[i][j];
        board[i][j] = '#';

        // ✅ use recursion results
        bool found =
            rec(i + 1, j, k + 1) ||
            rec(i - 1, j, k + 1) ||
            rec(i, j + 1, k + 1) ||
            rec(i, j - 1, k + 1);

        // ✅ backtrack
        board[i][j] = temp;

        return found;
    }

    bool check(int x, int y, int k) {
        return !(x < 0 || y < 0 || x >= m || y >= n || board[x][y] != t[k]);
    }
};

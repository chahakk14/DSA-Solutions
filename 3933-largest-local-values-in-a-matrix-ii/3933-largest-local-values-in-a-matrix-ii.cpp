class Solution {
public:

    int countLocalMaximums(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<pair<int,int>> pos[201];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pos[matrix[i][j]].push_back({i, j});
            }
        }

        int ans = 0;

        for (int r = 0; r < n; r++) {

            for (int c = 0; c < m; c++) {

                int x = matrix[r][c];

                if (x == 0)
                    continue;

                int r1 = max(0, r - x);
                int r2 = min(n - 1, r + x);

                int c1 = max(0, c - x);
                int c2 = min(m - 1, c + x);

                bool ok = true;

                // check only larger values
                for (int val = x + 1; val <= 200 && ok; val++) {

                    for (auto &[i, j] : pos[val]) {

                        if (i < r1 || i > r2 ||
                            j < c1 || j > c2)
                            continue;

                        int dr = abs(i - r);
                        int dc = abs(j - c);

                        // ignored corners
                        if (dr == x && dc == x)
                            continue;

                        ok = false;
                        break;
                    }
                }

                ans += ok;
            }
        }

        return ans;
    }
};
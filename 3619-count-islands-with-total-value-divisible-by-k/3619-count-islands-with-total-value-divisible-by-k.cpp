class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int dirs[5] = {1, 0, -1, 0, 1};
        vector<int> stack;
        stack.reserve(m * n);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sum = grid[i][j];
                    grid[i][j] = 0;
                    stack.push_back(i * n + j);

                    while (!stack.empty()) {
                        int cur = stack.back();
                        stack.pop_back();
                        int r = cur / n, c = cur % n;
                        for (int d = 0; d < 4; d++) {
                            int nr = r + dirs[d], nc = c + dirs[d + 1];
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                                sum += grid[nr][nc];
                                grid[nr][nc] = 0;
                                stack.push_back(nr * n + nc);
                            }
                        }
                    }

                    if (sum % k == 0) ans++;
                }
            }
        }
        return ans;
    }
};
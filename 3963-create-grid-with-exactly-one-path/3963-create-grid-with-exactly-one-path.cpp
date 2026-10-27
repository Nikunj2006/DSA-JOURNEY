class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        int r = 0, c = 0;
        grid[0][0] = '.';

        while (r < m - 1 || c < n - 1) {
            if (r == m - 1)
                c++;
            else if (c == n - 1)
                r++;
            else if ((r + c) % 2 == 0)
                c++;
            else
                r++;

            grid[r][c] = '.';
        }

        return grid;
    }
};
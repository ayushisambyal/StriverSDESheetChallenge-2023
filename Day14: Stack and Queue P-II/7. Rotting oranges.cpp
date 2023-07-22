#include <bits/stdc++.h>

class Pair {
public:
    int row;
    int col;
    int tm;

    Pair(int _row, int _col, int _tm) {
        this->row = _row;
        this->col = _col;
        this->tm = _tm;
    }
};

int minTimeToRot(vector<vector<int>>& grid, int n, int m) {
    queue<Pair> q;
    int freshOranges = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push(Pair(i, j, 0));
            }
            else if (grid[i][j] == 1) {
                freshOranges++;
            }
        }
    }

    int tm = 0;
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    while (!q.empty()) {
        int r = q.front().row;
        int c = q.front().col;
        int t = q.front().tm;
        tm = max(tm, t);
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + delrow[i];
            int nc = c + delcol[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                q.push(Pair(nr, nc, t + 1));
                grid[nr][nc] = 2;
                freshOranges--;
            }
        }
    }

    if (freshOranges > 0) {
        return -1;
    }

    return tm;
}

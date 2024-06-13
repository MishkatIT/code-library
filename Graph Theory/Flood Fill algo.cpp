/*
    Author    : MishkatIT
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using ld = long double;
const ll mod = 1e9 + 7;
const ll N = 2e5 + 10;
const ll inf = 1e9;
const ll linf = 1e18;

int dy[] = {+1, -1, +0, +0, +1, +1, -1, -1};
int dx[] = {+0, +0, -1, +1, -1, +1, -1, +1};
//           R   L   U   D   RU  RD  LU  LD


void floodFill(vector<vector<int>>& grid, int x, int y, int newColor, int oldColor) {
    int n = grid.size();
    int m = grid[0].size();
    if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != oldColor) return;
    grid[x][y] = newColor;

    for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        floodFill(grid, nx, ny, newColor, oldColor);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m, x, y, newColor;
        cin >> n >> m >> x >> y >> newColor;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        int oldColor = grid[x][y];
        if (oldColor != newColor) {
            floodFill(grid, x, y, newColor, oldColor);
        }

        for (const auto& row : grid) {
            for (int cell : row) {
                cout << cell << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}

/*
    https://codeforces.com/contest/1985/problem/H1
    https://leetcode.com/problems/flood-fill/description/
*/
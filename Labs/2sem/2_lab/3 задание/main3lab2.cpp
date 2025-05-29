#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

const int dx[8] = {-1,-1,-1,0,1,1,1,0};
const int dy[8] = {-1,0,1,1,1,0,-1,-1};

int bfs(const vector<string>& grid, int n, int m, int sx, int sy, int ex, int ey) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<tuple<int, int, int>> q;
    q.push({sx, sy, 0});
    visited[sx][sy] = true;

    while (!q.empty()) {
        auto [x, y, steps] = q.front(); q.pop();
        if (x == ex && y == ey) return steps;

        for (int dir = 0; dir < 8; ++dir) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                !visited[nx][ny] && grid[nx][ny] != '#') {
                visited[nx][ny] = true;
                q.push({nx, ny, steps + 1});
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    cout << "Введите размеры поля N M: ";
    cin >> n >> m;

    vector<string> grid(n);
    int sx, sy, ex, ey;

    cout << "Введите поле:\n";
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'S') {
                sx = i; sy = j;
            }
            if (grid[i][j] == 'E') {
                ex = i; ey = j;
            }
        }
    }

    int result = bfs(grid, n, m, sx, sy, ex, ey);
    cout << "Минимальное количество шагов: " << result << endl;

    return 0;
}

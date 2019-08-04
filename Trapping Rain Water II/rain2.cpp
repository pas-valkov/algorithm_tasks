struct Cell {
    int val, x, y;
    Cell(int val, int x, int y) : val{val}, x{x}, y{y} {}
};

struct comp {
    bool operator() (const Cell &a, const Cell &b) {
        return a.val > b.val;
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& h) {
        if (h.size() == 0)
            return 0;
        vector<vector<int>> visited(h.size(), vector<int>(h[0].size(), 0));
        priority_queue<Cell, vector<Cell>, comp> q;
        for (int i = 0; i < h.size(); ++i)
            for (int j = 0; j < h[0].size(); ++j)
                if (i == 0 || i == h.size()-1 || j == 0 || j == h[0].size()-1) {
                    visited[i][j] = true;
                    q.push(Cell(h[i][j], i, j));
                }
        int answer = 0;
        vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            Cell temp_cell = q.top(); q.pop();
            for (auto dir : dirs) {
                int x = temp_cell.x + dir.first;
                int y = temp_cell.y + dir.second;
                if (!(x < 0 || x >= h.size() || y < 0 || y >= h[0].size()) && !visited[x][y]) {
                    visited[x][y] = true;
                    q.push(Cell{max(temp_cell.val, h[x][y]), x, y});
                    answer += max(0, temp_cell.val - h[x][y]);
                }
            }
        }
        return answer;
    }
};

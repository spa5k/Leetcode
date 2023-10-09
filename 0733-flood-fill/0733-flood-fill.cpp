class Solution
{
public:
    struct Coordinate
    {
        int r;
        int c;
        Coordinate(int r, int c) : r(r), c(c) {}
    };

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int num_rows = image.size();
        int num_cols = image[0].size();
        bfs(image, Coordinate(sr, sc), color, num_rows, num_cols);
        return image;
    }

    vector<Coordinate> get_neighbors(vector<vector<int>> &image, Coordinate node, int root_color, int num_rows, int num_cols)
    {
        vector<Coordinate> neighbors;
        int delta_row[4] = {-1, 0, 1, 0};
        int delta_col[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int neighbor_row = node.r + delta_row[i];
            int neighbor_col = node.c + delta_col[i];
            if (0 <= neighbor_row && neighbor_row < num_rows && 0 <= neighbor_col && neighbor_col < num_cols)
            {
                if (image[neighbor_row][neighbor_col] == root_color)
                {
                    neighbors.emplace_back(Coordinate(neighbor_row, neighbor_col));
                }
            }
        }

        return neighbors;
    }

    void bfs(vector<vector<int>> &image, Coordinate root, int replacement_color, int num_rows, int num_cols)
    {
        queue<Coordinate> q;
        q.push(root);
        vector<vector<bool>> visited(num_rows, vector<bool>(num_cols, false));
        int root_color = image[root.r][root.c];
        image[root.r][root.c] = replacement_color; // replace root color
        visited[root.r][root.c] = true;

        while (q.size() > 0)
        {
            Coordinate node = q.front();
            vector<Coordinate> neighbors = get_neighbors(image, node, root_color, num_rows, num_cols);
            for (Coordinate neighbor : neighbors)
            {
                if (visited[neighbor.r][neighbor.c])
                    continue;
                image[neighbor.r][neighbor.c] = replacement_color; // replace color
                q.push(neighbor);
                visited[neighbor.r][neighbor.c] = true;
            }
            q.pop();
        }
    }
};
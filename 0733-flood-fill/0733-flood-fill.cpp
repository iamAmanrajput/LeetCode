class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int newColor,
             int orgColor) {

        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() ||
            image[i][j] != orgColor) {
            return;
        }

        image[i][j] = newColor;

        dfs(image, i - 1, j, newColor, orgColor); // top
        dfs(image, i, j + 1, newColor, orgColor); // right
        dfs(image, i + 1, j, newColor, orgColor); // bottom
        dfs(image, i, j - 1, newColor, orgColor); // left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        if (image[sr][sc] == color)
            return image;

        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};
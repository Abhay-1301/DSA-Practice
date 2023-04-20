#include <bits/stdc++.h>
using namespace std;

void floodFill(vector<vector<int>> &image, int sr, int sc, int color, vector<vector<bool>> &visited, int sColor, int m, int n)
{
    image[sr][sc] = color;
    visited[sr][sc] = true;

    if ((sr - 1) >= 0 && !visited[sr - 1][sc] && image[sr - 1][sc] == sColor)
        floodFill(image, sr - 1, sc, color, visited, sColor, m, n);

    if ((sr + 1) < m && !visited[sr + 1][sc] && image[sr + 1][sc] == sColor)
        floodFill(image, sr + 1, sc, color, visited, sColor, m, n);

    if ((sc - 1) >= 0 && !visited[sr][sc - 1] && image[sr][sc - 1] == sColor)
        floodFill(image, sr, sc - 1, color, visited, sColor, m, n);

    if ((sc + 1) < n && !visited[sr][sc + 1] && image[sr][sc + 1] == sColor)
        floodFill(image, sr, sc + 1, color, visited, sColor, m, n);
}

int main()
{
    vector<vector<int>> image = {{1, 1, 1},
                                 {1, 1, 0},
                                 {1, 0, 1}};
    int m = 3;
    int n = 3;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int sr = 1;
    int sc = 1;
    int color = 2;
    int sColor = image[sr][sc];
    floodFill(image, sr, sc, color, visited, sColor, m, n);

    for (auto i : image)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}

// T.C = O(row*column) or O(V)
// S.C = O(row*column) or O(V) {visited matrix}
#include<bits/stdc++.h>
using namespace std;

int path(vector < vector < int >> & matrix, int i, int j, vector < vector < int >> & memo) {
    if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size())
        return 0;

    if (memo[i][j] > 0) return memo[i][j];

    int currentmax = 1;

    if (i + 1 < matrix.size() && i + 1 >= 0 && matrix[i + 1][j] > matrix[i][j]) {
        currentmax = max(currentmax, 1 + path(matrix, i + 1, j, memo));
    }

    if (j + 1 < matrix[0].size() && j + 1 >= 0 && matrix[i][j + 1] > matrix[i][j]) {
        currentmax = max(currentmax, 1 + path(matrix, i, j + 1, memo));
    }

    if (j - 1 < matrix[0].size() && j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j]) {
        currentmax = max(currentmax, 1 + path(matrix, i, j - 1, memo));
    }

    if (i - 1 < matrix.size() && i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j]) {
        currentmax = max(currentmax, 1 + path(matrix, i - 1, j, memo));
    }
    memo[i][j] = currentmax;

    return currentmax;
}

int longestPath(vector < vector < int >> & matrix) {
    vector < vector < int >> memo(matrix.size(), vector < int > (matrix[0].size(), 0));

    int maximum = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            maximum = max(maximum, path(matrix, i, j, memo));
        }
    }
    return maximum;
}




int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        vector < vector < int >> matrix1(m, vector < int > (n));
        vector < vector < int >> matrix2(m, vector < int > (n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix1[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix2[j][i];
            }
        }

        int x = longestPath(matrix1);
        int y = longestPath(matrix2);

        if (x > y) {
            cout << "1" << endl;
        } else if (y > x) {
            cout << "-1" << endl;
        } else {
            cout << "0" << endl;
        }

    }
}
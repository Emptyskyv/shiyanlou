#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> left(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    left[i][j] = matrix[i][j] == '1';
                } else {
                    if (matrix[i][j] == '1') {
                        left[i][j] = left[i][j - 1] + 1;
                    } else {
                        left[i][j] = 0;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (left[i][j] == 0) {
                    continue;
                } else {
                    int weight = left[i][j];
                    int height = 1;
                    int temp = weight * height;
                    for (int a = i - 1; a >= 0; a--) {
                        weight = min(weight, left[a][j]);
                        height++;
                        temp = max(temp, weight * height);
                    }
                    ans = max(temp, ans);
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution ss;
    vector<vector<char>> matrix = {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'},
    };
    ss.maximalRectangle(matrix);

    return 0;
}
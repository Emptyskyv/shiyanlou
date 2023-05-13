#include <vector>
#include <unordered_set>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> direction = {0, 1, 2, 3};
        int sum = matrix.size() * matrix[0].size();
        vector<vector<int>> flag(matrix.size(), vector<int>(matrix[0].size()));
        vector<int> ans;
        int index = 0;
        int i = 0;
        int j = 0;
        while (ans.size() < sum) {
            ans.emplace_back(matrix[i][j]);
            flag[i][j] = 1;
            if (direction[index] == 0) {
                j += 1;
            } else if (direction[index] == 1) {
                i += 1;
            } else if (direction[index] == 2) {
                j -= 1;
            } else {
                i -= 1;
            }
            if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || flag[i][j]) {
                if (direction[index] == 0) {
                    j -= 1;
                    i += 1;
                } else if (direction[index] == 1) {
                    i -= 1;
                    j -= 1;
                } else if (direction[index] == 2) {
                    j += 1;
                    i -= 1;
                } else {
                    i += 1;
                    j += 1;
                }
                index = (index + 1) % 4;
            }

        }

        return ans;
    }
};

int main() {
    vector<vector<int>> matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    Solution ss;
    ss.spiralOrder(matrix);

    return 0;
}
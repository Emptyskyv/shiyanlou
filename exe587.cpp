#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int cross(vector<int> p, vector<int> q, vector<int> r) {
    return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
}

bool cmp(const vector<int> &p, const vector<int> &q) {
    if (p[0] == q[0]) {
        return p[1] < q[1];
    }
    return p[0] < q[0];
}

vector<vector<int>> outerTrees(vector<vector<int>> &trees) {
    sort(trees.begin(), trees.end(), cmp);
    vector<bool> flags(trees.size(), false);
    vector<vector<int>> ans = {trees[0]};
    flags[0] = true;
    int now = 0;
    for (int i = 1; i < trees.size(); ++i) {
        if (!flags[i]) {
            bool access = true;
            for (int j = 1; j < trees.size(); ++j) {
                if (i == j) {
                    continue;
                }
                if (cross(trees[now], trees[i], trees[j]) < 0) {
                    access = false;
                    break;
                }
            }
            if (access) {
                flags[i] = true;
                ans.push_back(trees[i]);
                now = i;
            }
        }
    }

    return ans;
}

int main(void) {
    vector<vector<int>> trees = {{1, 1},
                                 {2, 2},
                                 {2, 0},
                                 {2, 4},
                                 {3, 3},
                                 {4, 2}};
    vector<vector<int>> ans = outerTrees(trees);
    for (auto x:ans) {
        cout << '[' << x[0] << ',' << x[1] << ']' << endl;
    }

    return 0;
}
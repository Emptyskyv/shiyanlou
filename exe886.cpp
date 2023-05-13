#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> m;
        for (auto& dis : dislikes) {
            m[dis[0]].emplace_back(dis[1]);
            m[dis[1]].emplace_back(dis[0]);
        }
        vector<int> visited(n + 1);
        unordered_set<int> a;
        unordered_set<int> b;
        for (int i = 1; i <= n; i ++) {
            if (m.count(i) == 0) {
                a.insert(i);
                visited[i] = 1;
            }
        }
        vector<int> at;
        vector<int> bt;
        for (int i = 1; i <= n; i ++) {
            if (!visited[i]) {
                at.emplace_back(i);
                break;
            }
        }
        bool isa = true;
        while (a.size() + b.size() < n) {
            if (isa) {
                for (int n : at) {
                    a.insert(n);
                    vector<int> temp = m[n];
                    for (int x : temp) {
                        bt.emplace_back(x);
                    }
                }
                at.clear();
                isa = false;
            } else {
                for (int n : bt) {
                    b.insert(n);
                    vector<int> temp = m[n];
                    for (int x : temp) {
                        at.emplace_back(x);
                    }
                }
                bt.clear();
                isa = false;
            }
        }
        for (auto& n : a) {
            if (b.count(n)) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution ss;
    vector<vector<int>> dislikes = {
            {1, 2},
            {1, 3},
            {2, 3},
    };
    ss.possibleBipartition(3, dislikes);

    return 0;
}
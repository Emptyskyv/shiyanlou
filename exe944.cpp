#include <vector>
#include <iostream>
#include <string>

using namespace std;

int minDeletionSize(vector<string>& strs) {
    if (strs.size() < 2) {
        return 0;
    }

    vector<int> com(strs[0].size());
    int ans = 0;
    for (int i = 0; i < strs[0].size(); ++i) {
        com[i] = strs[0][i];
    }
    vector<bool> flag(com.size(), true);
    for (int i = 1; i < strs.size(); ++i) {
        for (int j = 0; j < com.size(); ++j) {
            if (com[j] > strs[i][j]) {
                flag[j] = false;
            } else {
                com[j] = strs[i][j];
            }
        }
    }
    for (auto x : flag) {
        if (!x) {
            ++ans;
        }
    }

    return ans;
}

int main (void) {
    vector<string> strs = {"cba","daf","ghi"};
    cout << minDeletionSize(strs);

    return 0;
}
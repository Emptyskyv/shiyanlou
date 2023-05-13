#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if (k == 0) {
            return vector<int>(code.size());
        }
        int sum = 0;
        int index = 1;
        bool flag = false;
        if (k < 0) {
            reverse(code.begin(), code.end());
            flag = true;
            k = -k;
        }
        int temp = k;
        while (temp-- > 0) {
            sum += code[index++];
        }
        index = 1;
        vector<int> ans(code.size());
        for (int i = 0; i < code.size(); i++, index++) {
            ans[i] = sum;
            sum = sum - code[index % code.size()] + code[(index + k) % code.size()];
        }

        if (flag) {
            reverse(ans.begin(), ans.end());
        }

        return ans;
    }
};

int main() {
    vector<int> code = {2, 4, 9, 3};
    Solution ss;
    ss.decrypt(code, -2);
}
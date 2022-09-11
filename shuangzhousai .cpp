#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] >= nums[i] || nums[i] - nums[j] > k) {
                    continue;
                } else {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int ans = 0;
        for (auto num : dp) {
            ans = max(num, ans);
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> intervals = {
            {5, 10},
            {6, 8},
            {1, 5},
            {2, 3},
            {1, 10}
    };
    Solution ss;
    //ss.minGroups(intervals);

    return 0;
}
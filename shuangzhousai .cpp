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

class A {
private:
    int x;
public:
    A() {
        x = 1;
    }
    A(int _x) : x(_x) {}
    A(A& a) {
        x = a.x;
    }
    A operator=(const A& a) {
        x = a.x;
        return *this;
    }
    ~A() {}
};

int main() {
    A a(1);
    A b(2);
    A c(3);
    a = b = c;
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
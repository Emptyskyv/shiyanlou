#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i ++) {
            if (m.count(nums[i]) == 0) {
                m[nums[i]] = i;
            }
            if (m.count(target - nums[i]) != 0 && m[target - nums[i]] != i) {
                ans.emplace_back(m[target - nums[i]]);
                ans.emplace_back(i);
                return ans;
            }
        }

        return {};
    }
};int main() {
    vector<int> nums = {3,2,4};
    Solution ss;
    ss.twoSum(nums, 6);

    return 0;
}

int init() {
    cout << "for test" << endl;
}
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);

        return ans;
    }

    void dfs(vector<int>& nums, int index) {
        if (index > nums.size()) {
            return;
        }
        ans.emplace_back(temp);
        for (int i = index; i < nums.size(); i ++) {
            temp.emplace_back(nums[i]);
            dfs(nums, index + 1);
            temp.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {1,2,3};
    Solution ss;
    ss.subsets(nums);

    return 0;
}
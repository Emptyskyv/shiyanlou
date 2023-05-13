#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int begin = 0;
        vector<vector<int>> ans;
        while (begin < nums.size() - 2) {
            vector<vector<int>> temp;
            if (begin > 0 && nums[begin] == nums[begin - 1]) {
                begin++;
                continue;
            }
            twosum(nums, begin + 1, -nums[begin], temp);
            if (temp.size() != 0) {
                for (auto t : temp) {
                    t.emplace_back(nums[begin]);
                    ans.emplace_back(t);
                }
            }
            begin++;
        }

        return ans;
    }

    void twosum(vector<int>& nums, int begin, int sum, vector<vector<int>>& temp) {
        if (begin > nums.size() - 2) {
            return;
        }
        int left = begin;
        int right = nums.size() - 1;
        while (left < right) {
            int l = nums[left];
            int r = nums[right];
            if (l + r == sum) {
                temp.push_back({l, r});
                left++;
                right--;
            } else if (l + r < sum) {
                left++;
            } else {
                right--;
            }
            while (left < right && nums[left] == l) {
                left++;
            }
            while (left < right && nums[right] == r) {
                right--;
            }
        }
    }
};

int main() {
    vector<int> nums = {1,-1,-1,0};
    Solution ss;
    ss.threeSum(nums);

    return 0;
}
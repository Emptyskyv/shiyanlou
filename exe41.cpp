#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] <= 0) {
                nums[i] = nums.size() + 1;
            }
        }
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] <= nums.size()) {
                int index = nums[i] - 1;
                nums[index] = -nums[index];
            }
        }
        int ans = nums.size() + 1;
        cout << nums[0] << " " << nums[1] << " " << nums[2] << " " << nums[3];
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {3,4,-1,1};
    Solution ss;
    ss.firstMissingPositive(nums);

    return 0;
}
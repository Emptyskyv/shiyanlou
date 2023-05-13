#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        for (; i >= 0; i --) {
            if (i - 1 >= 0 && nums[i] > nums[i - 1]) {
                break;
            }
        }
        if (i == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        i--;
        for (int j = nums.size() - 1; j > i; j --) {
            if (nums[j] > nums[i]) {
                swap(nums[j], nums[i]);
                break;
            }
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    vector<int> nums = {3,2,1};
    Solution ss;
    ss.nextPermutation(nums);

    return 0;
}
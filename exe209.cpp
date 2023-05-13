#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int ans = nums.size();
        while (right < nums.size()) {
            while (right < nums.size() && sum < target) {
                sum += nums[right++];
            }
            while (left < right && sum >= target) {
                ans = min(ans, right - left);
                sum -= nums[left++];
            }
        }

        return ans;
    }
};

int main() {
    int target = 7;
    vector<int> nums = {
            2,3,1,2,4,3
    };
    Solution ss;
    ss.minSubArrayLen(target, nums);
}
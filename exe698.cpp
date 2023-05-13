#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k) {
            return false;
        }
        int key = sum / k;
        sort(nums.begin(), nums.end(), greater<int>());
        int begin = 0;
        int end = nums.size() - 1;
        int ans = 0;
        while (begin <= end) {
            int temp = nums[end--];
            while (temp < key) {
                temp += nums[begin++];
            }
            if (temp == key) {
                ans++;
                continue;
            } else if (temp > key) {
                return false;
            }
        }

        return ans == k ? true : false;
    }
};

int main() {
    vector<int> nums = {4,4,6,2,3,8,10,2,10,7};
    int k = 4;
    Solution ss;
    ss.canPartitionKSubsets(nums, k);

    return 0;
}
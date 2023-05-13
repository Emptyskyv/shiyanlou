#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<int> bigger(nums.size());
        int max = 0;
        vector<int> smaller(nums.size());
        int min = 1000000;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] >= max) {
                bigger[i] = nums[i];
                max = nums[i];
            } else {
                bigger[i] = max;
            }
        }

        for (int j = nums.size() - 1; j >= 0; j --) {
            if (nums[j] <= min) {
                smaller[j] = nums[j];
                min = nums[j];
            } else {
                smaller[j] = min;
            }
        }

        for (int j = nums.size() - 2; j >= 0; j --) {
            if (bigger[j] > smaller[j + 1]) {
                return j + 1;
            }
        }

        return 0;
    }
};

int main() {
    vector<int> nums = {5,0,3,8,6};
    Solution ss;
    ss.partitionDisjoint(nums);

    return 0;
}
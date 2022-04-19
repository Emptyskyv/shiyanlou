#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool carPooling(vector<vector<int>> &trips, int capacity) {
    int tomax = 0;
    vector<int> diff(1000, 0);
    for (auto x: trips) {
        int begin = x[1];
        int end = x[2];
        int num = x[0];
        diff[begin] += num;
        if (end < diff.size()) {
            diff[end] -= num;
        }
        tomax = max(tomax, end);
    }
    vector<int> nums(tomax + 1);
    nums.push_back(diff[0]);
    if (nums[0] > capacity) {
        return false;
    }
    for (int i = 1; i <= tomax; ++i) {
        nums[i] = nums[i - 1] + diff[i];
        if (nums[i] > capacity) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<vector<int>> nums = {{9, 0, 1},
                                {3, 3, 7}};
    int k = 4;
    cout << carPooling(nums, k);
    return 0;
}

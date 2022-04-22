//
// Created by Emptysky on 2022/4/22.
//
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int binsearch(vector<int> nums, int target) {
    int left = 0, right = nums.size() - 1;
    int mid = left + (right + left) / 2;
    while (left <= right) {
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        }
        mid = left + (right - left) / 2;
    }

    return -1;
}

int main(void) {
    vector<int> nums;
    int i = 0;
    while (i++ < 10) {
        nums.push_back(rand() % 101);
    }
    for (auto x:nums) {
        cout << x << " ";
    }
    sort(nums.begin(), nums.end());
    cout << endl;
    cout << binsearch(nums, 96);

    return 0;
}
#include <vector>
#include <iostream>

using namespace std;

//int numSubarrayProductLessThanK(vector<int> &nums, int k) {
//    vector<int> prenums(nums.size(), 1);
//    for (int i = 1; i < nums.size(); ++i) {
//        prenums[i] = prenums[i - 1] * nums[i - 1];
//    }
//    int left = 0;
//    int right = 0;
//    int ans = 0;
//    while (right < nums.size()) {
//        int temp = nums[right] * prenums[right] / prenums[left];
//        if (temp < k) {
//            ans += right - left + 1;
//            ++right;
//        } else {
//            if (left < right) {
//                ++left;
//            } else {
//                ++right;
//            }
//        }
//    }
//
//    return ans;
//}

int numSubarrayProductLessThanK2(vector<int> &nums, int k) {
    int left = 0;
    int right = 0;
    int ans = 0;
    int accu = nums[0];
    while (right < nums.size()) {
        if (accu < k) {
            ans += right - left + 1;
            ++right;
            accu *= nums[right];
        } else {
            if (left < right) {
                accu /= nums[left];
                ++left;
            } else {
                ++right;
                accu *= nums[right];
            }
        }
    }

    return ans;
}

int main(void) {
    vector<int> nums = {1, 2, 3};
    int k = 0;
    cout << numSubarrayProductLessThanK2(nums, k);

    return 0;
}
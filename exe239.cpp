#include <vector>
#include <deque>
#include <iostream>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> d;
    vector<int> ans;
    int i = 1;
    d.push_back(nums[0]);
    for (; i < k; ++i) {
        while (!d.empty() && nums[i] > d.back()) {
            d.pop_back();
        }
        d.push_back(nums[i]);
    }
    --i;
    ans.push_back(d.front());
    if (d.front() == nums[i - k + 1]) {
        d.pop_front();
    }
    ++i;
    for (; i < nums.size(); ++i) {
        while (!d.empty() && nums[i] > d.back()) {
            d.pop_back();
        }
        d.push_back(nums[i]);
        ans.push_back(d.front());
        if (d.front() == nums[i - k + 1]) {
            d.pop_front();
        }
    }

    return ans;
}

int main(void) {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums, k);

    return 0;
}
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> s;
    vector<int> ans(nums.size());
    for (int j = nums.size() - 1; j >= 0; --j) {
        while (!s.empty() && s.top() <= nums[j]) {
            s.pop();
        }
        s.push(nums[j]);
    }
    for (int j = nums.size() - 1; j >= 0; --j) {
        while (!s.empty() && s.top() <= nums[j]) {
            s.pop();
        }
        ans[j] = s.empty() ? -1 : s.top();
        s.push(nums[j]);
    }

    return ans;
}

int main(void) {
    vector<int> nums = {1,2,1};
    vector<int> ans = nextGreaterElements(nums);
    for (auto x : ans) {
        cout << x << ' ';
    }

    return 0;
}
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    int begin = 0;
    int end = arr.size();
    int mid;

    while (begin < end) {
        mid = begin + (end - begin) / 2;
        if (arr[mid] < x) {
            begin = mid + 1;
        } else if (arr[mid] > x) {
            end = mid;
        } else if (arr[mid] == x) {
            end = mid;
        }
    }
    int left = mid - 1;
    int right = mid;
    vector<int> ans;
    while (k) {
        if (left < 0) {
            ans.emplace_back(arr[right++]);
        } else if (right >= arr.size()) {
            ans.emplace_back(arr[left--]);
        } else {
            int a = abs(arr[left] - x);
            int b = abs(arr[right] - x);
            if (a <= b) {
                ans.emplace_back(arr[left--]);
            } else {
                ans.emplace_back(arr[right++]);
            }
        }
        k--;
    }
    sort(ans.begin(), ans.end());

    return ans;
}

int main() {
    vector<int> nums = {1,1,1,10,10,10};
    int k = 1;
    int x = 9;
    findClosestElements(nums, k, x);

    return 0;
}

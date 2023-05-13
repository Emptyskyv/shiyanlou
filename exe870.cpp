#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
        vector<int> index1(nums1.size()), index2(nums2.size());
        iota(index1.begin(), index1.end(), 0);
        iota(index2.begin(), index2.end(), 0);
        sort(index1.begin(), index1.end(), [&](int x, int y) { return nums1[x] < nums1[y]; });
        sort(index2.begin(), index2.end(), [&](int x, int y) { return nums2[x] < nums2[y]; });
        int begin = 0;
        int end = nums2.size() - 1;
        int index = 0;
        vector<int> ans(nums2.size());
        while (begin <= end) {
            if (nums2[index2[begin]] < nums1[index1[index]]) {
                ans[nums2[index2[begin]]] = nums1[index1[index++]];
                begin++;
            } else {
                ans[nums2[index2[end]]] = nums1[index1[index++]];
                end--;
            }
        }

        return ans;
    }
};

int main() {
    Solution ss;
    vector<int> num1 = {2, 0, 4, 1, 2};
    vector<int> num2 = {1, 3, 0, 0, 2};
    ss.advantageCount(num1, num2);

    return 0;
}
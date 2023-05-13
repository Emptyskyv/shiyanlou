#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void heap_sort(vector<int> &nums) {
        int sz = nums.size();
        for (int i = sz / 2 - 1; i >= 0; i--) {
            adjust(nums, i, sz);
        }
        // make_heap finish!
        while (sz) {
            swap(nums[0], nums[sz - 1]);
            sz--;
            adjust(nums, 0, sz);
        }
        cout << "Finish!" << endl;
    }

    void adjust(vector<int>& nums, int index, int size) {
        int temp = nums[index];
        int child = index * 2 + 1;
        while (child < size) {
            if (child + 1 < size && nums[child] < nums[child + 1]) {
                child++;
            }
            if (temp >= nums[child]) {
                break;
            }
            nums[index] = nums[child];
            index = child;
            child = 2 * index + 1;
        }
        nums[index] = temp;
    }


};

int main() {
    vector<int> nums = {2,5,6,3,6,7,8};
    Solution ss;
    ss.heap_sort(nums);

    return 0;
}
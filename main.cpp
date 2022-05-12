#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> nums) {
    if (nums.size() < 2) {
        return nums.size();
    }
    int quick = 1;
    int slow = 0;
    while (quick < nums.size()) {
        if (nums[quick] == nums[slow]) {
            ++quick;
        } else {
            ++slow;
            nums[slow] = nums[quick];
            ++quick;
        }
    }

    return slow + 1;
}

int main() {
    unordered_map<int, int> m;
    m[1] = 2;
    m[2] = 4;
    cout << m.size();
    cout << "Hello, World!" << std::endl;
    return 0;
}

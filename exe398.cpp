#include <vector>
#include <random>
#include <iostream>

using namespace std;

int pick(vector<int> num, int target) {
    int count = 0;
    int res = -1;
    for (int i = 0; i < num.size(); ++i) {
        if (num[i] != target) {
            continue;
        }
        ++count;
        if ((rand() % count) == 0) {
            res = i;
        }
    }

    return res;
}

int main(void) {
    vector<int> num = {1,2,3,3,3};
    cout << pick(num, 3);

    return 0;
}
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
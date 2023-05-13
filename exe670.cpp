#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string temp = to_string(num);
        int maxindex = temp.size() - 1;
        int maxnum = 0;
        int index1 = 0;
        int index2 = 0;
        for (int i = maxindex; i >= 0; i--) {
            if (temp[i] > temp[maxindex]) {
                maxindex = i;
            } else if (temp[i] < temp[maxindex]) {
                index1 = i;
                index2 = maxindex;
            }
        }
        if (index1 != index2) {
            swap(temp[index1], temp[index2]);
            return stoi(temp);
        }

        return num;
    }
};

int main() {
    int num = 2736;
    Solution ss;
    ss.maximumSwap(num);

    return 0;
}
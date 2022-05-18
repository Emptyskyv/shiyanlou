#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

bool oneEditAway(string first, string second) {
    int a = first.size();
    int b = second.size();
    if (abs(a - b) > 1) {
        return false;
    }
    if (first.size() > second.size()) {
        string temp = first;
        first = second;
        second = temp;
    }
    int i = 0;
    int j = 0;
    int ans = 0;
    if (a != b) {
        for (; i < second.size() && j < first.size(); ++i, ++j) {
            if (first[j] != second[i]) {
                ++i;
                if (first[j] == second[i]) {
                    ++ans;
                } else {
                    return false;
                }
            }
        }
    } else {
        for (; i < a; ++i) {
            if (first[i] != second[i]) {
                ++ans;
            }
        }
    }
    return ans > 1 ? false : true;
}

int main(void) {
    string first = "";
    string second = "p";

    cout << oneEditAway(first, second);

    return 0;
}
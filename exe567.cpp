#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> need, windows;
    for (auto x: s1) {
        ++need[x];
    }
    int left = 0, right = 0;
    int valid = 0;
    int len = 0;
    while (right < s2.size()) {
        char c = s2[right];
        ++right;
        if (need.count(c)) {
            ++windows[c];
            if (windows[c] == need[c]) {
                ++valid;
            }
        }
        while (valid == need.size()) {
            if (right - left == s1.size()) {
                return true;
            }
            char l = s2[left];
            if (need.count(l)) {
                --windows[l];
                if (windows[l] < need[l]) {
                    --valid;
                }
            }
            ++left;
        }
    }

    return false;
}

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << checkInclusion(s1, s2);

    return 0;
}

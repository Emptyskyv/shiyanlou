#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> need, windows;
    for (auto c: t) {
        ++need[c];
    }
    int left = 0, right = 0;
    int valid = 0;
    int len = INT_MAX;
    string ans = "";
    while (right <= s.size()) {
        if (valid >= need.size()) {
            char r = s[left];
            if (len > right - left) {
                len = right - left;
                ans = s.substr(left, len);
            }
            ++left;
            if (windows.count(r)) {
                --windows[r];
                if (windows[r] < need[r]) {
                    --valid;
                }
            }
        } else {
            if (right >= s.size()) {
                break;
            }
            char c = s[right];
            ++right;
            if (need.count(c)) {
                ++windows[c];
                if (windows[c] == need[c]) {
                    ++valid;
                }
            }
        }
    }

    return ans;
}

int main() {
    string s = "bba";
    string t = "ab";
    cout << minWindow(s, t);

    return 0;
}
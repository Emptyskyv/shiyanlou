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

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int> needs;
        unordered_map<int, int> windows;
        int flag = 0;
        for (auto ch : t) {
            needs[ch]++;
        }
        int left = 0;
        int right = 0;
        int length = INT_MAX;
        int begin = 0;
        while (right < s.size()) {
            auto ch = s[right++];
            if (needs.count(ch)) {
                windows[ch]++;
                if (windows[ch] == needs[ch]) {
                    flag++;
                }
            }
            while (flag == needs.size()) {
                auto ch2 = s[left];
                if (right - left < length) {
                    length = right - left;
                    begin = left;
                }
                left++;
                if (needs.count(ch2)) {
                    if (windows[ch2] == needs[ch2]) {
                        flag--;
                    }
                    windows[ch2]--;
                }
            }
        }
        string temp = s.substr(begin, length);
        return length == INT_MAX ? "" : temp;
    }
};

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution ss;
    ss.minWindow(s, t);
    //cout << minWindow(s, t);

    return 0;
}
#include<iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> windows;
    int left = 0, right = 0;
    int maxlen = 0;
    while (right < s.size()) {
        char c = s[right];
        ++right;
        if (windows[c] == 0) {
            ++windows[c];
            maxlen = max(maxlen, right - left);
        } else {
            while (s[left] != c) {
                char l = s[left];
                --windows[l];
                ++left;
            }
            ++left;
        }
    }

    return maxlen;
}

int main() {
    string s = "tmmzuxt";
    cout << lengthOfLongestSubstring(s);

    return 0;
}
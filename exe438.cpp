#include<iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> need, windows;
    for (auto x: p) {
        ++need[x];
    }
    int left = 0, right = 0;
    int valid = 0;
    vector<int> ans;
    while (right < s.size()) {
        char c = s[right];
        ++right;
        if (need.count(c)) {
            ++windows[c];
            if (windows[c] == need[c]) {
                ++valid;
            }
        }
        while (valid == need.size()) {
            char l = s[left];
            if (right - left == p.size()) {
                ans.push_back(left);
            }
            if (need.count(l)) {
                --windows[l];
                if (windows[l] < need[l]) {
                    --valid;
                }
            }
            ++left;
        }
    }

    return ans;
}

int main() {
    string s = "baa";
    string p = "aa";
    vector<int> ans = findAnagrams(s, p);
    for (auto x: ans) {
        cout << x;
    }
    return 0;
}
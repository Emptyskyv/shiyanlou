#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<string> diff;
    int distinctSubseqII(string s) {
        //long int ans = 0;
        for (int i = 0; i < s.size(); i ++) {
            string temp = "";
            dfs(s, i, temp);
        }

        return ((int)diff.size()) % 1000000007;
    }

    void dfs(string& s, int begin, string& temp) {
        if (begin >= s.size()) {
            return;
        }
        diff.insert(temp);
        for (int i = begin; i < s.size(); i ++) {
            dfs(s, i + 1, temp);
            temp += s[i];
            dfs(s, i + 1, temp);
            temp.pop_back();
        }
    }
};

int main() {
    string s = "abc";
    Solution ss;
    ss.distinctSubseqII(s);

    return 0;
}

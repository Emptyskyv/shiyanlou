#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string str;
    bool flags = false;
    bool wordBreak(string s, vector<string>& wordDict) {
        str = s;
        for (int i = 0; i < str.size(); i ++) {
            dfs(wordDict, 0, i);
        }

        return flags;
    }

    void dfs(vector<string>& wordDict, int begin, int end) {
        if (begin == str.size()) {
            flags = true;
            return;
        }

        string t = str.substr(begin, end - begin + 1);
        if (find(wordDict.begin(), wordDict.end(), t) != wordDict.end()) {
            cout << t << endl;
            for (int i = 1; i <= str.size() - end && !flags; i ++) {

                dfs(wordDict, end + 1, end + i);
            }
        } else {
            return;
        }
    }
};

int main() {
    Solution ss;
    string s = "leetcode";
    vector<string> word = {"leet", "code"};
    ss.wordBreak(s, word);

    return 0;
}

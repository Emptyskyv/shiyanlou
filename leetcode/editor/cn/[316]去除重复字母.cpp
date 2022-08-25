
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> s1;
        int cal[256] = {0};
        bool judge[256] = {false};

        for (auto x: s) {
            ++cal[x];
        }
        stack<char> temp;
        for (auto x: s) {
            --cal[x];
            if (judge[x]) {
                continue;
            }
            while (!s1.empty() && s1.top() > x && cal[s1.top()]) {
                judge[s1.top()] = false;
                s1.pop();
            }
            s1.push(x);
            judge[x] = true;
        }
        string ans = "";
        while(!s1.empty()) {
            ans += s1.top();
            s1.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
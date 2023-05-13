#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> record;
        int ans = 0;
        record.push(0);
        for (auto ch : s) {
            if (ch == '(') {
                record.push(0);
            } else {
                ans = record.top();
                record.pop();
                record.top() += max(ans * 2, 1);
            }
        }

        return record.top();
    }
};
int main() {
    Solution ss;
    string s = "(()(()))";
    ss.scoreOfParentheses(s);

    return 0;
}
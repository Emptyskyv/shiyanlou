#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if (s.size() < 2) {
            return s;
        }
        reverse(s.begin(), s.end());
        int left = 0;
        int right = 1;
        while (right < s.size()) {
            if (s[right] == ' ') {
                reverse(s.begin() + left, s.begin() + right);
                left = right + 1;
                right = left + 1;
            } else {
                right++;
            }
        }

        return s;
    }
};

int main() {
    Solution ss;
    string s = "the sky is blue";
    ss.reverseWords(s);

    return 0;
}
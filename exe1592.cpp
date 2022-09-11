#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string reorderSpaces(string s) {
        int n = s.size(), cnt = n, m = 0;
        for(int i = n-1, j = n-1, f = false; i >= 0; --i){
            if(s[i] != ' ') swap(s[i], s[j--]), m += !f, f = true, --cnt;
            else if(f) --j, f = false;
        }
        for(int i = 0, j = 0, f = false, a = cnt / max(m - 1, 1); i < n; ++i){
            if(s[i] != ' ') swap(s[i], s[j++]), f = true;
            else if(f) j += a, f = false;
        }
        return s;
    }
};

int main() {
    Solution ss;
    string text = " practice   makes   perfect";
    ss.reorderSpaces(text);

    return 0;
}

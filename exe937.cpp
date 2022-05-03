#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string s1, string s2) {
    string flag1, flag2;
    for (auto s: s1) {
        if (s != ' ') {
            flag1 += s;
        } else {
            break;
        }
    }
    for (auto s: s2) {
        if (s != ' ') {
            flag2 += s;
        } else {
            break;
        }
    }
    string left1, left2;
    left1 = s1.substr(flag1.size() + 1, s1.size() - flag1.size());
    left2 = s2.substr(flag2.size() + 1, s2.size() - flag2.size());
    bool num1 = false;
    bool num2 = false;
    if (left1[0] >= '0' && left1[0] <= '9') {
        num1 = true;
    }
    if (left2[0] >= '0' && left2[0] <= '9') {
        num2 = true;
    }
    if (num1 && !num2) {
        return false;
    } else if (!num1 && num2) {
        return true;
    }
    if (num1 && num2) {
        return false;
    } else if (!num1 && !num2) {
        if (left1 == left2) {
            return flag1 < flag2;
        }
    }
    bool l = left1 < left2;
    return left1 < left2;
}

vector<string> reorderLogFiles(vector<string> &logs) {
    sort(logs.begin(), logs.end(), cmp);

    return logs;
}

int main(void) {
    vector<string> logs = {"dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero"};
    vector<string> ans = reorderLogFiles(logs);
    for (auto s : ans) {
        cout << s << endl;
    }

    return 0;
}
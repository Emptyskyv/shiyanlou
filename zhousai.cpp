#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <numeric>
#include <valarray>

using namespace std;

class Solution {
public:
    double mean(vector<int>& temp) {
        double sum = accumulate(temp.begin(), temp.end(), 0);
        return sum / temp.size();
    }

    double variance(vector<int>& temp) {
        double ans = 0;
        double m = mean(temp);
        for (float x : temp) {
            ans += pow(x - m, 2);
        }

        return ans / temp.size();
    }

    vector<double> honeyQuotes(vector<vector<int>>& handle) {
        vector<int> temp;
        vector<double> ans;
        for (auto hand : handle) {
            if (hand[0] == 1) {
                temp.emplace_back(hand[1]);
            } else if (hand[0] == 2) {
                temp.erase(std::find(temp.begin(), temp.end(), hand[1]));
            } else if (hand[0] == 3) {
                if (temp.empty()) {
                    ans.emplace_back(-1);
                } else {
                    ans.emplace_back(mean(temp));
                }
            } else {
                if (temp.empty()) {
                    ans.emplace_back(-1);
                } else {
                    ans.emplace_back(variance((temp)));
                }
            }
        }

        return ans;
    }
};

int main() {
    string s = "leet**cod*e";
    // cout << removeStars(s);
    vector<vector<int>> handle = {{1,76}, {1,89}, {4},};
    Solution ss;
    ss.honeyQuotes(handle);
    return 0;
}
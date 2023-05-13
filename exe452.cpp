#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.size() < 2) {
            return 1;
        }

        sort(points.begin(), points.end(), [=](auto a, auto b) {
            return a[0] < b[0] || a[0] == b[0] && a[1] >= b[1];
        });
        int ans = 0;
        int left = points[0][0];
        int right = points[0][1];
        int index = 1;
        while (index < points.size()) {
            while (index < points.size() && left <= points[index][0] && points[index][0] <= right) {
                left = max(left, points[index][0]);
                right = min(right, points[index][1]);
                index++;
            }
            ans++;
            if (index < points.size()) {
                left = points[index][0];
                right = points[index][1];
            }
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> points = {
            {2,  8},
            {1,  6},
            {7,  12},
            {10, 18}
    };
    Solution ss;
    ss.findMinArrowShots(points);

    return 0;
}
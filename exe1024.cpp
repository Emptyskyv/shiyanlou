#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end(), [&](const auto& a, const auto& b) {
            return a[0] < b[0] || a[0] == b[0] && a[1] > b[1];
        });

        int index = 0;
        vector<int> first = clips[index++];
        if (first[0] != 0) {
            return -1;
        }
        int num = 1;
        while (index < clips.size()) {
            while (index < clips.size() && clips[index][1] <= first[1]) {
                index++;
            }
            if (index >= clips.size()) {
                break;
            }
            vector<int> next = clips[index++];
            while (index < clips.size() && clips[index][0] <= first[1]) {
                if (clips[index][1] > next[1]) {
                    next = clips[index];
                }
                index++;
            }
            if (next[0] > first[1]) {
                return -1;
            }
            first = next;
            num++;
        }

        return first[1] >= time ? num : -1;
    }
};

int main () {
    Solution ss;
    vector<vector<int>> clips{
            {5, 7},
            {1, 8},
            {0, 0},
            {2, 3},
            {4, 5},
            {0, 6},
            {5, 10},
            {7, 10}
    };
//    vector<vector<int>> clips = {
//            {0, 4},
//            {2, 8}
//    };
    int time = 5;
    ss.videoStitching(clips, time);

    return 0;
}
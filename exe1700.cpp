#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        unordered_map<int, int> mstu;
        unordered_map<int, int> msand;
        for (int i = 0; i < students.size(); i ++) {
            mstu[students[i]]++;
            msand[sandwiches[i]]++;
        }
        int stu = 0;
        int sand = 0;
        for (; mstu[0] > 0 && mstu[1] > 0; ) {
            if (students[stu] == sandwiches[sand]) {
                mstu[students[stu]]--;
                msand[students[stu]]--;
                stu++;
                sand++;
            } else {
                students.emplace_back(students[stu]);
                stu++;
            }
        }

        return mstu[0] + mstu[1];
    }
};

int main() {
    vector<int> students = {0,0,1,1,0,0,0,0,1,0,0,1,1,0,1,1};
    vector<int> sandwiches = {1,0,0,0,0,0,0,1,0,0,1,0,1,1,1,0};
    Solution ss;
    ss.countStudents(students, sandwiches);

    return 0;
}

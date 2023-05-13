#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int getKthMagicNumber(int k) {
        unordered_set<int> s;
        priority_queue<int, vector<int>, greater<>> heap;
        s.insert(1);
        heap.push(1);
        while (heap.size() < k) {
            int temp = heap.top();
            heap.pop();
            if (s.count(temp * 3) == 0) {
                s.insert(temp * 3);
                heap.push(temp * 3);
            }
            if (s.count(temp * 5) == 0) {
                s.insert(temp * 5);
                heap.push(temp * 5);
            }
            if (s.count(temp * 7) == 0) {
                s.insert(temp * 7);
                heap.push(temp * 7);
            }
        }
        int ans = 0;
        while (!s.empty()) {
            ans = heap.top();
            heap.pop();
        }

        return ans;
    }
};

int main() {
    int k = 5;
    Solution ss;
    ss.getKthMagicNumber(k);

    return 0;
}
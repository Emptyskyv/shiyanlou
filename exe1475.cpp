#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices);
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[j] <= prices[i]) {
                    ans[i] = prices[i] - prices[j];
                    break;
                }
            }
        }

        return ans;
    }
};

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    vector<int> prices = {10, 1, 1, 6};
    Solution ss;
    ss.finalPrices(prices);
    int* a;
    int b = 10;
    a = &b;
    int c = 12;
    int* d = &c;
    swap(a, d);
    cout << *a << " " << *d;

    return 0;
}
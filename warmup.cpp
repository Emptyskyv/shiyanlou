#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n != 0) {
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            nums.emplace_back(temp);
        }
        int ans = 0;
        int temp = 0;
        for (int i = 0; i < n; i++) {
            if (temp < 0) {
                temp = 0;
            }
            temp += nums[i];
            ans = max(ans, temp);
        }
        cout << ans << endl;
        cin >> n;
    }

    return 0;
}
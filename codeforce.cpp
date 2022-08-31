#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void function() {
    int n, m;
    cin >> n >> m;
    int matrix[n][m];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            matrix[i][j] = s[j] - '0';
            sum += matrix[i][j];
        }
    }
    int mmin = 5;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            int cnt = matrix[i][j] + matrix[i][j + 1] + matrix[i + 1][j] + matrix[i + 1][j + 1];
            if (cnt == 0) {
                mmin = 0;
                break;
            }
            mmin = min(mmin, max(1, cnt - 1));
        }
    }
    if (mmin == 0) {
        cout << sum << endl;
    } else {
        cout << 1 + sum - mmin << endl;
    }
}

int main() {
    int nums = 1;
    cin >> nums;
    while (nums--) {
        function();
    }


    return 0;
}
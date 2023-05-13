#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode& operator+(const TreeNode& t) {
        val += t.val;
        return *this;
    }
};

double fun(int x) {
    return x;
}

auto f = [](int a)->float {
    return a;
};


template <typename It>
auto fcn(It beg, It end) -> decltype(*beg)
{
    // 处理序列
    return *beg;    // 返回序列中一个元素的引用
}
template <typename It>
auto fcn2(It beg, It end) -> typename remove_reference<decltype(*beg)>::type {
    return *beg;
}

//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param heights int整型vector
//     * @return int整型vector
//     */
//    vector<int> findBuilding(vector<int>& heights) {
//        stack<int> front;
//        vector<int> count(heights.size());
//        for (int i = heights.size() - 1; i >= 0; i --) {
//            count[i] = front.size();
//            while (!front.empty() && front.top() <= heights[i]) {
//                front.pop();
//            }
//            front.push(heights[i]);
//        }
//        stack<int> back;
//        for (int i = 0; i < heights.size(); i ++) {
//            count[i] += back.size();
//            while (!back.empty() && back.top() <= heights[i]) {
//                back.pop();
//            }
//            back.push(heights[i]);
//        }
//
//        return count;
//    }
//};

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
//    int n, L;
//    cin >> n >> L;
//    vector<vector<int>> light(n, vector<int>());
//    for (int i = 0; i < n; i ++) {
//        int x, y;
//        cin >> x >> y;
//        vector<int> temp = {x, y};
//        light[i] = temp;
//    }
//
//    // 程序开始
//    sort(light.begin(), light.end(), [](auto& x, auto& y) {
//        return x[0] < y[0] || x[0] == y[0] && x[1] > y[1];
//    });
//    int left = 0;
//    int right = 0;
//    int ans = 1;
//    for (auto l : light) {
//        if (right >= L) {
//            cout << ans << endl;
//            break;
//        }
//        if (l[0] <= left) {
//            right = max(right, l[1]);
//        } else {
//            ans++;
//            left = right;
//            if (l[0] <= left) {
//                right = max(right, l[1]);
//            } else {
//                break;
//            }
//        }
//    }
//    if (right < L) {
//        cout << -1;
//    }
    int a = 1;
    int& b = a;
    auto test1 = b;
    test1 = 2;
    decltype(auto) test2 = b;
    //test2 = 3;
    auto f1 = [](auto& x) {
        return x;
    };
    auto test3 = f1(b);
    test3 = 3;

    cout << test3 << endl;
    cout << a << endl;
    test2 = 2;
    cout << a << endl;
    return 0;
}
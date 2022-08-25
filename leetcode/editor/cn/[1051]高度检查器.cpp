
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> height = heights;
        int sum = 0;
        sort(height.begin(), height.end());
        for (int i = 0; i < height.size(); ++i) {
            if (heights[i] != height[i]) {
                ++sum;
            }
        }

        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

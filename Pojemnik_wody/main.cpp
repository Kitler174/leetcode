using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    int maxArea(vector<int>& height) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        int left = 0; 
        int right = height.size() - 1; 
        int maxArea = 0;
        while (left < right) {
            int width = right - left;
            int currentHeight = min(height[left], height[right]);
            int currentArea = width * currentHeight;
            maxArea = max(maxArea, currentArea);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};

int main() {
    Solution sol;
    vector<int> nums= {1,1};

    int result = sol.maxArea(nums);
    cout << result << endl;
    return 0;
}
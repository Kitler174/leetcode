using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        int n = nums.size();
        int left,right,sum,i;
        int result = nums[0] + nums[1] + nums[2];;
        sort(nums.begin(), nums.end());
        for (i = 0; i < n - 2; i++) {
            left = i + 1;
            right = n - 1;
            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < abs(result - target)){
                    result = sum;
                }
                if (sum < target) {
                    left++; 
                } else if (sum > target) {
                    right--; 
                } else {
                    return result; 
                }
            }
        }
        return result;
    }
};


int main() {
    Solution sol;
    vector<int> nums= {1,1,1,0};
    int result = sol.threeSumClosest(nums, -100);
    cout << result;
    return 0;
}
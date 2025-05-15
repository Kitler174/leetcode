using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left,right;
        long sum;
        for (int i = 0; i < n - 3; i++) {
            if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            else if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                left = j + 1;
                right = n - 1;
                while (left < right) {
                    sum = (long long)nums[i] + (long long)nums[left] + (long long)nums[right] + (long long)nums[j];
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return result;
    }
};


int main() {
    Solution sol;
    vector<int> nums= {1,0,-1,0,-2,2};
    vector<vector<int>> result = sol.fourSum(nums,0);
    for (vector n: result){
        cout << n[0] << " " << n[1] << " " << n[2] << " " << n[3] << endl;
    }
    return 0;
}
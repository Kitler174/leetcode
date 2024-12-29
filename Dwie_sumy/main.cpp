using namespace std;
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (numToIndex.find(complement) != numToIndex.end()) {
                return {numToIndex[complement], i};
            }
            numToIndex[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution sol;  
    vector<int> nums = {3,3};
    int target = 6;
    vector<int> result = sol.twoSum(nums, target);
    cout << result[0] << " " << result[1];
    return 0;
}
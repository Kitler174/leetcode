using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return 1;
        int slow = 0; 
        for (int fast = 1; fast < size; fast++) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast]; 
            }
        }
        slow++;
        return slow;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2};
    int result = sol.removeDuplicates(nums);
    cout << result;
}
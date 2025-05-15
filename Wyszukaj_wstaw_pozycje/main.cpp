#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int right = nums.size();
        if (nums[right-1] < target) return right;
        int left = 0;
        int mid;
        while (left <= right){
            mid = left + (right - left) / 2;
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] < target) left=mid+1;
            else right=mid-1;
        }
        return left;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,5,6};
    int result = sol.searchInsert(nums,5);
    cout << result;
}
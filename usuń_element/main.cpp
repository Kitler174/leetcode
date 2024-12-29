using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i;
        int sum = 0;
        int size = nums.size();
        for (i = size-1; i > -1; i--){
            if (nums[i] == val){
                sum++;
                nums.erase(nums.begin()+i);
                nums.push_back(val);
                

            }
        }     
        return size - sum;
    }
};

int main() {
    Solution sol;
    vector<int> nums= {3,2,2,3};
    int result = sol.removeElement(nums,3);
    cout << result << endl;
    return 0;
}
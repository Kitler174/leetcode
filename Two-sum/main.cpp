using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            for (int i = 0; i < nums.size()-1; i++){
                for (int g = 0; g < nums.size()-1; g++){
                    if (nums[i] + nums[g] == target && i != g){
                        return {i,g};
                    }
                }            
            }        
            return {};    
        }
};

int main() {
    Solution sol;
    vector<int> input = {1, 2, 3};
    vector<int> result = sol.twoSum(input, 5);
    for (int i = 0; i < result.size()-1;i++){
        cout << result[i] << endl;
    }
    return 0;
}
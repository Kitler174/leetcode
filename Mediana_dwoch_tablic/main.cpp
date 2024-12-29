using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (int s: nums2){
            nums1.push_back(s);
        }
        sort(nums1.begin(), nums1.end());
        int size = nums1.size();
        float result;
        if (size % 2 == 0){
            result = (float)(nums1[size/2-1] + nums1[size/2]) / 2;
        }
        else{
            result = nums1[size/2];
        }
        return result;
    }
};

int main() {
    Solution sol;  
    vector<int> nums = {1,3};
    vector<int> nums2= {2,4};
    int result = sol.findMedianSortedArrays(nums, nums2);
    cout << result;
    return 0;
}
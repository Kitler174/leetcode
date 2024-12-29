using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        auto min_it = (string)*min_element(strs.begin(), strs.end()); 
        int licz = min_it.length();
        bool a;
        while (licz > 0){
            for (const auto& str : strs) {
                a = true;
                if (min_it != str.substr(0, min_it.length())){
                    min_it.pop_back();
                    a = false;
                    break;
                }
            }
            if (a){
                return min_it;
            }
            licz--;
        }
        return "";
    }
};

int main() {
    Solution sol;
    vector<string> nums= {"reflower","flow","flight"};
    string result = sol.longestCommonPrefix(nums);
    cout << endl;
    cout << result << endl;
    return 0;
}
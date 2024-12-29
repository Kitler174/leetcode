using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    int romanToInt(const std::string& s) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        vector<int> romanValues(89, 0); 
        romanValues['I'] = 1;
        romanValues['V'] = 5;
        romanValues['X'] = 10;
        romanValues['L'] = 50;
        romanValues['C'] = 100;
        romanValues['D'] = 500;
        romanValues['M'] = 1000;

        int total = 0;
        int length = s.length();

        for (int i = 0; i < length; ++i) {
            int currentVal = romanValues[s[i]];
            if (i + 1 < length && romanValues[s[i]] < romanValues[s[i + 1]]) {
                total -= currentVal;
            } else {
                total += currentVal;
            }
        }
        return total;
    }
};

int main() {
    Solution sol;
    int result = sol.romanToInt("LVIII");
    cout << result << endl;
    return 0;
}
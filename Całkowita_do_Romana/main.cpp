using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> roman = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        string result;
        for (const auto& [value, symbol] : roman){
            while (value <= num){
                result+=symbol;
                num-=value;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    string result = sol.intToRoman(58);
    cout << result << endl;
    return 0;
}
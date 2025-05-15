using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    string digitss;
    vector<string> result;
    string combination;
    vector<string> phoneMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backtrack(int index) {
        if (index == digitss.size()) {
            result.push_back(combination);
            return;
        }
        string letters = phoneMap[digitss[index] - '0'];
        for (char letter : letters) {
            combination.push_back(letter);
            backtrack(index + 1);
            combination.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        digitss = digits;
        backtrack(0);
        return result;
    }
};

int main() {
    Solution sol;
    vector<string> result = sol.letterCombinations("23");
    for (const string& n: result){
        cout << n << endl;
    }
    return 0;
}
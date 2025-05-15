using namespace std;
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <limits>

class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        int n = s.length();
        int result = 0;
        int sign = 1;
        while (index < n && isspace(s[index])) {
            index++;
        }
        if (index < n && (s[index] == '-' || s[index] == '+')) {
            sign = (s[index] == '-') ? -1 : 1;
            index++;
        }
        while (index < n && isdigit(s[index])) {
            int digit = s[index] - '0';
            if (result > (numeric_limits<int>::max() - digit) / 10) {
                return (sign == 1) ? numeric_limits<int>::max() : numeric_limits<int>::min();
            }
            result = result * 10 + digit;
            index++;
        }

        return result * sign;
    }
};

int main() {
    Solution sol;
    int result = sol.myAtoi("42");
    cout << result << endl;
    return 0;
}
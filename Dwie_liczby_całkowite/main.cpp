using namespace std;
#include <iostream>
#include <algorithm>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; 
        }
        return dividend / divisor;
    }
};
int main() {
    Solution sol;
    int result = sol.divide(-2147483648,-1);
    cout << result;
}
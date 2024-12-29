using namespace std;
#include <iostream>
#include <algorithm>

class Solution {
public:
    int reverse(int x) {
        int result = 0;
    
        while(x!=0) {
            int d = x%10;
            if(result > INT_MAX/10 || result < INT_MIN/10) {
                return 0;
            }
            result = result*10 + d;
            x /= 10;
        }
    }
};

int main() {
    Solution sol;
    int result = sol.reverse(12345678);
    cout << result << endl;
    return 0;
}
using namespace std;
#include <iostream>

class Solution {
    public:
        double myPow(double x, int n) {
            long long N = n; 
            if (N < 0) {
                x = 1 / x;
                N = -N;
            }
    
            double result = 1.0;
            while (N) {
                if (N % 2 == 1) {
                    result *= x;
                }
                x *= x;
                N /= 2;
            }
    
            return result;
        }
};
    

int main() {
    Solution sol;
    double result = sol.myPow(2,-3);
    cout << result << endl;
    return 0;
}
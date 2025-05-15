using namespace std;
#include <iostream>
#include <algorithm>


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)){
            return false;
        }
        int result = 0;
        int xx = x;
        while(x!=0) {
            int d = x%10;
            if(result > INT_MAX/10 || result < INT_MIN/10) {
                result = 0;
                break;
            }
            result = result*10 + d;
            x /= 10;
        }
        if (xx == result){
            return true;
        }
        return false;
    }
};
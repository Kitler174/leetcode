using namespace std;
#include <iostream>
#include <algorithm>
#include <iterator>
class Solution {
public:
    string longestPalindrome(string s) {
        int maxLength = s.length();
        string text;
        string longest;
        string ends;
        string endss;
        for (int end = 0; end < maxLength; ++end){
            int maxLength = s.length();
            int start = 0, maxLen = 1;
            auto expandAroundCenter = [&](int lewo, int prawo) {
                while (lewo >= 0 && prawo < maxLength && s[lewo] == s[prawo]) {
                    lewo--;
                    prawo++;
                }
            return prawo - lewo - 1;
            };

            for (int end = 0; end < maxLength; ++end) {
                int len1 = expandAroundCenter(end, end);
                int len2 = expandAroundCenter(end, end + 1);
                int len = max(len1, len2);
                if (len > maxLen) {
                    maxLen = len;
                    start = end - (len - 1) / 2; 
                }
            }
            return s.substr(start, maxLen);
        }
        return "";
    }
};

int main() {
    Solution sol;  
    string result = sol.longestPalindrome("abcdasdfghjkldcba");
    cout << result;
    return 0;
}
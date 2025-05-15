using namespace std;
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <iterator>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int start = 0;
        unordered_set<char> charSet;
        for (int end = 0; end < s.length(); ++end){
            char currentChar = s[end];
            while (charSet.find(currentChar) != charSet.end()) {
                charSet.erase(s[start]);
                start++;
            }
            
            charSet.insert(currentChar);
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};

int main() {
    Solution sol;  
    int result = sol.lengthOfLongestSubstring("abcabcde");
    cout << result;
    return 0;
}
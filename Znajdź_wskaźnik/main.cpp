using namespace std;
#include <iostream>
#include <algorithm>

class Solution {
public:
    int strStr(string haystack, string needle) {
        int size = haystack.size();
        if (size == 1 && haystack == needle)return 0;
        int len = needle.size();
        int i,j;
        for (i=0; i < size-len+1; i++){
            if (haystack[i] == needle[0]){
                j = 0;
                while (j < len && haystack[i + j] == needle[j]) {
                    j++;
                }
                if (j == len)return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    int result = sol.strStr("abc","c");
    cout << result;
}
using namespace std;
#include <iostream>
#include <algorithm>

class Solution {
public:
    int minLength(string s) {
        int i;
        bool act = true;
        string current = s;
        while (act){
            act = false;
            current = "";
            for (i=0; s.length() > i; i++){
                if ((s[i] == 'A' && s[i+1] == 'B') || (s[i] == 'C' && s[i+1] == 'D')){
                    act = true;
                    i++;
                }
                else{
                    current += s[i];
                }
            }
            s = current;
        }
        return s.length();
    }
};

int main() {
    Solution sol;  
    int result = sol.minLength("ABFCACDB");
    cout << result;
    return 0;
}
using namespace std;
#include <iostream>

string func(string n) {
    string d = "";
    int i = 0;
    while (i < n.length()) {
        char rest = n[i];
        int count = 0;
        while (i < n.length() && n[i] == rest) {
            count++;
            i++;
        }
        d += to_string(count);
        d += rest;
    }
    return d;
}



class Solution {
    public:
        string countAndSay(int n) {
            if (n == 1){
                return "1";
            }
            else{
                string dd = "1";
                for (int d = 1; d < n; d++){
                    dd = func(dd);
                }
                return dd;
            }
        }
};

int main() {
    Solution sol;
    string result = sol.countAndSay(9);
    cout << result << endl;
    return 0;
}
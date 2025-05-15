using namespace std;
#include <iostream>
#include <sstream>

string func(const string& n) {
    ostringstream d;
    int i = 0;
    while (i < n.length()) {
        char rest = n[i];
        int count = 0;
        while (i < n.length() && n[i] == rest) {
            count++;
            i++;
        }
        d << count << rest;
    }
    return d.str();
}



class Solution {
    public:
        string countAndSay(int n) {
                string dd = "1";
                for (int d = 1; d < n; d++){
                    dd = func(dd);
                }
                return dd;
        }
};

int main() {
    Solution sol;
    string result = sol.countAndSay(9);
    cout << result << endl;
    return 0;
}
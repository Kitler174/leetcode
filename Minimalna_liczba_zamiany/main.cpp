using namespace std;
#include <iostream>
#include <algorithm>

class Solution {
public:
    int minSwaps(string s) {
        int balans = 0;
        int potrzebne_zamiany = 0;
        for (char znak : s) {
            if (znak == '[') {
                balans++;
            } else {
                balans--;
            }
            if (balans < 0) {
                potrzebne_zamiany++;  
                balans += 2;
            }
        }
        
        return potrzebne_zamiany;
    }
};

int main() {
    Solution sol;  
    int result = sol.minSwaps("]]] [[[");
    cout << result;
    return 0;
}
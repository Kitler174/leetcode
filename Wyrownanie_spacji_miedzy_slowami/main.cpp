using namespace std;
#include <iostream>
#include <vector>

class Solution {
public:
    string reorderSpaces(string text) {
        string result = "";
        int size = text.length();
        int spaces = 0;
        int words = 0;
        bool act=true;
        int d;
        for (int i = 0; i < size; i++){
            if (text[i] == ' '){
                spaces++;
                act = true;
            }
            else if(act){
                words++;
                act = false;
            }
        }
        if (words == 1){
            for (int i = 0; i < size; i++){
                if (text[i] != ' '){
                    result+=text[i];
                    act = true;
                }
            }
            for (int d = 0; d < spaces; d++){
                result+=' ';
            }
            return result;
        }
        words--;
        int rest = spaces % words;
        spaces = spaces/words;
        act = false;
        for (int i = 0; i < size; i++){
            if (text[i] != ' '){
                result+=text[i];
                act = true;
            }
            else if (act && words>0){
                for (d = 0; d < spaces; d++){
                    result+=' ';
                }
                act = false;
                words--;
            }
        }
        for (d = 0; d < rest; d++){
            result+=' ';
        }
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.reorderSpaces("  hello");
    cout << '|';
}
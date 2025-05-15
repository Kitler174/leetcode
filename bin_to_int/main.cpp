using namespace std;
#include <iostream>

int bin_to_ten(const char* com){
    int i;
    int potega_n = 1;
    int result = 0;
    for (i=0; com[i]!='\0'; i++){}
    i--;
    while (i > -1){
        if (com[i] == '1'){
            result+=potega_n;
        }
        potega_n*=2;
        i--;
    }
    return result; 
}

int main() {
    char command[1024] = "10010";
    int result = bin_to_ten(command);
    cout << result;
}
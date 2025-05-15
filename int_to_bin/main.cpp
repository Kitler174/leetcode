using namespace std;
#include <iostream>

void ten_to_bin(const char* com,int x, int y){
    int num = 0;
    int potega_n = 1;
    int char_l = 0;
    for (int i=0; com[i]!='\0'; i++){
        num = num*10 + (com[i] -'0');
    }
    while (potega_n < num){
        potega_n*=2;
        char_l++;
    }
    potega_n/=2;
    char result[char_l+1];
    int d;
    for (d=0; potega_n != 0; d++){
        if (num >= potega_n){
            num -= potega_n;
            result[d] = '1';
        }
        else{
            result[d] = '0';
        }
        potega_n/=2;

    }
    result[d] = '\0';
    return result;
}

int main() {
    char command[1024] = "23";
    char* result = ten_to_bin(command);
    
}
using namespace std;
#include <iostream>

typedef struct {
    char text[1024];
    int length;
} Result;

Result ret_next_text(const char* command, int startfrom){
    Result Res;
    int count = 0;
    for (int i=startfrom; command[i]!=' ' && command[i]!='\0'; i++){
        Res.text[count] = command[i];
        count++;
    }
    Res.length = startfrom + count;
    Res.text[count] = '\0';
    return Res;
}

int main(){
    char* command = "CREATE-ACC DA BC";
    Result result;
    int counter = 0;
    result = ret_next_text(command, counter);
    char buffer[1024] = {0};
    counter = result.length + 1;
    result = ret_next_text(command, counter);
    for (int i = 0; result.text[i] != '\0'; i++){
        cout << result.text[i] << endl;
    }
    counter = result.length + 1;
    result = ret_next_text(command, counter);
    for (int i = 0; result.text[i] != '\0'; i++){
        cout << result.text[i] << endl;
    }
}
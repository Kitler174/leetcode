using namespace std;
#include <iostream>
#include <vector>
class Solution {
public:
    int maximumSwap(int num) {
        int sum=0;
        vector<int> vec = {};
        while (num != 0){
            vec.push_back(num % 10);
            sum+=1;
            num /= 10;
        }
        int last;
        for (int i = 0; i < sum-1; i++){
            if (vec[i] > vec[i+1]){
                last = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = last;
                i=-1;
            }
        }
        sum = 0;
        int r = 1;
        for (int s: vec){
            sum += s*r;
            r*=10;
        }
        return sum;
    }
};

int main() {
    Solution sol;
    cout << sol.maximumSwap(98368);
}
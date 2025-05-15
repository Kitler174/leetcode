#include <unordered_map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;
        
        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        if (s.size() < totalLen) return result;

        unordered_map<string, int> wordMap;
        for (string& word : words) {
            wordMap[word]++;
        }
        for (int i = 0; i < wordLen; i++) {
            int left = i, count = 0;
            unordered_map<string, int> seen;
            for (int right = i; right <= (int)s.size() - wordLen; right += wordLen) {
                string word = s.substr(right, wordLen);
                if (wordMap.find(word) != wordMap.end()) {
                    seen[word]++;
                    count++;
                    while (seen[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return result;
    }
};
int main() {
    Solution sol;
    string s1 = "barfoothefoobarman";
    vector<string> words1 = {"foo", "bar"};
    vector<int> result1 = sol.findSubstring(s1, words1);
    
    cout << "Przykład 1 wynik: ";
    for (int index : result1) {
        cout << index << " ";
    }
}
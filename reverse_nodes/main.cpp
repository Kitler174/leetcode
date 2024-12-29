using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> result = {};
        while (head != nullptr) {
            result.push_back(head->val);
            head = head->next;
        }
        ListNode* dummy = new ListNode(0);
        head = dummy;
        int size = result.size();
        int a = size / k;
        int help = 0;
        int help2 = k;
        int b = a*k;
        while (a > 0){
            while (help2 > help){
                head->next = new ListNode(result[help2-1]);
                head = head->next;
                help2--;
            }
            help+=k;
            help2+=2*k;
            a--;
        }
        while (b < size){
            head->next = new ListNode(result[b]);
            head = head->next;
            b++;
        }
        return dummy->next;
    }
};

int main() {
    ListNode* list1 = new ListNode(1, new ListNode(4, new ListNode(5, new ListNode(1, new ListNode(3, new ListNode(4))))));
    Solution sol;
    printList(sol.reverseKGroup(list1, 4));
}
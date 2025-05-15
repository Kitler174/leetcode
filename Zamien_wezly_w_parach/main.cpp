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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* dummy = new ListNode(0); 
        dummy->next = head;
        ListNode* result = dummy;
        ListNode* first;
        ListNode* second;
        while (head != nullptr){
            first = head;
            second = head->next;
            if (second == nullptr){
                result->next = first;
                return dummy->next;
            }
            first->next = second->next; 
            second->next = first;   
            result->next = second;   
            result = first;              
            head = first->next; 
        }
        return dummy->next;
    }
};

int main() {
    ListNode* list1 = new ListNode(1, new ListNode(4, new ListNode(5, new ListNode(1, new ListNode(3)))));
    Solution sol;
    printList(sol.swapPairs(list1));
}
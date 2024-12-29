#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* current = &dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        return dummy.next;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution sol;  
    ListNode* l11 = new ListNode(2);
    l11->next = new ListNode(4);
    l11->next->next = new ListNode(3); // 342
    ListNode* l22 = new ListNode(5);
    l22->next = new ListNode(6);
    l22->next->next = new ListNode(4); // 465
    ListNode* result = sol.addTwoNumbers(l11, l22);
    printList(result);
    return 0;
}
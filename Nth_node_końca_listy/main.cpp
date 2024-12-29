using namespace std;
#include <iostream>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        for (n; n > 0; n--){
            fast = fast->next;
        }
        while (fast != nullptr) {
            fast = fast->next;
            prev = slow; 
            slow = slow->next;
        }

        if (prev != nullptr) {
            prev->next = slow->next; 
        } else {
            head = head->next;
        }

        delete slow;
        return head;
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
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(3)));
    ListNode* result = sol.removeNthFromEnd(list1, 2);
    printList(result);
    return 0;
}
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

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> result = {};
        for (int i = 0; i < lists.size(); i++){
            ListNode* current = lists[i];
            while (current != nullptr){
                result.push_back(current->val);
                current = current->next;
            }
        }
        if (result.empty()) return nullptr;
        ListNode* dummy = new ListNode(result[0]);
        ListNode* res = dummy;
        sort(result.begin(), result.end());
        for (int ii = 0; ii < result.size(); ii++){
            ListNode* newNode = new ListNode(result[ii]);
            res->next = newNode;
            res = res->next;
        }
        return dummy->next;
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
    ListNode* list1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* list3 = new ListNode(2, new ListNode(6));
    ListNode* list4 = nullptr;
    vector<ListNode*> k = {list4};
    Solution sol;
    ListNode* mergedList = sol.mergeKLists(k);
    printList(mergedList);
    return 0;
}
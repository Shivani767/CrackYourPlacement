// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1, v2;
        while (l1) {
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            v2.push_back(l2->val);
            l2 = l2->next;
        }
        
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        while (!v1.empty() || !v2.empty() || carry) {
            int sum = carry;
            if (!v1.empty()) {
                sum += v1.back();
                v1.pop_back();
            }
            if (!v2.empty()) {
                sum += v2.back();
                v2.pop_back();
            }
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            node->next = dummy->next;
            dummy->next = node;
        }
        
        return dummy->next;
    }
};

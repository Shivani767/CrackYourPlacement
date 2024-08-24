class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;
        
        while (l1!= nullptr || l2!= nullptr || carry!= 0) {
            int sum = (l1!= nullptr? l1->val : 0) + (l2!= nullptr? l2->val : 0) + carry;
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
            
            if (l1!= nullptr) l1 = l1->next;
            if (l2!= nullptr) l2 = l2->next;
        }
        
        return dummy->next;
    }
};

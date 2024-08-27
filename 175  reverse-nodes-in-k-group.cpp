class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        
        int count = 0;
        ListNode* cur = head;
        while (cur != nullptr && count < k) {
            cur = cur->next;
            count++;
        }
        
        if (count == k) {
            cur = pre->next;
            for (int i = 0; i < k - 1; i++) {
                ListNode* temp = cur->next;
                cur->next = temp->next;
                temp->next = pre->next;
                pre->next = temp;
            }
            pre = cur;
            cur = cur->next;
            count = 0;
        } else {
            return dummy->next;
        }
        
        while (cur != nullptr) {
            count = 0;
            while (cur != nullptr && count < k) {
                cur = cur->next;
                count++;
            }
            
            if (count == k) {
                ListNode* temp = pre->next;
                for (int i = 0; i < k - 1; i++) {
                    ListNode* temp2 = temp->next;
                    temp->next = temp2->next;
                    temp2->next = pre->next;
                    pre->next = temp2;
                }
                pre = temp;
                temp = temp->next;
                count = 0;
            } else {
                return dummy->next;
            }
        }
        
        return dummy->next;
    }
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        
        for (int i = 1; i < left; i++) {
            pre = pre->next;
        }
        
        ListNode* cur = pre->next;
        for (int i = left; i < right; i++) {
            ListNode* temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        
        return dummy->next;
    }
};

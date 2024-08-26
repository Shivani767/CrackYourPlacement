class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* before = new ListNode(0);
        ListNode* after = new ListNode(0);
        ListNode* beforePtr = before;
        ListNode* afterPtr = after;
        
        while (head != nullptr) {
            if (head->val < x) {
                beforePtr->next = head;
                beforePtr = beforePtr->next;
            } else {
                afterPtr->next = head;
                afterPtr = afterPtr->next;
            }
            head = head->next;
        }
        
        afterPtr->next = nullptr;
        beforePtr->next = after->next;
        
        return before->next;
    }
};

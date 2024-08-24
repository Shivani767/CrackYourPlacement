/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* slow = head, *fast = head;
        stack<int> s;
        
        // find the middle of the linked list
        while (fast && fast->next) {
            s.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // if the length of the linked list is odd, skip the middle node
        if (fast) slow = slow->next;
        
        // compare the first half and the second half
        while (slow) {
            if (s.top() != slow->val) return false;
            s.pop();
            slow = slow->next;
        }
        
        return true;
    }
};

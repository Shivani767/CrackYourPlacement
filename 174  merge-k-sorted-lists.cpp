/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (auto list : lists) {
            if (list) pq.push(list);
        }
        ListNode dummy;
        ListNode* cur = &dummy;
        while (!pq.empty()) {
            cur->next = pq.top();
            pq.pop();
            cur = cur->next;
            if (cur->next) pq.push(cur->next);
        }
        return dummy.next;
    }
};

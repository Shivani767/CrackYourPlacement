
class Solution {
public:
    // Utility function to reverse the linked list
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    // Utility function to remove leading zeros
    Node* removeLeadingZeros(Node* head) {
        while (head != nullptr && head->data == 0) {
            head = head->next;
        }
        return head == nullptr ? new Node(0) : head;
    }

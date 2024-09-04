The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
public:
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;

        while (current != NULL) {
            next = current->next;  // Store the next node
            current->next = prev;  // Reverse the link
            prev = current;        // Move prev and current one step forward
            current = next;
        }

        return prev;  // New head of the reversed list
    }

    Node* compute(Node* head) {
        if (!head) return NULL;

        // Reverse the linked list
        head = reverseList(head);

        Node* current = head;
        Node* maxNode = head;
        Node* temp;

        while (current != NULL && current->next != NULL) {
            if (current->next->data < maxNode->data) {
                // Skip the node if the next node's data is less than maxNode's data
                temp = current->next;
                current->next = temp->next;
                delete temp;  // Optional: free the memory of the skipped node
            } else {
                // Update maxNode if the next node's data is greater
                current = current->next;
                maxNode = current;
            }
        }

        // Reverse the list again to restore the original order
        head = reverseList(head);

        return head;
    }
};

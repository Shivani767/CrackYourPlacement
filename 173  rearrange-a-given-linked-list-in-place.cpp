#include <iostream>

// Linked list Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a new Node in a linked list
Node* newNode(int key) {
    Node* temp = new Node;
    temp->data = key;
    temp->next = nullptr;
    return temp;
}

// Function to reverse the linked list
void reverseList(Node** head) {
    // Initialize prev and current pointers
    Node* prev = nullptr;
    Node* curr = *head;
    Node* next = nullptr;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        if (head->next) {
            std::cout << "-> ";
        }
        head = head->next;
    }
    std::cout << std::endl;
}

// Function to rearrange a linked list
void rearrange(Node** head) {
    // 1) Find the middle point using tortoise and hare method
    Node* slow = *head;
    Node* fast = slow->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2) Split the linked list in two halves
    Node* head1 = *head;
    Node* head2 = slow->next;
    slow->next = nullptr;

    // 3) Reverse the second half
    reverseList(&head2);

    // 4) Merge alternate nodes
    *head = newNode(0); // Assign dummy Node
    Node* curr = *head;
    while (head1 || head2) {
        // First add the element from list
        if (head1) {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }

        // Then add the element from the second list
        if (head2) {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }

    // Assign the head of the new list to head pointer
    *head = (*head)->next;
}

// Driver program
int main() {
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    std::cout << "Original List: ";
    printList(head);

    rearrange(&head);

    std::cout << "Rearranged List: ";
    printList(head);

    return 0;
}

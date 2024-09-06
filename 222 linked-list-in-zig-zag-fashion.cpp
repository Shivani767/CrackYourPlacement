#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to distribute nodes in zigzag fashion
void zigZagList(Node* head) {
    bool flag = true; // alternate between < and > relations

    Node* current = head;
    while (current->next != NULL) {
        if (flag) { // expect <
            if (current->data > current->next->data) {
                swap(current->data, current->next->data);
            }
        } else { // expect >
            if (current->data < current->next->data) {
                swap(current->data, current->next->data);
            }
        }

        current = current->next;
        flag = !flag; // flip flag for reverse checking
    }
}

// Function to push a new node to the beginning of the list
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to print the linked list
void printList(Node* node) {
    while (node != NULL) {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // create a list 4 -> 3 -> 7 -> 8 -> 6 -> 2 -> 1
    push(&head, 1);
    push(&head, 2);
    push(&head, 6);
    push(&head, 8);
    push(&head, 7);
    push(&head, 3);
    push(&head, 4);

    printf("Given linked list:\n");
    printList(head);

    zigZagList(head);

    printf("Zig Zag Linked list:\n");
    printList(head);

    return 0;
}

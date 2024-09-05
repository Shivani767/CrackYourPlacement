#include <iostream>

// Class for a node of deque
class DQueNode {
public:
    int value;
    DQueNode* next;
    DQueNode* prev;

    // Constructor
    DQueNode(int val) : value(val), next(nullptr), prev(nullptr) {}
};

// Implementation of deque class
class Deque {
private:
    // Pointers to head and tail of deque
    DQueNode* head;
    DQueNode* tail;

public:
    // Constructor
    Deque() : head(nullptr), tail(nullptr) {}

    // Destructor
    ~Deque() {
        while (head) {
            DQueNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // If list is empty
    bool isEmpty() const {
        return head == nullptr;
    }

    // Count the number of nodes in list
    int size() const {
        if (isEmpty()) {
            return 0;
        }

        int len = 0;
        DQueNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    // Insert at the first position
    void insertFirst(int element) {
        DQueNode* temp = new DQueNode(element);

        if (head == nullptr) {
            head = tail = temp;
        } else {
            head->prev = temp;
            temp->next = head;
            head = temp;
        }
    }

    // Insert at last position of deque
    void insertLast(int element) {
        DQueNode* temp = new DQueNode(element);

        if (head == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    // Remove element at the first position
    void removeFirst() {
        if (isEmpty()) {
            std::cout << "List is Empty" << std::endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            DQueNode* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }

    // Remove element at the last position
    void removeLast() {
        if (isEmpty()) {
            std::cout << "List is Empty" << std::endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            DQueNode* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }

    // Displays the elements in deque
    void display() const {
        if (isEmpty()) {
            std::cout << "List is Empty" << std::endl;
            return;
        }

        DQueNode* temp = head;
        while (temp) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

// Class to implement stack using Deque
class Stack {
private:
    Deque d;

public:
    // Push to push element at top of stack
    // using insert at last function of deque
    void push(int element) {
        d.insertLast(element);
    }

    // Returns size
    int size() const {
        return d.size();
    }

    // Pop to remove element at top of stack
    // using remove at last function of deque
    void pop() {
        d.removeLast();
    }

    // Display
    void display() const {
        d.display();
    }
};

// Class to implement queue using deque
class Queue {
private:
    Deque d;

public:
    // Enqueue to insert element at last
    // using insert at last function of deque
    void enqueue(int element) {
        d.insertLast(element);
    }

    // Dequeue to remove element from first
    // using remove at first function of deque
    void dequeue() {
        d.removeFirst();
    }

    // Display
    void display() const {
        d.display();
    }

    // Size
    int size() const {
        return d.size();
    }
};

// Driver Code
int main() {
    // Object of Stack
    Stack stk;

    // Push 7 and 8 at top of stack
    stk.push(7);
    stk.push(8);
    std::cout << "Stack: ";
    stk.display();

    // Pop an element
    stk.pop();
    std::cout << "Stack: ";
    stk.display();

    // Object of Queue

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        
        unordered_map<Node*, Node*> map;
        Node* dummy = new Node(0);
        Node* current = dummy;
        Node* original = head;
        
        // First pass: create new nodes and store them in the map
        while (original != nullptr) {
            Node* newNode = new Node(original->val);
            map[original] = newNode;
            current->next = newNode;
            current = current->next;
            original = original->next;
        }
        
        // Second pass: set the next and random pointers
        original = head;
        current = dummy->next;
        while (original != nullptr) {
            if (original->next != nullptr) {
                current->next = map[original->next];
            }
            if (original->random != nullptr) {
                current->random = map[original->random];
            }
            original = original->next;
            current = current->next;
        }
        
        return dummy->next;
    }
};

// This function should return head to the DLL
class Solution {
  public:
  
  void solve(Node* root, Node*& head, Node*& tail){
      if(root == NULL)
      {
          return;
      }
      
      // LNR
      solve(root->left, head, tail );
      // lwft linklist is created
      // now we have to connect root
      if(tail != NULL){
            tail-> right = root;
          root ->left = tail;
          tail = root;
      }else{
        
        head = root;
        tail = root;
      }
      // solve right part
      solve(root->right, head, tail);
  }
  
  
    Node* bToDLL(Node* root) {
      Node* head = NULL;
      Node* tail = NULL;
      solve(root,head, tail);
      return head;
    }
};

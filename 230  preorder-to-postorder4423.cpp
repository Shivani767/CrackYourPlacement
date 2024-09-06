/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/

class Solution {
  public:
    // Function that constructs BST from its preorder traversal.
    Node* temp(int pre[],int start,int end)
    {
        if(start>=end)return NULL;
        Node* root=newNode(pre[start]);
        int i=start+1;
        while(i<end&&pre[i]<pre[start])
        i++;
        root->left=temp(pre,start+1,i);
        root->right=temp(pre,i,end);
        return root;
        }
    Node* Bst(int pre[], int size) {
        // code here
        int start=0;
        return temp(pre,start,size);
    }
};

/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return the root of the new binary tree formed
struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
     stack<Node*> s;
    Node *root=new Node(pre[0]);
    s.push(root);
    for(int i=1;i<n;i++)
    {
        Node *temp=s.top();
        s.pop();
        Node *newnode=new Node(pre[i]);
        if(!temp->left) temp->left=newnode;
        else if(!temp->right) temp->right=newnode;
        if(!temp->left||!temp->right) s.push(temp);
        if(preLN[i]=='N') s.push(newnode);
    }
    return root;
}

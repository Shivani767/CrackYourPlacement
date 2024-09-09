


/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function

float solve(Node*root,int&n)
{
    int oddi=(n+1)/2,oddv=-1;
    int even1i=n/2+1,even1v=-1;
    int even2i=n/2,even2v=-1;
    Node*curr=root;
    int i=0;
    while(curr)
    {
        if(curr->left==nullptr)
        {
            i++;
            if(oddi==i)oddv=curr->data;
            if(even1i==i)even1v=curr->data;
            if(even2i==i)even2v=curr->data;
            curr=curr->right;
        }
        else
        {
            Node*pred=curr->left;
            while(pred->right!=curr && pred->right)
            {
                pred=pred->right;
            }
        
        if(pred->right==nullptr)
        {
            pred->right=curr;
            curr=curr->left;
        }
        else
        {
            pred->right=nullptr;
            i++;
             if(oddi==i)oddv=curr->data;
            if(even1i==i)even1v=curr->data;
            if(even2i==i)even2v=curr->data;
            curr=curr->right;
        }
    }
    }
    float ans=0.0;
    if(n&1)
    {
        ans=oddv;
    }
    else
    {
        ans=(even1v+even2v)/2.0;
    }
    return ans;
}

int findNodeCount(Node*root)
{
    if(!root)
    return 0;
    int ans=1;
    ans+=findNodeCount(root->left)+findNodeCount(root->right);
    return ans;
}
// Function should return median of the BST
float findMedian(struct Node *root)
{
      //Code here
      int n=findNodeCount(root);
      return solve(root,n);
}

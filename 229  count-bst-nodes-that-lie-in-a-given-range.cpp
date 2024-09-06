class Solution{
public:
void ct(Node* root,int l,int  h,int &ans)
{
    if(root==NULL)
    return ;
    if(root->data>=l&&root->data<=h)
    {ans++;
    ct(root->left,l,h,ans);
    ct(root->right,l,h,ans);}
    else if(root->data<l)
    ct(root->right,l,h,ans);
    else 
    ct(root->left,l,h,ans);
}
    int getCount(Node *root, int l, int h)
    {
      // your code goes here 
      int ans=0;
      ct(root,l,h,ans);
      return ans;
    }
};

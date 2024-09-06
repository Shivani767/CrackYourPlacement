class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* findlca(int a,int b,Node* root){
        if(root==NULL||root->data==a||root->data==b) return root;
        Node* leftres=findlca(a,b,root->left);
        Node* rightres=findlca(a,b,root->right);
        if(leftres!=NULL&&rightres!=NULL) return root;
        if(leftres) return leftres;
        if(rightres) return rightres;
        return NULL;
    }
    void findlen(Node* root,int a,int temp,int &len){
        if(root==NULL)  return;
        if(root->data==a){
            len=min(len,temp);
            return;
        }
        findlen(root->left,a,temp+1,len);
        findlen(root->right,a,temp+1,len);
        
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* temp=root;
        Node* lca=findlca(a,b,temp);
        int len1=INT_MAX,t=0;
        findlen(lca,a,t,len1);
        t=0;
        int len2=INT_MAX;
        findlen(lca,b,t,len2);
        return len1+len2;
    }
};

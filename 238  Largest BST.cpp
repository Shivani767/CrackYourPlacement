class Box{
  public:
  bool validBST;
  int BSTsize;
  int maxVal;
  int minVal;
  Box()
  {
    validBST=1;
    BSTsize=0;
    maxVal = INT_MIN;
    minVal = INT_MAX;
  }
};


class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    Box* solve(Node* root, int &ans)
    {
        if(root==nullptr)
        {
            return new Box();
        }
        
        Box* leftHead = solve(root->left, ans);
        Box* rightHead = solve(root->right, ans);
        if(leftHead->validBST==1 && rightHead->validBST==1 && 
        root->data> leftHead->maxVal && root->data<rightHead->minVal)
        {
            Box* head = new Box();
            head->BSTsize = 1+leftHead->BSTsize+rightHead->BSTsize;
            ans = max(ans, head->BSTsize);
            head->minVal =min(leftHead->minVal,root->data);
            head->maxVal = max(rightHead->maxVal,root->data);
            return head;
        }
        else
        {
            leftHead->validBST=0;
            return leftHead;
        }
    }
    
    
    int largestBst(Node *root)
    {
    	int maxSize = 1;
    	solve(root,maxSize);
    	return maxSize;
    }
};

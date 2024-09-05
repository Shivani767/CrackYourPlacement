struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        vector<int> v;
        Node *t = root;
        while(t)
        {
            v.push_back(t->data);
            Node *tb = t->bottom;
            while(tb)
            {
                v.push_back(tb->data);
                tb=tb->bottom;
            }
            t=t->next;
        }
        
        sort(v.begin(),v.end());
        // for(int i:v)
        // {
        //     cout << v[i] << " ";
        // }
        // cout << endl;
        
        Node *a = new Node(0);
        Node *ans = a;
        
        for(int i=0;i<v.size();i++)
        {
            Node *temp = new Node(v[i]);
            ans->bottom = temp;
            ans = ans->bottom;
        }
        return a->bottom;
    }
};

// User function Template for C++
class node{
    public:
    vector<node*> nxt; 
    bool end; 
    
    node(){
        nxt.resize(26,NULL);
        end = false;
    }
};

void add(node* head, string s){
    for(auto e:s){
        if(!head->nxt[e-'a']){
            node* t=new node();
            head->nxt[e-'a']=t;
        }
        head = head->nxt[e-'a'];
    }
    head->end = true;
}

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        // node* head = new node();
        // for(auto e : contact){
        //     add(head,e);
        // }
        // vector<vector<string>>> ans; 
        
        // for(int i =0;i<s.size();i++){
        //     vector<string> dum;
        //     f(head,i,s,dum);
        //     ans.push_back(dum);
        // }
        set<string> avail ;
        vector<vector<string>> ans; 
        
        for(int i =0;i<n;i++)avail.insert(contact[i]);
        
        for(int i =0;i<s.size();i++){
            vector<string> cval;
            vector<string> rem; 
            for(auto e : avail){
                    // cout<<e<<" "<<i<<endl;
                if(e[i]==s[i]){
                    cval.push_back(e);
                }else {
                   
                    rem.push_back(e);
                    // cout<<e<<" fuck "<<i<<endl;
                }
            }
            for(auto e : rem) avail.erase(e);
            if(cval.size()==0)cval={"0"};
            ans.push_back(cval);
        }
        return ans;
        
    }
};


/* Multiply contents of two linked lists */
class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long MOD=1000000007;
        std::vector<int>v1,v2;
        
        Node *temp1=first;
        while(temp1!=NULL){
            v1.push_back(temp1->data);
            temp1=temp1->next;
        }
        Node *temp2=second;
        while(temp2!=NULL){
            v2.push_back(temp2->data);
            temp2=temp2->next;
        }
        
        long long num1=0;
        for(int digit:v1){
            num1=(num1*10+digit)%MOD;
        }
        
        long long num2=0;
        for(int digit:v2){
            num2=(num2*10 +digit)%MOD;
        }
        
        long long result=(num1*num2)%MOD;
        return result;
        
        
        
    }
};

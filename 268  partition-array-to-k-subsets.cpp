class Solution{
  public:
    bool isKPartitionPossible(int a[], int n, int k)
    {
int sum =0;
for(int i =0 ; i< n ; i++){
    sum += a[i];
}
if(sum % k != 0){
    return false;
}

bool visited[n] = {false};
return canpartition(a,n , visited , k , 0 , 0 , sum/k);
    }
    
bool canpartition(int a[] , int n ,bool visited[] , int  k , int currentsum, int start , int target){
    if(k ==0) return true;
    if(currentsum == target){
        return canpartition(a, n , visited , k -1 , 0 , 0 , target);
    }
    
    for(int i = start; i < n ; i++){
        if(!visited[i] && currentsum + a[i] <= target){
            visited[i] = true;
            if(canpartition(a, n , visited , k , currentsum + a[i], i+1 ,  target)){
                return true;
            }
            visited[i] = false;
        }
    }
    
    return false;
    
}
};

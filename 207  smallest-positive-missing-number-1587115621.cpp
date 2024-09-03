class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
      for(int i=0;i<n;i++){
          if(arr[i]!=i+1){
              while(arr[i]<=n&&arr[i]>0&&arr[i]!=i+1&&(arr[i]!=arr[arr[i]-1])){
                   swap(arr[i],arr[arr[i]-1]);
              }
          }
      }
      int cr=1;
      int ans=n+1;
      for(int i=0;i<n;i++){
          if(arr[i]!=i+1){
              return i+1;
          }
      }
      return ans;
    } 
};

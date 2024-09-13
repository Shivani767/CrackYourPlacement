// User function Template for C++

class Solution{
public:
    bool solveSO(int N, int arr[], int tar)
    {
       
        vector<int> curr(tar+1,0);
        vector<int> next(tar+1,0);
        
       
        
            next[0] = 1;
            // curr[0] = 1;
         
        for( int i=N-1; i>=0; i--)
        {
            for(int j=1; j<=tar; j++)
            {
                bool inc =0;
                
                if(j-arr[i] >= 0)
                    inc = next[j-arr[i]];
                    
                    bool exc = next[j];
                    
                     curr[j] = inc | exc;
            }
            next = curr;
        }
        return next[tar];
    }


    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0; i<N; i++)
        {
            sum += arr[i];
        }
        
        if(sum & 1)     //for odd sum.
            return 0;
            
        int tar = sum/2;
            
        // vector<vector<int>> dp(tar+1,vector<int>(N,-1));
        
        // return solveMem(N,arr,tar,0,dp);
        //return solveTab(N,arr,tar);
        
        return solveSO(N,arr,tar);
    }
};

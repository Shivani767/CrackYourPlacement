/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        
        vector<pair<int,int>>v;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,arr[i].dead);
            v.push_back({arr[i].profit,arr[i].dead});
        }
        vector<int>visited(maxi+1,-1);
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        int ans=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            int timee=v[i].second;
            int p=v[i].first;
            for(int j=timee;j>=1;j--)
            {
                if(visited[j]==-1)
                {
                    visited[j]=1;
                    ans+=p;
                    count++;
                    break;
                }
            }
        }
        vector<int>a;
        a.push_back(count);
        a.push_back(ans);
        return a;
    } 
};

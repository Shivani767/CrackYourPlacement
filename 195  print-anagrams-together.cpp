
class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& v) {
        //code here
        
        vector<vector<string>>res;
        int curr=0;
        unordered_map<string,int>mp;
        
        for(int i=0;i<v.size();i++)
        {
            string s=v[i];
            sort(s.begin(),s.end());
            if(mp.count(s)<1)
            { 
                mp[s]=curr;
                curr++;
                vector<string> temp;
                temp.push_back(v[i]);
                res.push_back(temp);
            }
            else
            {
                int idx =mp[s];
                res[idx].push_back(v[i]);
            }
        }
        /*for(int i=0;i<res.size();i++)
        {
             sort(res[i].begin(),res[i].end());
        }
        */
        return res;
    }
};

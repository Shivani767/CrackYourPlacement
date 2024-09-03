Class Solution {
public:
    bool isPossible(int k, vector<int> &arr1, vector<int> &arr2) {
        // Your code goes here
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end(),greater<int>());
        
        if(arr1[arr1.size()-1] + arr2[0] <=k) return false;
        
        for(int i=0;i<arr1.size();i++){
            
            if(arr1[i]+arr2[i] < k) return false;
        }
        
        return true;
        
    }
    
    
};

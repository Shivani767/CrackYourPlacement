class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
       int sz = colors.size(), totalRemovalTime = 0, prevSafeColorIndx = 0;
       for(int indx = 1; indx < sz; indx++){
           char currColor = colors[indx], prevSafeColor = colors[prevSafeColorIndx];
           if(currColor == prevSafeColor){
               if(neededTime[indx] > neededTime[prevSafeColorIndx]){
                   totalRemovalTime += neededTime[prevSafeColorIndx];
                   prevSafeColorIndx = indx;
               }else{
                   totalRemovalTime += neededTime[indx];
               }
           }else prevSafeColorIndx = indx;
       }
       return totalRemovalTime;
    }
};

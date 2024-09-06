class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        
        int n = mat.size();
        int mayCele = -1;
        
        
        int top = 0 , down = n-1;
        while(top < down){
            if(mat[top][down]) top++;
            else if(mat[down][top]) down--;
            else{
                top++,down--;
            }
        }
        
        mayCele = top;
        
        for(int i = 0 ; i < n ; i++){
            if(i == mayCele) continue;
            if(mat[mayCele][i] != 0) return -1;
            if(mat[i][mayCele] != 1) return -1;
        }
        
        return mayCele;
    }
};

class Solution
{
    public:
    //Function to find minimum time required to rot all oranges.
    
    int recursive_way(vector<vector<int>> &grid,vector<pair<pair<int,int>,int>> &initial_rotten_oranges,int *time){
        vector<pair<pair<int,int>,int>> rotten_oranges_level;
        int flag = 0; //to check whether after unit time any fresh oranges get rotten or not
        int n = grid.size();
        int m = grid[0].size();
        
        
        for(auto it : initial_rotten_oranges){
            int i = it.first.first;
            int j = it.first.second;
            //this if else condition is true but it fails when it is a scalar or row matrix and column matrix according to me
            //code for special cases
            if(n == 1 || m == 1){
                if(n == 1 && m == 1){
                    return 0;
                }
                else if(n == 1){
                    if(i == 0 && j == 0){
                        if(grid[i][j+1] == 1 ){
                            grid[i][j+1] = 2;
                            flag++;
                            rotten_oranges_level.push_back({{i,j+1},*time + 1});
                        }
                    }
                    if(i == 0 && j == m-1){
                        if(grid[i][j-1] == 1 ){
                            grid[i][j-1] = 2;
                            flag++;
                            rotten_oranges_level.push_back({{i,j-1},*time + 1});
                        }
                    }
                    if(j !=0 && j != m-1){
                        if(grid[i][j+1] == 1 ){
                            grid[i][j+1] = 2;
                            flag++;
                            rotten_oranges_level.push_back({{i,j+1},*time + 1});
                        }
                        if(grid[i][j-1] == 1 ){
                            grid[i][j-1] = 2;
                            flag++;
                            rotten_oranges_level.push_back({{i,j-1},*time + 1});
                        }
                    }
                }
                else{
                    if(i == 0 && j == 0){
                        if(grid[i+1][j] == 1 ){
                            grid[i+1][j] = 2;
                            flag++;
                            rotten_oranges_level.push_back({{i+1,j},*time + 1});
                        }
                    }
                    if(i == 0 && j == m-1){
                        if(grid[i-1][j] == 1 ){
                            grid[i-1][j] = 2;
                            flag++;
                            rotten_oranges_level.push_back({{i+1,j},*time + 1});
                        }
                    }
                    if(j !=0 && j != m-1){
                        if(grid[i+1][j] == 1 ){
                            grid[i+1][j] = 2;
                            flag++;
                            rotten_oranges_level.push_back({{i+1,j},*time + 1});
                        }
                        if(grid[i-1][j] == 1 ){
                            grid[i-1][j] = 2;
                            flag++;
                            rotten_oranges_level.push_back({{i+1,j},*time + 1});
                        }
                    }
                }
                continue;
            }
            if(i == 0 && j == 0){
                if(grid[i+1][j] == 1 ){
                    grid[i+1][j] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i+1,j},*time + 1});
                    
                }
                if(grid[i][j+1] == 1 ){
                    grid[i][j+1] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i,j+1},*time +  1});

                }
            }
            if(i == 0 && j == m-1){
                if(grid[i+1][j] == 1 ){
                    grid[i+1][j] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i+1,j},*time + 1});

                    
                }
                if(grid[i][j-1] == 1 ){
                    grid[i][j-1] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i,j-1},*time + 1});

                }
            }
            if(i == n-1 && j == 0){
                if(grid[i-1][j] == 1 ){
                    grid[i-1][j] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i-1,j},*time + 1});

                    
                }
                if(grid[i][j+1] == 1 ){
                    grid[i][j+1] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i,j+1},*time + 1});

                }
            }
            if(i == n-1 && j == m-1){
                if(grid[i-1][j] == 1 ){
                    grid[i-1][j] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i-1,j},*time + 1});

                    
                }
                if(grid[i][j-1] == 1 ){
                    grid[i][j-1] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i,j-1},*time + 1});

                }
            }
            if(i == 0 && j != 0 && j != m-1 ){
                if(grid[i][j-1] == 1){
                    grid[i][j-1] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i,j-1},*time + 1});
                }
                if(grid[i+1][j] == 1){
                    grid[i+1][j] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i+1,j},*time + 1});
                }
                if(grid[i][j+1] == 1){
                    grid[i][j+1] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i,j+1},*time + 1});
                }
            }
            if(i == n-1 && j != 0 && j != m-1){
                if(grid[i-1][j] == 1){
                    grid[i-1][j] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i-1,j},*time + 1});
                }
                if(grid[i][j+1] == 1){
                    grid[i][j+1] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i,j+1},*time + 1});
                }
                if(grid[i][j-1] == 1){
                    grid[i][j-1] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i,j-1},*time + 1});
                }
            }
            if(j == 0 && i != 0 && i != n-1){
                if(grid[i-1][j] == 1){
                    grid[i-1][j] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i-1,j},*time + 1});
                }
                if(grid[i][j+1] == 1){
                    grid[i][j+1] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i,j+1},*time + 1});
                }
                if(grid[i+1][j] == 1){
                    grid[i+1][j] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i+1,j},*time + 1});
                }
            }
            if(j == m-1 && i != 0 && i != n-1){
                if(grid[i-1][j] == 1){
                    grid[i-1][j] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i-1,j},*time + 1});
                }
                if(grid[i][j-1] == 1){
                    grid[i][j-1] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i,j-1},*time + 1});
                }
                if(grid[i+1][j] == 1){
                    grid[i+1][j] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i+1,j},*time + 1});
                }
            }
            if(i != 0 && i != n-1 && j != 0 && j != m-1){
                if(grid[i-1][j] == 1){
                    grid[i-1][j] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i-1,j},*time + 1});
                }
                if(grid[i][j-1] == 1){
                    grid[i][j-1] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i,j-1},*time + 1});
                }
                if(grid[i+1][j] == 1){
                    grid[i+1][j] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i+1,j},*time + 1});
                }
                if(grid[i][j+1] == 1){
                    grid[i][j+1] = 2;
                    flag++;
                    rotten_oranges_level.push_back({{i,j+1},*time + 1});
                }
            }
        }
        if(!flag){
            //means now no fresh oranges will get rot
            //but there is one more constraint in this question that if we have left any fresh oranges then we have to return
            //-1
            for(int i = 0;i<n;i++){
                for(int j = 0; j <m;j++){
                    if(grid[i][j] == 1){
                        return -1;
                    }
                }
            }
            //if all fresh oranges available got rotten then we are returning the time
            return *time;
        }
        else{
            //there are some fresh oranges which got rotten which are stored in rotten_oranges_level
            //and this will now rot again fresh oranges at next unit of time
            *time = *time + 1;
            return recursive_way(grid,rotten_oranges_level,time);
                    
            }
        }
    
    

    int orangesRotting(vector<vector<int>>& grid) {
        // at first i have to find starting index of rotten oranges at time t = 0
        int n = grid.size(); // number of rows
        int m = grid[0].size(); // number of columns
        //we will store the index of rotten oranges first
        //we will also create a time variable to track time
        int initial_time = 0;
        int *time = &initial_time;
        vector<pair<pair<int,int>,int>> initial_rotten_oranges;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    initial_rotten_oranges.push_back({{i,j},*time});
                }
            }
        }
        //debugging line 1
        /*for(auto it : initial_rotten_oranges){
            cout << it.first.first <<","<<it.first.second<<","<<it.second;
            cout << " ";
        }*/
        //now to calculate minimum possible time to rot all oranges taking help of bfs
        //will apply bfs with considering next level neighbours at up,right,left,down
        return recursive_way(grid,initial_rotten_oranges,time);
    }
};

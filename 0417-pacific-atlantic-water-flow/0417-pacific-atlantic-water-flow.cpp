class Solution {
public:
   vector<vector<int>> directions = {{1,0} , {-1,0}, {0,1}, {0,-1}};

   void dfs(int r, int c , vector<vector<int>> & heights, vector<vector<bool>> & visited) {
    visited[r][c] = true;

    int m= heights.size();
    int n = heights[0].size();

    for(auto &dir: directions) {
        int dr = r + dir[0];
        int dc= c + dir[1];

        if(dr <0 || dr >=m || dc <0 || dc >=n)  continue;

        if(visited[dr][dc])
        continue;

        //Reverse flow conditions 
        if(heights[dr][dc] < heights[r][c]) continue;
        dfs(dr, dc, heights, visited);
    }
   }



    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>>atlantic(m,vector<bool>(n, false));

        //left and right borders: pacific ocean 
        for(int i=0; i<m; i++) {
            dfs(i, 0, heights, pacific);
            dfs(i, n-1, heights, atlantic);
        }
        //Top and Bottom borders: atlantic ocean
        for(int j=0; j<n; j++ ) {
            dfs(0, j, heights, pacific);
            dfs(m-1, j, heights, atlantic);
        }

        vector<vector<int>> result;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n;j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i,j});
                }
            }
        }

        return result;

    }


};
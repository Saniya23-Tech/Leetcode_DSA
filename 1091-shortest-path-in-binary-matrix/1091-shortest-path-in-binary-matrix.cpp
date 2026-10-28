class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        //if start or end is blocked having 1
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
        return -1;

        queue<pair<pair<int, int> , int>> q; //row, column, pathcount
        q.push({{0,0}, 1});

        grid[0][0] = 1; //marking visited 

        int dir_r[8] = {-1,-1,-1,0,0,1,1,1};
        int dir_c[8] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty()) {
            int row = q.front().first.first;
            int column = q.front().first.second;
            int pathCount = q.front().second;

            q.pop();

            //until the destination reached
            if(row == n-1 && column == n-1)
            return pathCount;

            for(int i=0; i<8; i++) {
                int r = row+dir_r[i];
                int c= column+dir_c[i];

                if(r >=0 && r <n && c>=0 && c <n && grid[r][c] == 0) {
                    q.push({{r,c}, pathCount + 1});

                    grid[r][c] = 1;
                }
            }
        }
        return -1;
        
    }
};
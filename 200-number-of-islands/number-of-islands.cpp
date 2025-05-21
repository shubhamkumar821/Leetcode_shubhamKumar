class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<int> dx={1,0,-1,0};
        vector<int> dy={0,1,0,-1};
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> st(m,vector<bool>(n,false));
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
           if(!st[i][j] && grid[i][j]=='1')
           {
              cnt++;
              dfs({i,j},st,dx,dy,grid,m,n);
           }
            }
        }
        return cnt;
    }
    void dfs(pair<int,int> k,vector<vector<bool>>& st,vector<int>&dx,vector<int>&dy,vector<vector<char>> & grid,int m,int n)
    {
        int a=k.first,b=k.second;
        st[a][b]=true;
        for(int i=0;i<4;i++)
        {
            if(check( a+dx[i],b+dy[i],m,n))
            {
              if(!st[a+dx[i]][b+dy[i]] && grid[a+dx[i]][b+dy[i]]=='1')
              {
                  dfs({a+dx[i],b+dy[i]},st,dx,dy,grid,m,n);
              }
            }
        }

    }
    bool check(int x,int y,int m,int n)
    {
        if(x<0||x>=m || y<0 || y>=n)
        {
            return false;
        }
        else 
        {
          return true;
        }

    }
};
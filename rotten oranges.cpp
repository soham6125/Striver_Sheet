// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& arr) {
        int ans = -1;
        int r = arr.size(), c = arr[0].size();
        int cnt = 0;
        queue<pair<int,int>> q;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(arr[i][j] == 1) cnt++;
                else if(arr[i][j] == 2) q.push({i,j});
            }
        }
        if(cnt == 0) return 0;
        while(!q.empty())
        {
            ans++;
            int sz = q.size();
            while(sz--)
            {
                auto p = q.front();
                q.pop();
                int x = p.first, y = p.second;            
                arr[x][y] = -1;
                if(x-1>=0 and arr[x-1][y] == 1)
                {
                    arr[x-1][y] = 2;
                    q.push({x-1,y});
                    cnt--;
                }
                if(x<r-1 and arr[x+1][y] == 1)
                {
                    arr[x+1][y] = 2;
                    q.push({x+1,y});
                    cnt--;
                }
                if(y>0 and arr[x][y-1] == 1)
                {
                    arr[x][y-1] = 2;
                    q.push({x,y-1});
                    cnt--;
                }
                if(y<c-1 and arr[x][y+1] == 1)
                {
                    arr[x][y+1] = 2;
                    q.push({x,y+1});
                    cnt--;
                }
            }
        }              
        if(cnt == 0) return ans;
        else return -1;
    }
};


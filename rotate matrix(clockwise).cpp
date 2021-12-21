class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<=i;j++)
            {
                swap(arr[i][j],arr[j][i]);
            }
        }
        int n=arr.size(), m=arr[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m/2;j++)
            {
                swap(arr[i][j],arr[i][m-1-j]);
            }
        }
    }
};
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int, int> row, col;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++ ){
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == 0){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                if(row[r] > 0 or col[c] > 0){
                    matrix[r][c] = 0;
                }
            }
        }
    }
};
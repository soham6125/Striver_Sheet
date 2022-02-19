// rotate anticlockwise

class Solution {
public:
    void transpose(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        for(int i=0; i<n; i++) {
            for(int j=i; j<m; j++) {
                swap(arr[i][j], arr[j][i]);
            }
        }
    }

    void rotate(vector<vector<int>>& arr) {
        for(int i=0; i<arr.size(); i++){
            reverse(arr[i].begin(), arr[i].end());
        }
        transpose(arr);
    }
};

// rotate clockwise

class Solution {
public:
    void transpose(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        for(int i=0; i<n; i++) {
            for(int j=i; j<m; j++) {
                swap(arr[i][j], arr[j][i]);
            }
        }
    }

    void rotate(vector<vector<int>>& arr) {
        int n = arr.size();
        for(int i=0; i<arr.size()/2; i++){
            swap(arr[i], arr[n-i-1]);
        }
        transpose(arr);
    }
};
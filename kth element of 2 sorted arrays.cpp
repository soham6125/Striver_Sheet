class Solution {
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int v[n+m] = {0};
        int i = 0, j = 0;
        int cnt = 0;
        while(i < n and j < m) {
            if(arr1[i] <= arr2[j]) {
                v[cnt] = arr1[i];
                i++; cnt++;
            }
            else {
                v[cnt] = arr2[j];
                j++; cnt++;
            }
            if(cnt == k) return v[cnt-1];
        }
        while(i < n) {
            v[cnt] = arr1[i];
            i++; cnt++;
            if(cnt == k) return v[cnt-1];
        }
        while(j < m) {
            v[cnt] = arr2[j];
            j++; cnt++;
            if(cnt == k) return v[cnt-1];
        }
        return -1;
    }
};
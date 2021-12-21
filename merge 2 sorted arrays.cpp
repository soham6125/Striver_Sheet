void merge(vector<int> arr1, vector<int> arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    int i = 0, j = 0, k = n - 1;
    while (i <= k and j < m) 
    {
        if (arr1[i] < arr2[j])
            i++;
        else {
            swap(arr2[j++], arr1[k--]);
        }
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}
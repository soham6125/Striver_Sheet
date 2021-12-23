bool subset_sum(int arr[],int sum,int n)
{
	bool dp[n+1][sum+1] = {-1};
	int i,j;
    for(i=0; i<=sum; i++) dp[0][i] = false;
    for(i=0; i<=n; i++) dp[i][0] = true;
	for(i=1; i<n+1; i++)
	{
		for(j=1; j<sum+1; j++)
		{
			if(arr[i-1] > j)
			{
				dp[i][j] = dp[i-1][j];
			}
			else if(arr[i-1] <= j)
			{
				dp[i][j]= dp[i-1][j-arr[i-1]] || dp[i-1][j];
			}
		}
	}
	return dp[n][sum];
}
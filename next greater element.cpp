vector<int> next_greater(vector<int> &arr) {
    stack<ll> st;
	int n = arr.size();
    vector<int> res(n); 
    for(ll i=n-1; i>=0; i--)  
    { 
        while (!st.empty() and st.top() <= arr[i]) 
            st.pop(); 
        if (st.empty()) res[i] = -1;          
        else  res[i] = st.top();         
        st.push(arr[i]); 
    } 
    return res;
}
// https://leetcode.com/problems/valid-parentheses/

bool valid_parenthesis(string s) {
    stack<char> st;
    int n = s.length();
    for(int i=0 ;i<n; i++) {
        if(s[i] == '(') st.push(s[i]);
        else {
            if(st.empty()) st.push(s[i]);
            else {
                if(st.top() == '(') st.pop();
                else st.push(s[i]);
            }
        }
    }
    return st.empty();
}
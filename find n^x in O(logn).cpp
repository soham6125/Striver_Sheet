void power(int n, int x) {
    if(x == 0) return 1;
    if(x == 1) return n;
    if(n%2) {
        int tmp = power(n, x/2);
        tmp = tmp * tmp * n;
        return tmp;
    }
    else {
        int tmp = power(n, x/2);
        tmp = tmp * tmp;
        return tmp;
    }
}
int numDecodings(char* s) {
    int n = strlen(s);
    if (n == 0 || s[0] == '0') return 0;

    int prev = 1;
    int sum = 1;

    for (int i = 1; i < n; i++) {
        int temp = 0;
        
        if (s[i] != '0') {
            temp += sum;
        }

        int val = (s[i-1] - '0') * 10 + (s[i] - '0');
        if (val >= 10 && val <= 26) {
            temp += prev;
        }

        prev = sum;
        sum = temp;

        if (sum == 0) return 0;
    }

    return sum;
}

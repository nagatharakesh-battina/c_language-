int myAtoi(char* s) {
    int i = 0;
    
    // 1. Skip leading whitespaces
    while (s[i] == ' ') {
        i++;
    }

    // 2. Check sign
    int sign = 1;
    if (s[i] == '+' || s[i] == '-') {
        if (s[i] == '-') sign = -1;
        i++;
    }

    // 3. Convert digits
    long result = 0;  // use long to detect overflow

    while (s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';

        // 4. Check overflow BEFORE multiplying
        if (result > (LONG_MAX / 10) || 
           (result == LONG_MAX / 10 && digit > 7)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    return (int)(sign * result);
}

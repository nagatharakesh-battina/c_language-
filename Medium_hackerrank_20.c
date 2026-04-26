char* convert(char* s, int numRows) {
    int len = strlen(s);
    if (numRows == 1 || numRows >= len) return s;

    char* result = (char*)malloc((len + 1) * sizeof(char));
    int k = 0;
    int cycleLen = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j + i < len; j += cycleLen) {
            // First character in the cycle for this row
            result[k++] = s[j + i];
            
            // Second character in the cycle (only for middle rows)
            if (i != 0 && i != numRows - 1 && j + cycleLen - i < len) {
                result[k++] = s[j + cycleLen - i];
            }
        }
    }
    result[k] = '\0';
    return result;
}

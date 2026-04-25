char* multiply(char* num1, char* num2) {
if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) return "0";

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int totalLen = len1 + len2;
    int* res = (int*)calloc(totalLen, sizeof(int));

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + res[i + j + 1];

            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }

    char* result = (char*)malloc((totalLen + 1) * sizeof(char));
    int k = 0, i = 0;
    while (i < totalLen && res[i] == 0) i++; // Skip leading zeros
    while (i < totalLen) result[k++] = res[i++] + '0';
    
    result[k] = '\0';
    free(res);
    return result;
}

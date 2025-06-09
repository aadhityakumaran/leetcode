#include <limits.h>

int positiveAtoi(char* s, int i) {
    int num = 0;
    while ('0' <= s[i] && s[i] <= '9') {
        if (num > (INT_MAX / 10)) return INT_MAX;
        int digit = s[i] - '0';
        num *= 10;
        if (num > INT_MAX - digit) return INT_MAX;
        num += digit;
        i++;
    }
    return num;
}

int negativeAtoi(char* s, int i) {
    int num = 0;
    while ('0' <= s[i] && s[i] <= '9') {
        if (num < (INT_MIN / 10)) return INT_MIN;
        int digit = s[i] - '0';
        num *= 10;
        if (num < INT_MIN + digit) return INT_MIN;
        num -= digit;
        i++;
    }
    return num;
}

int myAtoi(char* s) {
    int i = 0;
    while (s[i] == ' ') i++;

    if (s[i] == '+') return positiveAtoi(s, i + 1);
    if (s[i] == '-') return negativeAtoi(s, i + 1);
    return positiveAtoi(s, i);
}

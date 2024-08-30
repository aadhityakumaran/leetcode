#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);

    char a[256] = {0};
    int maxlength = 0;

    int length = 0;

    int left = 0;
    int right = 0;

    while (right < n) {
        if (a[s[right]] == 0) {
            a[s[right]] = 1;
            right++;
            length++;
            if (length > maxlength) maxlength = length;
        } else {
            a[s[left]] = 0;
            left++;
            length--;
        }
    }
    return maxlength;
}
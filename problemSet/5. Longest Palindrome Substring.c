#include <string.h>

int oddSize(char* s, int len, int pos) {
    // Returns the offset from the current position
    int left_marker = pos;
    int right_marker = pos;
    while (1) {
        left_marker--;
        right_marker++;
        if (left_marker < 0 || // If left end too left
            right_marker >= len || // If right end too right
            s[left_marker] != s[right_marker]) {  // If left end and right end not equal
            return pos - left_marker - 1;  // The offset (The -1 since current offset is wrong)
        }
    }
}

int evenSize(char* s, int len, int pos) {
    // Returns the offset from the current position
    int left_marker = pos;
    int right_marker = pos + 1;
    while (1) {
        if (left_marker < 0 || // If left end too left
            right_marker >= len || // If right end too right
            s[left_marker] != s[right_marker]) {  // If left end and right end not equal
            return pos - left_marker - 1;  // The offset (The -1 since current offset is wrong)
        }
        
        left_marker--;
        right_marker++;
    }
}


char* longestPalindrome(char* s) {
    int n = strlen(s);
    int max_odd_offset = -1;
    int max_odd_pos = -1;
    
    int max_even_offset = -1;
    int max_even_pos = -1;

    for (int i=0; i<n; i++) {
        {
            int offset = oddSize(s, n, i);
            if (offset > max_odd_offset){ 
                max_odd_offset = offset;
                max_odd_pos = i;
            }
        }
        {
            int offset = evenSize(s, n, i);
            if (offset > max_even_offset){ 
                max_even_offset = offset;
                max_even_pos = i;
            }
        }
    }

    int odd_len = 2 * max_odd_offset + 1;
    int even_len = 2 * max_even_offset + 2;

    if (odd_len > even_len) {
        (s + max_odd_pos - max_odd_offset)[odd_len] = '\0';
        return s + max_odd_pos - max_odd_offset;
    } else {
        (s + max_even_pos - max_even_offset)[even_len] = '\0';
        return s + max_even_pos - max_even_offset;
    }
    
}
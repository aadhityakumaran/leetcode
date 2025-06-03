#include <string.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);

    if (numRows == 1 || len < numRows) {
        return s;
    }

    char* out = (char*)malloc((len + 1) * sizeof(char));
    
    int sep = 2 * numRows - 2;
    int outdex = 0;

    for (int i = 0; i < len; i += sep) {
        out[outdex++] = s[i];
    }

    for (int row = 1; row < numRows - 1; row++) {
        int val1 = row;
        int val2 = sep - row;
        while (1) {
            if (val1 >= len) {
                break;
            }
            out[outdex++] = s[val1];
            if (val2 >= len) {
                break;
            }
            out[outdex++] = s[val2];

            val1 += sep;
            val2 += sep;
        }
    }

    for (int i = numRows - 1; i < len; i += sep) {
        out[outdex++] = s[i];
    }

    out[outdex++] = '\0';
    return out;
}

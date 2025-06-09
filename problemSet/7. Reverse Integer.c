#include <limits.h>

int reverse(int x) {
    int out = 0;
    while (x) {
        if (out > (INT_MAX / 10) || out < (INT_MIN / 10)) return 0;
        int rem =  x % 10;
        if ((out > 0 && out > INT_MAX - rem) || 
            (out < 0 && out < INT_MIN - rem)) return 0;
        out = out * 10 + rem;
        x /= 10;
    }
    if (out > INT_MAX || out < INT_MIN) return 0;
    return out;
}

#include  "binsearch.h"

bool BinSearch(int32_t* a, int32_t n, int32_t x) {
    int32_t left = 0;
    int32_t right = n;
    int32_t middle;
    while (left != right) {
        middle = (left + right) / 2 + 1;
        if (a[middle] == x) {
            return true;
        }
        
        if (a[middle] < x) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }

    return false;
}

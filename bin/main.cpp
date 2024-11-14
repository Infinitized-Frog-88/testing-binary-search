#include <iostream>
#include <algorithm>
#include <cinttypes>
#include "binsearch.h"

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int32_t n;
    std::cin >> n;
    int32_t* a = new int32_t[n];
    for (int32_t i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a, a + n);
    int32_t x;
    while (std::cin >> x) {
        if (BinSearch(a, n, x)) {
            std::cout << "YES" << '\n';
        } else {
            std::cout << "NO" << '\n';
        }
    }

    delete[] a;
    return 0;
}

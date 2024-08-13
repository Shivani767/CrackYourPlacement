#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int m, n;
        std::cin >> m >> n;
        std::vector<int> x(m - 1), y(n - 1);
        for (int i = 0; i < m - 1; ++i) {
            std::cin >> x[i];
        }
        for (int i = 0; i < n - 1; ++i) {
            std::cin >> y[i];
        }
        std::sort(x.begin(), x.end());
        std::sort(y.begin(), y.end());
        int cost = 0;
        for (int i = m - 1; i > 0; --i) {
            cost += x[i - 1] * i;
        }
        for (int i = n - 1; i > 0; --i) {
            cost += y[i - 1] * i;
        }
        std::cout << cost << std::endl;
        if (t > 0) {
            std::cout << std::endl;
        }
    }
    return 0;
}

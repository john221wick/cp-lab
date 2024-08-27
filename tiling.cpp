#include <iostream>
using namespace std;

int tiling(int n) {
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            dp[i] = dp[i - 1] + dp[i / 2] + dp[i / 2 - 1];
        } else {
            dp[i] = dp[i - 1];
        }
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Number of ways to tile the board: " << tiling(n) << endl;

    return 0;
}

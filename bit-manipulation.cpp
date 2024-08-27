#include <iostream>
using namespace std;

int multiply(int a, int b) {
    int result = 0;
    while (b > 0) {
        // If b is odd, add a to result
        if (b & 1) {
            result += a;
        }
        // Left shift a (equivalent to multiplying by 2)
        a <<= 1;
        // Right shift b (equivalent to dividing by 2)
        b >>= 1;
    }
    return result;
}

// Function to divide two numbers using bit manipulation
int divide(int dividend, int divisor) {
    int quotient = 0;
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    long long ll_dividend = abs((long long)dividend);
    long long ll_divisor = abs((long long)divisor);

    while (ll_dividend >= ll_divisor) {
        int temp = ll_divisor;
        int i = 1;
        while (ll_dividend >= (temp << 1)) {
            temp <<= 1;
            i <<= 1;
        }
        ll_dividend -= temp;
        quotient += i;
    }
    return sign * quotient;
}

int main() {
    int num1 = 12;
    int num2 = 3;

    // Multiplication
    cout << "Multiplication of " << num1 << " and " << num2 << ": " << multiply(num1, num2) << endl;

    // Division
    cout << "Division of " << num1 << " by " << num2 << ": " << divide(num1, num2) << endl;

    return 0;
}

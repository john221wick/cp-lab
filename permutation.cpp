#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

void permute(string str, int l, int r) {
    if (l == r) {
        string rev = str;
        reverse(rev.begin(), rev.end());
        if (str == rev) {
            cout << str << endl;
        }
    } else {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]);
            permute(str, l + 1, r);
            // backtrack
            swap(str[l], str[i]);
        }
    }
}

int main() {
    string str = "aabb";
    int n = str.size();
    sort(str.begin(), str.end());
    permute(str, 0, n - 1);
    return 0;
}

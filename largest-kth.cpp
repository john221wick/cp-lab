#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int findKthLargest(int nums[], int n, int k) {
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        pq.push(nums[i]);
    }
    for (int i = 0; i < k - 1; i++) {
        pq.pop();
    }
    return pq.top();
}


int main() {
    int nums[] = {3, 2, 1, 5, 6, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 2;

    cout << "Kth largest element: " << findKthLargest(nums, n, k) << endl;

    return 0;
}

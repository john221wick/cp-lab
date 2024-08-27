#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printSubset(int arr[], int n, int i, int* subset, int k, vector<vector<int> >& subsets) {
    if (k == n) {
        vector<int> subsetArr;
        for (int j = 0; j < n; j++) {
            if (subset[j] == 1) {
                subsetArr.push_back(arr[j]);
            }
        }
        subsets.push_back(subsetArr);
        return;
    }
    subset[k] = 1;
    printSubset(arr, n, i, subset, k + 1, subsets);
    subset[k] = 0;
    printSubset(arr, n, i, subset, k + 1, subsets);
}

void printSubsets(vector<vector<int> >& subsets) {
    for (int i = 0; i < subsets.size(); i++) {
        vector<int> subset = subsets[i];
        sort(subset.begin(), subset.end());
        int sum = 0;
        cout << "Subset: ";
        for (int j = 0; j < subset.size(); j++) {
            cout << subset[j] << " ";
            sum += subset[j];
        }
        cout << ", Sum: " << sum << endl;
    }
}

int main() {
    int arr[] = {3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int subset[n];
    vector<vector<int> > subsets;

    printSubset(arr, n, 0, subset, 0, subsets);
    cout << "Subsets, Sums, and Sorted Subsets:" << endl;
    printSubsets(subsets);

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;


long long operationCount = 0;
int maxDepth = 0;

void complexRec(int n, int depth) {
    maxDepth = max(maxDepth, depth);
    operationCount++;
    if (n <= 2) return;

    int p = n;
    while (p > 0) {
        operationCount++;
        vector<int> temp(n);
        operationCount += n;
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            operationCount++;
        }
        p >>= 1;
        operationCount++;
    }

    vector<int> small(n);
    operationCount += n;
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
        operationCount++;
    }

    reverse(small.begin(), small.end());
    operationCount += n;

    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
}

int main() {
    vector<int> inputs = {8, 32, 512, 1024};

    for (int n : inputs) {
        operationCount = 0;
        maxDepth = 0;

        auto start = high_resolution_clock::now();
        complexRec(n, 1);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<milliseconds>(end - start);

        cout << "n = " << n << endl;
        cout << "Operations performed = " << operationCount << endl;
        cout << "Recursion depth = " << maxDepth << endl;
        cout << "Execution time = " << duration.count() << " ms" << endl;
        cout << "-----------------------------" << endl;
    }

    return 0;
}

/*
Recurrence Relation = T(n)=3T(n/2)+O(n logn)
Time Complexity = O(n^log2​3) {:a>b^k} this case is used in this.
*/

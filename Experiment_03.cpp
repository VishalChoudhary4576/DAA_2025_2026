#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<char> arr(N);
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    int maxLen = 0;

    for(int i = 0; i < N; i++) {
        int countP = 0, countA = 0;

        for(int j = i; j < N; j++) {

            if(arr[j] == 'P')
                countP++;
            else
                countA++;

            if(countP == countA) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }

    cout << maxLen << endl;
}

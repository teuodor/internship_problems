#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;

    vector<int> LMin(n);
    vector<int> RMax(n);

    LMin[0] = arr[0];
    for(int i = 1; i < n ; i++)
        LMin[i] = min(arr[i], LMin[i - 1]);

    RMax[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--)
        RMax[i] = max(arr[i], RMax[i + 1]);

    int i = 0, j = 0, maxDiff = -1;
    while(i < n && j < n)
    {
        if(LMin[i] <= RMax[j]) {
            maxDiff = max(j - i, maxDiff);
            j++;
        } else
            i++;
    }

    cout << maxDiff;

    return 0;
}

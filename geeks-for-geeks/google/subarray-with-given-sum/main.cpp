#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int t, sum, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> sum;
        vector<int> v(n);
        for(auto &i : v)
            cin >> i;

        int temp, start, end;
        start = end = temp = 0;
        bool ok = false;
        while(end < n && start < n && !ok)
        {
            if(temp < sum)
                temp += v[end++];
            else if(temp > sum)
                temp -= v[start++];
            else
            {
                if(start < end)
                    cout << start + 1 << " " << end << endl;
                else
                    cout << start << " " << end << endl;
                ok = true;
            }
        }
        if(!ok)
            cout << -1;
    }

    return 0;
}

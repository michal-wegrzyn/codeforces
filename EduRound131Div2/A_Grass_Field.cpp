#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, num, sum;
    cin >> t;
    while (t--)
    {
        sum = 0;
        for (int i = 0; i < 4; i++)
        {
            cin >> num;
            sum += num;
        }
        if (sum == 0)
            cout << 0 << '\n';
        else if (sum == 4)
            cout << 2 << '\n';
        else
            cout << 1 << '\n';
    }

    return 0;
}

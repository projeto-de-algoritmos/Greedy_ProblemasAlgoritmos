#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;

        ll ans = a;
        int gap = 0;
        int i = 0;
        while (s[i] != '1') {
            if (i == (int) s.size() - 1) {
                ans = 0;
                break;
            }
            i++; 
        }
        for ( ; i < (int) s.size(); i++) {
            if (s[i] == '1' && gap > 0) {
                ans += min(a, gap * b);
                gap = 0;
            }
            else if (s[i] == '0')
                gap++;
        }
        cout << ans << endl;
    }
    return 0;
}
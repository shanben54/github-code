#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

int n, x, y, z;
int a[N], b[N], c[N], t[N];

int calc()
{
    t[0] = a[x], t[1] = b[y], t[2] = c[z];

    if(t[0] == t[1] && t[1] == t[2]) return 200;
    else if(t[0] + 1 == t[1] && t[1] + 1 == t[2]) return 200;
    
    sort(t, t + 3);
    if(t[0] == t[1] || t[1] == t[2]) return 100;
    else if(t[0] + 1 == t[1] && t[1] + 1 == t[2]) return 100;
    return 0;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    int m; cin >> m;
    int sum = 0;
    while(m--)
    {
        int dx, dy, dz; cin >> dx >> dy >> dz;
        x = (x + dx) % n;
        y = (y + dy) % n;
        z = (z + dz) % n;

        sum += calc();
    }
    cout << sum << endl;

    return 0;
}
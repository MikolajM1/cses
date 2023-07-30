//
//  main.cpp
//  Minimizing Coins
//
//  Created by Mikołaj Małysz on 03/07/2023.
//

#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main(int argc, const char * argv[]) {
    int n, x = 0;
    cin >> n >> x;
    vector<int> coins(n, 0);
    for (int i = 0; i<n; i++) {
        cin >> coins[i];
    }
    vector<int> v(x+1, INF);
    v[0] = 0;
    for (int i = 1; i<=x; i++) {
        for (int j = 0; j<n; j++) {
            if (i-coins[j] >= 0) {
                if (v[i-coins[j]]+1 < v[i]) {
                    v[i] = v[i-coins[j]]+1;
                }
            }
        }
    }
    if (v[x] == INF) {
        v[x] = -1;
    }
    cout << v[x] << endl;
    return 0;
}

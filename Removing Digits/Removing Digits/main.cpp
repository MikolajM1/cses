//
//  main.cpp
//  Removing Digits
//
//  Created by Mikołaj Małysz on 03/07/2023.
//

#include <iostream>
#include <vector>

const int INF = 1e9;

using namespace std;

int main(int argc, const char * argv[]) {
    int n = 0;
    cin >> n;
    vector<int> v(n+1, INF);
    v[0] = 0;
    int temp = 1;
    for (int i = 1; i<=n; i++) {
        temp = i;
        while (temp >= 1) {
            if (v[i-temp%10]+1 < v[i]) {
                v[i] = v[i-temp%10]+1;
            }
            temp /= 10;
        }
    }
    cout << v[n] << endl;
    return 0;
}

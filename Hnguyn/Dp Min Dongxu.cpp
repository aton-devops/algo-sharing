#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+10;


int main (){
    int S; cin >> S;
    int N; cin >> N;
    vector <int> coins(N);
    vector <int> f (S + 1, INF);
    f[0] = 0;
    for ( int i = 0; i < N; i++ ){
        cin >> coins[i];
    }
    
    for ( int i = 1; i <= S; i++ ){ // Duyet tung so tien tu 1 -> S

        for ( int j = 0 ; j < N; j++ ){ // Duyet tung loai dong xu
            int v = coins[j];
            if ( i >= v && f[i-v] != INF ){
                f[i] = min (f[i], f[i-v] + 1);
            }
        }
    }

    if ( f[S] == INF ){
        cout << -1 << endl;
    }
    else {
        cout << "So dong xu nho nhat la: " << f[S] << endl;  
    }
}

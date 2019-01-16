#include <iostream>
#include <random>
using namespace std;

bool _t = ios_base::sync_with_stdio(false);
int main() {
    int n, m;
    cin >> n >> m;
    cout << n << " " << m << endl;
    uniform_int_distribution<> rand(1, n);
    default_random_engine Gn(random_device{}());
    for (int i = 0; i < m; ++i) cout << rand(Gn) << " " << rand(Gn) << endl;
}

#include "MaxCliqueFinder.h"
#include <iostream>
#include <vector>
#include <functional>
#include <thread>
using namespace std;
using namespace chrono_literals;

bool _t = ios::sync_with_stdio(false);
vector<MaxCliqueFinder> finders;
int main() {
    int n, m;
    cin >> n >> m;
    for (auto &finder : finders) {
        finder.Init();
        for (int i = 1; i <= n; ++i) finder.AddVertex(i);
    }
    while (m--) {
        int u,v;
        cin >> u >> v;
        for (auto &finder : finders) finder.AddEdge(u, v);
    }
    vector<vector<int>> results;
    for (auto &finder : finders) {
        vector<int> temp;
        thread t([](MaxCliqueFinder &finder, vector<int> &res){
                    res = finder.FindMaxClique();
                }, ref(finder), ref(temp));
        this_thread::sleep_for(120s);
        {
            lock_guard<mutex> lg(*finder.done_m);
            finder.done = true;
        }
        t.join();
        results.push_back(temp);
    }
    for (const auto &res : results) {
        cout << "size: " << res.size() << endl;
        bool output = false;
        for (int i : res) {
            if (output) cout << ' ';
            else output = true;
            cout << i;
        }
        cout << endl;
    }
}

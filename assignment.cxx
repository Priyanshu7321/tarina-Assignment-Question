#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int f(vector<vector<int>>& v){
    sort(v.begin(), v.end(), [](auto& a, auto& b) { return a[0] < b[0]; });
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto& i : v) {
        if (!pq.empty() && i[0] >= pq.top()) pq.pop();
        pq.push(i[1]);
    }
    return pq.size();
}

int main() {
    vector<vector<int>> a={{0,30},{5,10},{15,20}};
    vector<vector<int>> b={{7,10},{2,4}};
    vector<vector<int>> c={{1,5},{8,9},{8,9}};
    vector<vector<int>> d={{1,4},{2,5},{3,6}};
    vector<vector<int>> e={{1,2},{2,3},{3,4},{4,5}};
    cout<<f(a)<<endl;
    cout<<f(b)<<endl;
    cout<<f(c)<<endl;
    cout<<f(d)<<endl;
    cout<<f(e)<<endl;
    return 0;
}

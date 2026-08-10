#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int mn = INT_MAX;
    
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] < mn) {
            mn = v[i];
        }
    }
    
    vector<int> index;
    for(int i = 0; i < n; i++) {
        if(v[i] == mn) {
            index.push_back(i);
        }
    }
    
    int min_dist = INT_MAX;
    for(size_t i = 1; i < index.size(); i++) {
        if(index[i] - index[i - 1] < min_dist) {
            min_dist = index[i] - index[i - 1];
        }
    }
    
    cout << min_dist << endl;
    return 0;
}

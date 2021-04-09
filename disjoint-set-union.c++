//aka union-find
//time complexity:
//Each union or find operation take O(log2(n)) time.

#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int arr[MAX];
int tsize[MAX];

void initialise() {
    for (int i = 0; i < MAX; i++) {
        arr[i] = i;
        tsize[i] = 1;
    }
}
int root(int i) {
    while (arr[i] != i) {
        arr[i] = arr[arr[i]]; //helps to flatten the graph
        i = arr[i];
    }
    return i; 
}

void uni(int a, int b) {
    int roota = root(a);
    int rootb = root(b);
    if (tsize[a] > tsize[b]) {
        arr[rootb] = roota;
        tsize[roota] += tsize[rootb]; 
    }
    else {
        arr[roota] = rootb;
        tsize[rootb] += tsize[roota];
    }
}

bool find(int a, int b) {
    if (root(a) == root(b)) return true;
    return false;
}

int main() {
    freopen("../input.txt", "r", stdin); 
    freopen("../output.txt", "w", stdout);
    initialise();
    int t, a, b;
    cin >> t;
    while (t--) {
        char c;
        cin >> c >> a >> b;
        if (c == 'u') {
            uni(a, b);
        }
        else {
            bool ans = find(a, b);
            cout << ans;
        }
    }

}
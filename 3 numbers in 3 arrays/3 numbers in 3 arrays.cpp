#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

const int N = 10; // just some input

using namespace std;

void print(vector <int> &v) {
    for (int i = 0; i < N; ++i)
        cout << v[i] << " ";
    cout << endl;
}

bool find_number(vector<int> &v1, vector<int> &v2, vector<int> &v3, int number) {
    int j = 0, k = N-1;
    while (j < N && k >= 0) {
        if (binary_search(v1.begin(), v1.end(), number - (v2[j] + v3[k]))) {
            cout << number - (v2[j] + v3[k]) << "+" << v2[j] << "+" << v3[k] << endl;
            return true;
        }
        else if (v2[j] + v3[k] > number) {
            --k;
        }
        else
            ++j;
    }
    return false;
}

int main() {
    int number;
    cin >> number;
    vector<int> v1(N);
    vector<int> v2(N);
    vector<int> v3(N);
    for (int i = 0; i < N; ++i) { // just some input
        v1[i] = -rand()%20;
        v2[i] = -rand()%140;
        v3[i] = -rand()%20;
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    sort(v3.begin(), v3.end());
    
    print(v1);
    print(v2);
    print(v3);
    
    
    if ( !(find_number(v1, v2, v3, number) || find_number(v1, v3, v2, number)) )
        cout << "NO\n";
    
    return 0;
}

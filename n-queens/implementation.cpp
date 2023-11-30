#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter the n of (n x n): ";
    cin >> n;
    int pos[n];
    cout << "Enter the positions of the queens: ";
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pos[j] == pos[i]) {
                cout << "No\n";
                return 0;
            }
            if ((i - j) % (pos[i] - pos[j]) == 0 && abs((i - j) / (pos[i] - pos[j])) == 1) {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    return 1;
}

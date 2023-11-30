#include <iostream>
#include <vector>
using std::cout, std::cin, std::vector;

int find(vector<int> arr, int add, vector<int>& aMain, int size) {
    if (add == 0) {
        aMain = arr;
        return 1;
    }
    else if (add == size) {
        int yes = 0;
        for (int i = 0; i + add + 1 < 2 * size; i++) {
            arr[i] = arr[i + add + 1] = add;
            if (find(arr, add - 1, aMain, size)) {
                yes = 1;
                for (auto i: aMain) cout << i << ' ';
                cout << '\n';
            }
            arr[i] = arr[i + add + 1] = 0;
        }
        if (yes) return 1;
    } else {
        for (int i = 0; i + add + 1 < 2 * size; i++) {
            if (arr[i] == 0 && arr[i + add + 1] == 0) {
                arr[i] = arr[i + add + 1] = add;
                if (find(arr, add - 1, aMain, size)) {
                    return 1;
                }
                arr[i] = arr[i + add + 1] = 0;
            }
        }
    }
    return 0;
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    vector<int> arr(2 * n, 0);
    if (find(arr, n, arr, n)) {
        cout << "These are some of the sequences.\n";
        return 0;
    }
    cout << "It is not possible to design such a sequence.\n";
    return 0;
}

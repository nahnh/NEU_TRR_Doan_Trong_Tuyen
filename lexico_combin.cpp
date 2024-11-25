#include <iostream>
using namespace std;

int s[10];
int n, r;

void lexi_comb(int n, int r) {
    int C_nr = 1; // Compute C(r, n)
    for (int i = 1; i <= r; i++)
        C_nr = C_nr * (n - i + 1) / i;
    // first combination
    for (int i = 1; i <= r; i++)
        s[i] = i;
    for (int i = 1; i <= r; i++)
        cout << s[i] << " ";
    cout << endl;
    // the rest
    for (int i = 2; i <= C_nr; i++) {
        int m = r;
        int max_val = n;
        while (m > 0 && s[m] == max_val) {
            m--;
            max_val--;
        }
        s[m]++; // update subsequent elements
        for (int j = m + 1; j <= r; j++)
            s[j] = s[j - 1] + 1;
        // print current combination
        for (int k = 1; k <= r; k++)
            cout << s[k] << " ";
        cout << endl;
    }
}

int main() {
    cout << "Enter n, r (n > r) = ";
    cin >> n >> r;
    if (r > n || r <= 0 || n <= 0) {
        cout << "Invalid input. Ensure 0 < r <= n." << endl;
        return 0;
    }
    lexi_comb(n, r);
    return 0;
}

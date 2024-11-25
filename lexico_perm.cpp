#include <iostream>
using namespace std;

int s[10];
int n, i, j, k, p, q, m;

void lexi_perm(int n) {
    int n_gt = 1; // n factorial
    for (i = 1; i <= n; i++)
        n_gt *= i;
    // first permutation
    for (i = 1; i <= n; i++) 
        s[i] = i;
    for (i = 1; i <= n; i++)
        cout << s[i] << " ";
    cout << endl;
    // the rest
    for (i = 2; i <= n_gt; i++) {
        m = n - 1; // find first dip from right
        while (m > 0 && s[m] > s[m + 1])
            m--;
        k = n; // find first s[k] > s[m]
        while (s[m] > s[k])
            k--;
        swap(s[m], s[k]); // trung gian
        // reverse right part
        p = m + 1;
        q = n;
        while (p < q) {
            swap(s[p], s[q]);
            p++;
            q--;
        }
        // print current permuation
        for (k = 1; k <= n; k++)
            cout << s[k] << " ";
        cout << endl;
    }
}

int main() {
    cout << "Enter n = ";
    cin >> n;
    if (n < 1 || n > 10) {
        cout << "Invalid input. Please enter a number between 1 and 10." << endl;
        return 0;
    }
    lexi_perm(n);
    return 0;
}

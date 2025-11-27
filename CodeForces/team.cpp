#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    int agree = 0;

    while (t--) {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;

        if (n1 + n2 + n3 >= 2) {
            agree++;
        }
    }

    cout << agree;
    return 0;
}

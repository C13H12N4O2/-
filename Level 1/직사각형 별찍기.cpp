#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int a;
    int b;
    string str;
    cin >> a >> b;
    for (int i = 0; i != b; i++) {
        for (int j = 0; j != a; j++) {
            str += '*';
        } str += '\n';
    }
    cout << str << endl;
    cout << a + b << endl;
    return 0;
}

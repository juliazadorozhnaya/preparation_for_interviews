#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int q;
    stack <int64_t> numbers;
    stack<int64_t> uniques;
    string com;
    int64_t min;
    cin >> q;

    while (q--) {

        cin >> com;
        if (com == "push") {
            int64_t n;
            cin >> n;
            numbers.push(n);
            if (numbers.size() == 1)
                min = n;
            else if (n < min)
                min = n;
            uniques.push(min);
            cout << "ok";
        }
        if (com == "pop") {
            if (numbers.size() != 0){
                cout << numbers.top();
                numbers.pop();
                uniques.pop();
            }
            else
                cout << "error";
        }

        if (com == "back") {
            if (numbers.size() != 0)
                cout << numbers.top();
            else
                cout << "error";
        }

        if (com == "size")
            cout << numbers.size();

        if (com == "clear") {
            while (numbers.size() != 0) {
                numbers.pop();
            }
            cout << "ok";
        }
        if (com == "min"){
            int size = numbers.size();
            if (size == 0)
                cout << "error";
            else
                cout << uniques.top();

        }

        if (q > 0)
            cout << endl;
    }

    return 0;
}
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack <char> pars;
    string s;
    cin >> s;
    for (auto c : s) {
        if (pars.size() == 0) {
            pars.push(c);
        } else {
            if (c == '(' || c == '[' || c == '{') {
                pars.push(c);
            } else {
                if (c == ')') {
                    if (pars.top() == '(') {
                        pars.pop();
                    } else {
                        pars.push(c);
                    }
                }
                if (c == ']') {
                    if (pars.top() == '[') {
                        pars.pop();
                    } else {
                        pars.push(c);
                    }
                }
                if (c == '}') {
                    if (pars.top() == '{') {
                        pars.pop();
                    } else {
                        pars.push(c);
                    }
                }
            }
        }
    }
    if (pars.size() == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
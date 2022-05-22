#include <iostream>
#include <vector>

using namespace std;

void g (const char * , long long ) { }

void g(double, int ) { }

void g ( ... , short) { }


int main() {
    g(0,5L);
}
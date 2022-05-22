#include <iostream>
#include <iomanip>
#include <math.h>

double f(double a, double b, double c, double d, double x){
    return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}

double f_bin_search_negative_a(double a, double b, double c, double d, double eps) {
    double l = -1000;
    double r = 1000;
    double m;

    while (r - l > eps)
    {   
        m = (l + r) / 2.0;

        if (f(a, b, c, d, m) < 0)
            r = m;
        else
            l = m;
    }

    return l;
} 

double f_bin_search_positive_a(double a, double b, double c, double d, double eps) {
    double l = -10000;
    double r = 10000;
    double m;

    while (r - l > eps)
    {   
        m = (l + r) / 2.0;

        if (f(a, b, c, d, m) > 0)
            r = m;
        else
            l = m;
    }

    return l;
}

int main() {
    double a, b, c, d, eps;
    eps = 0.00001;

    std::cin >> a >> b >> c >> d;
    std::cout << std::setprecision(10);

    if (a > 0)
        std::cout << f_bin_search_positive_a(a, b, c, d, eps) << std::endl;
    else
        std::cout << f_bin_search_negative_a(a, b, c, d, eps) << std::endl;

    return 0;
}

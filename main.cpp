#include <iostream>
#include <vector>

using namespace std;

#include "fraction.h"


int main()
{
    Fraction < int > drob1,drob2,drob3;
    cin >> drob1;
    cin >> drob2;
    drob3 = drob2 - drob1;
    bool f = (2 < drob2);
    cout << drob3 << "\n";
    cout << drob2 << "\n";
    cout << f << "\n";
    return 0;
}

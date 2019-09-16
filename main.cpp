#include <iostream>

using namespace std;

#include "drob.h"


int main()
{
    Drobi < double > drob1,drob2;
    cin >> drob1;
    cin >> drob2;
    drob1 = drob1 - drob2;
    cout << drob1;
    return 0;
}

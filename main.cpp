// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cmath>

#include "fraction.h"
#include "Testlib1.h"
#include "test.h"

int main()
{
	Fraction < int > frac1(1, 1);
	std::cout << frac1;
    TestAll();
	system("pause");
    return 0;
}

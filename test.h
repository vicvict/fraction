#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

bool Testlib::__assert_print_to_stderr = true;
bool Testlib::__assert_print_if_ok     = false;
bool Testlib::__assert_throw_exception = true;
bool Testlib::__test_print_to_stderr   = true;
bool Testlib::__test_throw_exception   = false;

void Test1();
void Test2();
void Test3();
void Test4();
void Test5();
void Test6();
void Test7();
void Test8();
void TestAll();

void Test1() {
    {
        Fraction < int > frac1;
        ASSERT_MSG(frac1.get_numerate() == 0, "numerate is equal to 0");
        ASSERT_MSG(frac1.get_denumerate() == 1, "denumerate is equal to 1");
    }
    {
        Fraction < int > frac1 (10,3);
        ASSERT_MSG(frac1.get_numerate() == 10, "numerate is equal to 10");
        ASSERT_MSG(frac1.get_denumerate() == 3, "denumerate is equal to 3");
    }
    {
        Fraction < int > frac1 (10,-3);
        ASSERT_MSG(frac1.get_numerate() == -10, "numerate is equal to -10");
        ASSERT_MSG(frac1.get_denumerate() == 3, "denumerate is equal to 3");
    }
    {
        Fraction < int > frac1 (6,3);
        ASSERT_MSG(frac1.get_numerate() == 2, "numerate is equal to 2");
        ASSERT_MSG(frac1.get_denumerate() == 1, "denumerate is equal to 1");
    }
    {
        Fraction < int > frac1 (6,-3);
        ASSERT_MSG(frac1.get_numerate() == -2, "numerate is equal to -2");
        ASSERT_MSG(frac1.get_denumerate() == 1, "denumerate is equal to 1");
    }
    {
        Fraction < int > frac1 (0,100);
        ASSERT_MSG(frac1.get_numerate() == 0, "numerate is equal to 0");
        ASSERT_MSG(frac1.get_denumerate() == 1, "denumerate is equal to 1");
    }
    {
        Fraction < int > frac1 (6);
        ASSERT_MSG(frac1.get_numerate() == 6, "numerate is equal to 6");
        ASSERT_MSG(frac1.get_denumerate() == 1, "denumerate is equal to 1");
    }
    {
        Fraction < int > frac1 (1.5);
        ASSERT_MSG(frac1.get_numerate() == 3, "numerate is equal to 3");
        ASSERT_MSG(frac1.get_denumerate() == 2, "denumerate is equal to 2");
    }
    {
        Fraction < int > frac1 (7,2);
        Fraction < int > frac2(frac1);
        ASSERT_MSG(frac1.get_numerate() == 7, "numerate is equal to 7");
        ASSERT_MSG(frac1.get_denumerate() == 2, "denumerate is equal to 2");
    }
	{
        Fraction < int > frac1 (7,2);
        double a = frac1.todouble();
        ASSERT_MSG(a == 3.5, "Normally return double");
    }
}

void Test2() {
    {
        ASSERT_MSG(Fraction < int > (7,3) == Fraction < int > (7,3), "7/3 is equal to 7/3");
        ASSERT_MSG(Fraction < int > (0,100) == Fraction < int > (0,1), "0/100 is equal to 0/1");
        ASSERT_MSG(Fraction < int > (6,3) == 2, "6/3 is equal to 2/1");
        ASSERT_MSG(Fraction < int > (7,3) != Fraction < int > (8,3), "7/3 is not equal to 8/3");
        ASSERT_MSG(Fraction < int > (-6,3) == Fraction < int > (2,-1), "-6/3 is equal to 2/-1");
    }
}

void Test3(){
    {
        ASSERT_MSG(Fraction < int > (7,3) > Fraction < int > (5,3), "7,3 is more than 5/3");
        ASSERT_MSG(Fraction < int > (-5,2) > -3 , "-5/2 is more than -3");
        ASSERT_MSG(5 > Fraction < int > (0,100) , "4 is more than 0/100");
        ASSERT_MSG(Fraction < int > (6,3) >= 2 , "6/3 is more or equal to 2");
        ASSERT_MSG(Fraction < int > (6,3) >= Fraction < int > (12,6) , "6/3 is more or equal to 12/6");
        ASSERT_MSG(Fraction < int > (7,3) >= 2 , "7/3 is more or equal to 2");
        ASSERT_MSG(Fraction < int > (6,3) >= Fraction < int > (11,6) , "6/3 is more or equal to 11/6");
        ASSERT_MSG(2 >= Fraction < int > (5,3), "2 is more or equal to 5/3");
        ASSERT_MSG(-2 >= Fraction < int > (6,-3), "-2 is more or equal to -6/3");
        ASSERT_MSG(Fraction < int > (4,3) < Fraction < int > (5,2) , "4/3 is less than 5/2");
        ASSERT_MSG(Fraction < int > (-6,5) < -1 , "-6/5 is less than -1");
        ASSERT_MSG(-2 < Fraction < int > (-4,3) , "-2 is less than -4/3");
        ASSERT_MSG(Fraction < int > (5,2) <= Fraction < int > (8,3) , "5/2 is less or equal to 8/3");
        ASSERT_MSG(Fraction < int > (5,2) <= Fraction < int > (10,4) , "5/2 is less or equal to 10/4");
        ASSERT_MSG(Fraction < int > (-5,2) <= -2 , "-5/2 is less or equal to -2");
        ASSERT_MSG(Fraction < int > (-4,2) <= -2 , "-4/2 is less or equal to -2");
        ASSERT_MSG(2 <= Fraction < int > (7,3) , "2 is less or equal to 7/3");
        ASSERT_MSG(-2 <= Fraction < int > (-6,3) , "-2 is less or equal to -6/3");
    }
}

void Test4(){
    {
        Fraction < int > frac1(4,3), frac2 (2,3) , frac3 (1,2) , frac4 (-4,3);
        ASSERT_MSG( (frac1 + frac2) == 2, "4/3 + 2/3 is equal to 2");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG(frac2 == Fraction < int > (2,3) , "The second term did not change");
        ASSERT_MSG( (frac1 + frac3) == Fraction < int > (11,6), "4/3 + 1/2 is equal to 11/6");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG(frac3 == Fraction < int > (1,2) , "The second term did not change");
        ASSERT_MSG( (frac1 + frac4) == 0, "4/3 + -4/3 is equal to 0");
        ASSERT_MSG( (frac1 + 3) == Fraction < int > (13,3), "4/3 + 3 is equal to 13/3");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG( (2 + frac3) == Fraction < int > (5,2), "1/2 + 2 is equal to 5/2");
        ASSERT_MSG(frac3 == Fraction < int > (1,2) , "The second term did not change");
        ASSERT_MSG( (+frac2) == Fraction < int > (2,3) , "+2/3 is equal to 2/3");
        ASSERT_MSG( (frac1 += frac2) == 2 , "4/3 += 2/3 is equal to 2");
        ASSERT_MSG(frac1 == 2 ,"I changed");
        ASSERT_MSG(frac2 == Fraction < int > (2,3), " I didn't changed");
        ASSERT_MSG( (frac2 += 1) == Fraction < int > (5,3) , "2/3 += 1 is equal to 5/3 ");
        ASSERT_MSG(frac2 == Fraction < int > (5,3), "I changed");
        ASSERT_MSG((++frac4) == Fraction < int > (-1,3) , "++(-4/3) is equal to -1/3");
        ASSERT_MSG(frac4 == Fraction < int > (-1,3), "I changed");
        ASSERT_MSG((frac4++) == Fraction < int > (-1,3) , "(-1/3)++ is equal to -1/3");
        ASSERT_MSG(frac4 == Fraction < int > (2,3), "I changed");
    }
}

void Test5(){
    {
        Fraction < int > frac1(4,3), frac2 (1,3) , frac3 (1,2) , frac4 (-4,3);
        ASSERT_MSG( (frac1 - frac2) == 1, "4/3 - 2/3 is equal to 1");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG(frac2 == Fraction < int > (1,3) , "The second term did not change");
        ASSERT_MSG( (frac1 - frac3) == Fraction < int > (5,6), "4/3 - 1/2 is equal to 5/6");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG(frac3 == Fraction < int > (1,2) , "The second term did not change");
        ASSERT_MSG( (frac1 - frac4) == Fraction < int > (8,3), "4/3 - -4/3 is equal to 8/3");
        ASSERT_MSG( (frac1 - 3) == Fraction < int > (-5,3), "4/3 - 3 is equal to -5/3");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG( (2 - frac3) == Fraction < int > (3,2), "2 - 1/2 is equal to 3,2");
        ASSERT_MSG(frac3 == Fraction < int > (1,2) , "The second term did not change");
        ASSERT_MSG( (-frac2) == Fraction < int > (-1,3) , "-(1/3) is equal to -1/3");
        ASSERT_MSG(frac2 == Fraction < int > (-1,3), "I changed");
        ASSERT_MSG( (frac1 -= frac2) == Fraction < int > (5,3) , "4/3 -= -1/3 is equal to 5/3 ");
        ASSERT_MSG(frac1 == Fraction < int > (5,3),"I changed");
        ASSERT_MSG(frac2 == Fraction < int > (-1,3), " I didn't changed");
        ASSERT_MSG( (frac3 -= 1) == Fraction < int > (-1,2) , "1/2 -= 1 is equal to -1/2 ");
        ASSERT_MSG(frac3 == Fraction < int > (-1,2), "I changed");
        ASSERT_MSG((--frac4) == Fraction < int > (-7,3) , "--(-4/3) is equal to -7/3");
        ASSERT_MSG(frac4 == Fraction < int > (-7,3), "I changed");
        ASSERT_MSG((frac4--) == Fraction < int > (-7,3) , "(-7/3)++ is equal to -7/3");
        ASSERT_MSG(frac4 == Fraction < int > (-10,3), "I changed");
    }
}

void Test6(){
    {
        Fraction < int > frac1(4,3), frac2 (3,4) , frac3 (0,2) , frac4 (2,-3);
        ASSERT_MSG( (frac1 * frac2) == 1, "4/3 * 3/4 is equal to 1");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG(frac2 == Fraction < int > (3,4) , "The second term did not change");
        ASSERT_MSG( (frac1 * frac3) == Fraction < int > (0), "4/3 * 0/2 is equal to 0");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG(frac3 == Fraction < int > (0,2) , "The second term did not change");
        ASSERT_MSG( (frac1 * frac4) == Fraction < int > (-8,9), "4/3 * -2/3 is equal to -8/9");
        ASSERT_MSG( (frac1 * 3) == 4, "4/3 * 3 is equal to 4");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG( (2 * frac2) == Fraction < int > (3,2), "2 * 3/4 is equal to 3/2");
        ASSERT_MSG(frac2 == Fraction < int > (3,4) , "The second term did not change");
        ASSERT_MSG( (frac1 *= frac2) == 1 , "4/3 *= 3/4 is equal to 1");
        ASSERT_MSG(frac1 == 1 ,"I changed");
        ASSERT_MSG(frac2 == Fraction < int > (3,4), " I didn't changed");
        ASSERT_MSG( (frac2 *= 3) == Fraction < int > (9,4) , "3/4 *= 3 is equal to 9/4 ");
        ASSERT_MSG(frac2 == Fraction < int > (9,4), "I changed");
        frac4.square();
        ASSERT_MSG( frac4 == Fraction < int > (4,9) , "(-2/3)^2 is equal to 4/9");
        frac4.sqrt();
        ASSERT_MSG( frac4 == Fraction < int > (2,3) , "sqrt(4/9) is equal to 2/3");
    }
}

void Test7(){
    {
        Fraction < int > frac1(4,3), frac2 (4,3) , frac3 (1,2) , frac4 (-2,3);
        ASSERT_MSG( (frac1 / frac2) == 1, "4/3 / 4/3 is equal to 1");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG(frac2 == Fraction < int > (4,3) , "The second term did not change");
        ASSERT_MSG( (frac1 / frac3) == Fraction < int > (8,3), "4/3 / 1/2 is equal to 8/3");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG(frac3 == Fraction < int > (1,2) , "The second term did not change");
        ASSERT_MSG( (frac1 / frac4) == -2, "4/3 / -2/3 is equal to -2");
        ASSERT_MSG( (frac1 / 4) == Fraction < int > (1,3), "4/3 / 4 is equal to 1/3");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG( (2 / frac2) == Fraction < int > (3,2), "2 / 4/3 is equal to 3/2");
        ASSERT_MSG(frac2 == Fraction < int > (4,3) , "The second term did not change");
        ASSERT_MSG( (frac1 /= frac2) == 1 , "4/3 /= 4/3 is equal to 1");
        ASSERT_MSG(frac1 == 1 ,"I changed");
        ASSERT_MSG(frac2 == Fraction < int > (4,3), " I didn't changed");
        ASSERT_MSG( (frac2 /= 3) == Fraction < int > (4,9) , "3/4 /= 3 is equal to 4/9 ");
        ASSERT_MSG(frac2 == Fraction < int > (4,9), "I changed");
    }
}

void Test8 ()
{
    {
        Fraction < int > frac1(5,3),frac2;
        ASSERT_MSG((frac2 = frac1) == Fraction < int > (5,3) , " 5/3 is equal to 5/3");
        ASSERT_MSG( frac1 == Fraction < int > (5,3) ," I don't changed");
        ASSERT_MSG((frac2 = 3) == 3 , " 3 is equal to 3");
    }
}

void TestAll() {
    Testlib::Test test;
    RUN_TEST_MSG(test, Test1, "Construction check");
    RUN_TEST_MSG(test, Test2, "Equality check");
    RUN_TEST_MSG(test, Test3, "Compared test");
    RUN_TEST_MSG(test, Test4, "Summary test");
    RUN_TEST_MSG(test, Test5, "Difference test");
    RUN_TEST_MSG(test, Test6, "Multiply test");
    RUN_TEST_MSG(test, Test7, "Division test");
    RUN_TEST_MSG(test, Test8, "Check of equal");
}

#endif // TEST_H_INCLUDED


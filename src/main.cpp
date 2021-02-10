#include <iostream>
//#include <windows.h>

#include "testclass.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    testclass* tc = new testclass();

    tc->foo();

    delete tc;

    //system("pause");
    return 0;
}

#include "SimpleLibDll.h"

static int add(int a, int b) {
    return a + b;
}

int SimpleLib::add(int a, int b)
{
    return a + b;
}

int SimpleLib::subtract(int a, int b)
{
    return a - b;
}

int SimpleLib::multiply(int a, int b)
{
    return a * b;
}

double SimpleLib::divide(int a, int b)
{
    return a / b;
}

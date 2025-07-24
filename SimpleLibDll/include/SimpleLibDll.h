#include "export.h"


class SIMPLELIBDLL_API SimpleLib {
public:
    SimpleLib() = default;
    ~SimpleLib() = default;
    int add(int a, int b);
    int subtract(int a, int b);
    int multiply(int a, int b);
    double divide(int a, int b);

};
#include <string>
#include "stdtostring.h"

class Plural
{
public:
    double ImaginaryPart; 
    double RealPart;
    Plural()
    {
        this->ImaginaryPart = 0;
        this->RealPart = 0;
    }
    Plural(double real, double imagimary)
    {
        this->ImaginaryPart = imagimary;
        this->RealPart = real;
    }
    Plural operator +(const Plural& p);
    Plural operator -(const Plural& p);
    Plural operator *(const Plural& p);
    Plural operator /(const Plural& p);
    Plural operator -();
    
    std::string ToString();
};
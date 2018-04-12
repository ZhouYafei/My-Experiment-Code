#include "Plural.h"

Plural Plural::operator +(const Plural &p)
{
    Plural plural;
    plural.ImaginaryPart = this->ImaginaryPart + p.ImaginaryPart;
    plural.RealPart = this->RealPart + p.RealPart;
    return plural;
}

Plural Plural::operator -(const Plural &p)
{
    Plural plural;
    plural.ImaginaryPart = this->ImaginaryPart - p.ImaginaryPart;
    plural.RealPart = this->RealPart - p.RealPart;
    return plural;
}

Plural Plural::operator *(const Plural &p)
{
    Plural plural;
    plural.ImaginaryPart =this->ImaginaryPart * p.RealPart +
                    this->RealPart * p.ImaginaryPart;
    plural.RealPart = this->RealPart * p.RealPart -
                    this->ImaginaryPart * p.ImaginaryPart;
    return plural;
}

Plural Plural::operator /(const Plural &p)
{
    Plural plural;
    plural.ImaginaryPart = this->ImaginaryPart * p.RealPart -
                    this->RealPart * p.ImaginaryPart;
    plural.ImaginaryPart = plural.ImaginaryPart /
        (p.RealPart * p.RealPart + p.ImaginaryPart * p.ImaginaryPart);
    plural.RealPart = this->RealPart * p.RealPart +
                    this->ImaginaryPart * p.ImaginaryPart;
    plural.RealPart = plural.RealPart / 
        (p.RealPart * p.RealPart + p.ImaginaryPart * p.ImaginaryPart);
    return plural;
}

std::string Plural::ToString()
{
    std::string imaginaryOp = "";
    if(this->ImaginaryPart >= 0)
        imaginaryOp = "+";
    return "("+ std::to_string(this->RealPart) + 
                imaginaryOp + std::to_string(this->ImaginaryPart) + "i" +")";
}
#ifndef __COMPONENT_H__
#define __COMPONENT_H__
#include <iostream>
using namespace std;

class Base {
    public:
        /* Constructors */
        Base() {}

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
};


#endif // __COMPONENT_H__

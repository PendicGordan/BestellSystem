#ifndef LESSTHANZERO_H
#define LESSTHANZERO_H

#include <exception>
#include <stdexcept>

using namespace std;

class LessThanZeroException : public runtime_error {

    public:

    LessThanZeroException() : runtime_error("Kleiner als 0."){}
    virtual const char* what();

    static int check(int number){
        if (number < 0) {
            throw LessThanZeroException();
        }
    return 0;
    }
};

#endif // LESSTHANZERO_H

#include "LessThanZero.h"

using namespace std;

const char* LessThanZeroException::what() {
    return "Number of tables can't be less than 0. You are fired, bye \n";
}

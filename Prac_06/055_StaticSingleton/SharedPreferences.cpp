#include "SharedPreferences.h"

SharedPreferences &SharedPreferences::getInstance() {
    static SharedPreferences a ;
    return a ;
}

void SharedPreferences::putInt(std::string key, int value) {

}

int SharedPreferences::getInt(std::string key) {
    return 0 ;
}
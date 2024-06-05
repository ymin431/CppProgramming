#include "EzrealSkill.h"
#include <iostream>

using namespace std ;

class GangplankSkill : public Skill {

    void q() override {
        cout << "TRIAL BY FIRE" << endl ;
    } ;

    void w() override {
        cout << "PARRRLEY" << endl ;
    } ;

    void e() override {
        cout << "REMOVE SCURVY" << endl ;
    } ;

    void r() override {
        cout << "POWDER KEG" << endl ;
    } ;

} ;
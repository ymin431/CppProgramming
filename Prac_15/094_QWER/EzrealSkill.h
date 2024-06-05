#include "Skill.h"
#include <iostream>

using namespace std ;

class EzrealSkill : public Skill {

    void q() override {
        cout << "RISING SPELL FORCE" << endl ;
    } ;

    void w() override {
        cout << "MYSTIC SHOT" << endl ;
    } ;

    void e() override {
        cout << "ESSENCE FLUX" << endl ;
    } ;

    void r() override {
        cout << "ARCANE SHIFT" << endl ;
    } ;

} ;
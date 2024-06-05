#include "patient.h"

pPatient create_patient(const std::string &name, int age, float weight, float height, int date){

    PatientInfo patient ;

    float bmi = weight / (height* height) ;

    patient.name = name ;
    patient.age = age ;
    patient.weight = weight ;
    patient.height = height ;
    patient.date = date ;
    patient.bmi = bmi ;

    return std::make_unique<PatientInfo>(patient) ;

}



void sort_patients(PatientList &patients) {

    std::sort(patients.begin(), patients.end(),
              [](const pPatient& a, const pPatient& b){ return a->bmi > b->bmi; } ) ;

}



PatientList find_patient(const PatientList &patients, const std::string &name){

    PatientList foundPatient ;

    auto it = std::find_if(patients.begin(), patients.end(),
                           [name](const pPatient& a){ return a->name == name ; }) ;

    while ( it != patients.end() ) {
        foundPatient.push_back(std::make_unique<PatientInfo>(**it)) ;
        it = std::find_if(std::next(it), patients.end(),
                               [name](const pPatient& a){ return a->name == name ; }) ;
    }

    return foundPatient ;

}



int count_patients(const PatientList &patients, float threshold){

    int countPatient = std::count_if(patients.begin(), patients.end(),
                                     [threshold](const pPatient& a){ return a->bmi > threshold ; }) ;

    return countPatient ;

}



void remove_old_records(PatientList &patients, int date){

    patients.erase(std::remove_if(patients.begin(), patients.end(),
                                  [date](const pPatient& a){ return a->date < date ; }), patients.end()) ;

}



void print_patients(const PatientList &patients){

    std::for_each(patients.begin(), patients.end(),[](const std::unique_ptr<PatientInfo>& a){
        std::cout << a->name << " " << a->age << " " << a->weight << " " << a->height << " " << a->date << " " << a->bmi << std::endl ;
    } ) ;

}
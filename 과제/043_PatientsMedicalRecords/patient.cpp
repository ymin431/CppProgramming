#include "patient.h"

pPatient create_patient(const std::string &name, int age, float weight, float height, int date){

    PatientInfo patient ;
    patient.name = name ;
    patient.age = age ;
    patient.weight = weight ;
    patient.height = height ;
    patient.date = date ;
    patient.bmi = weight / (height * height) ;

    return std::make_unique<PatientInfo>(patient) ;

}

void sort_patients(PatientList &patients) {

	sort(patients.begin(), patients.end(),
                  [](pPatient& a, pPatient& b){return a->bmi > b->bmi;}) ;

}



std::vector<PatientInfo> find_patient(const PatientList &patients, const std::string &name){

    auto find = std::find_i(patients.begin(), patients.end(),
                             [name](pPatient& a){return a->name == name;}) ;

    std::cout >>

}



int count_patients(const PatientList &patients, float threshold){

	//implement your code

}



void remove_old_records(PatientList &patients){

	//implement your code

}



void print_patients(const PatientList &patients){

	//implement your code

}
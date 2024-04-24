#include "patient.h"

std::unique_ptr<PatientInfo> createPatient( std::string& name, int age, int weight, double height ) {

    auto patient = std::make_unique<PatientInfo>() ;

    patient->name = name ;
    patient->age = age ;
    patient->weight = weight ;
    patient->height = height ;
    patient->BMI = weight / (height * height) ;

    return patient ;

}

void SortBMI( std::vector<std::unique_ptr<PatientInfo>>& patients, std::string& option ) {

    if ( option == "desc" )
        std::sort(patients.begin(), patients.end(),
                  [](std::unique_ptr<PatientInfo>& a, std::unique_ptr<PatientInfo>& b){return a->BMI > b->BMI;}) ;
    else
        std::sort(patients.begin(), patients.end(),
                  [](std::unique_ptr<PatientInfo>& a, std::unique_ptr<PatientInfo>& b){return a->BMI < b->BMI;}) ;

    std::cout << "Sorted by BMI (" << option << "ending):" << std::endl ;
    for ( auto& i : patients )
        std::cout << i->name << " " << i->age << " " << i->weight << " " << i->height << " " << i->BMI << std::endl ;

}

void Search( std::vector<std::unique_ptr<PatientInfo>>& patients, std::string& option ) {

    std::cout << "Search Results for :" << std::endl ;

    for ( auto& i : patients )
        if ( (*i).name == option )
            std::cout << (*i).name << " " << (*i).age << " " << (*i).weight << " "
                << (*i).height << " " << (*i).BMI << std::endl ;

}

void ViewOption( const std::vector<std::unique_ptr<PatientInfo>>& patients, std::string& option ) {

    int num ;
    std::cin >> num ;

    std::vector<std::unique_ptr<PatientInfo>> view_patients ;

    view_patients.reserve(patients.size());
    for (auto &patient: patients) {
        view_patients.push_back(std::make_unique<PatientInfo>(*patient));
    }

    if ( option == ">" )
        view_patients.erase(std::remove_if(view_patients.begin(), view_patients.end(),
                                  [num](std::unique_ptr<PatientInfo>& a){return a->BMI < num;}), view_patients.end()) ;
    else if ( option == "<" )
        view_patients.erase(std::remove_if(view_patients.begin(), view_patients.end(),
                                           [num](std::unique_ptr<PatientInfo>& a){return a->BMI > num;}), view_patients.end()) ;

    std::cout << "Patients with BMI " << option << " :" << std::endl ;
    for ( auto& i : view_patients )
        std::cout << i->name << " " << i->age << " " << i->weight << " " << i->height << " " << i->BMI << std::endl ;

}

void Remove( std::vector<std::unique_ptr<PatientInfo>>& patients, std::string& option ) {

    int num ;
    std::cin >> num ;

    if ( option == ">" )
        patients.erase(std::remove_if(patients.begin(), patients.end(),
                                           [num](std::unique_ptr<PatientInfo>& a){return a->BMI > num;}), patients.end()) ;
    else if ( option == "<" )
        patients.erase(std::remove_if(patients.begin(), patients.end(),
                                           [num](std::unique_ptr<PatientInfo>& a){return a->BMI < num;}), patients.end()) ;

    std::sort(patients.begin(), patients.end(),
              [](std::unique_ptr<PatientInfo>& a, std::unique_ptr<PatientInfo>& b){return a->BMI > b->BMI;}) ;

    std::cout << "Remaining Patients after Removal:" << std::endl ;
    for ( auto& i : patients )
        std::cout << i->name << " " << i->age << " " << i->weight << " " << i->height << " " << i->BMI << std::endl ;

}
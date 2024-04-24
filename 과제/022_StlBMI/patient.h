#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

struct PatientInfo {
    std::string name ;
    int age ;
    int weight ;
    double height ;
    double BMI ;
};

std::unique_ptr<PatientInfo> createPatient(std::string& name, int age, int weight, double height) ;

void SortBMI(std::vector<std::unique_ptr<PatientInfo>>& patients, std::string& option) ;

void Search(std::vector<std::unique_ptr<PatientInfo>>& patients, std::string& option) ;

void ViewOption(const std::vector<std::unique_ptr<PatientInfo>>& patients, std::string& option) ;

void Remove(std::vector<std::unique_ptr<PatientInfo>>& patients, std::string& option) ;
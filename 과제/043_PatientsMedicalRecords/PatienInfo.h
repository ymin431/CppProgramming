#include <iostream>
#include <vector>

struct PatientInfo {

  std::string name;

  int age;

  float weight;

  float height;

  int date;

  float bmi;

};

using PatientList = std::vector<std::unique_ptr<PatientInfo>>;

using pPatient = std::unique_ptr<PatientInfo>;


#include "patient.cpp"

struct PatientInfo ;

enum class Command {

    CREATE,

    SORT,

    FIND,

    COUNT,

    REMOVE,

    EXIT

};



Command get_command(const std::string &command_str) {

    if (command_str == "CREATE") return Command::CREATE;

    if (command_str == "SORT") return Command::SORT;

    if (command_str == "FIND") return Command::FIND;

    if (command_str == "COUNT") return Command::COUNT;

    if (command_str == "REMOVE") return Command::REMOVE;

    return Command::EXIT;

}


int main() {

    std::cout << std::fixed ;
    std::cout.precision(2) ;

    PatientList patients;

    std::string command_str;

    Command command;



    while (std::cin >> command_str) {

        command = get_command(command_str);

        if (command == Command::EXIT) {

            break;

        }

        else if ( command == Command::CREATE ) {

            std::string newName;
            int newAge, newDate ;
            float newWeight, newHeight ;

            std::cin >> newName >> newAge >> newWeight >> newHeight >> newDate ;

            patients.push_back(create_patient(newName, newAge, newWeight, newHeight, newDate)) ;

        }

        else if ( command == Command::SORT ) {

            sort_patients(patients) ;
            print_patients(patients) ;

        }

        else if ( command == Command::FIND ) {

            std::string findName ;
            std::cin >> findName ;

            std::vector<std::unique_ptr<PatientInfo>> foundPatient = find_patient(patients, findName) ;

            if ( foundPatient.empty() )
                std::cout << "Patient not found" << std::endl ;
            else
                print_patients(foundPatient) ;

        }

        else if ( command == Command::COUNT ) {

            float cmpBmi ;
            std::cin >> cmpBmi ;

            int countPatient = count_patients(patients, cmpBmi) ;

            std::cout << countPatient << " patients with BMI greater than " << cmpBmi << std::endl ;

        }

        else if ( command == Command::REMOVE ) {

            int removeDate ;
            std::cin >> removeDate ;

            remove_old_records(patients, removeDate) ;
            print_patients(patients) ;

        }

    }

    return 0;

}


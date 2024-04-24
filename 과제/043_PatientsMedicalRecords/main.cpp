#include "patient.cpp"

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

  PatientList patients;

  std::string command_str;

  Command command;

  while (std::cin >> command_str) {

    command = get_command(command_str);

    if (command == Command::EXIT) {

      break;

    }

    else if ( command == Command::CREATE ) {

        std::string name ;
        int age, date ;
        float weight, height ;
        std::cin >> name >> age >> weight >> height >> date ;

        patients.push_back(create_patient(name, age, weight, height, date)) ;

    }

    else if ( command == Command::SORT ) {

        sort_patients(patients) ;

    }

    else if ( command == Command::FIND ) {

        std::string name ;
        std::cin >> name ;

        find_patient(patients, name) ;

        }

    else if ( command == Command::COUNT ) {

    }

    else if ( command == Command::REMOVE ) {

    }

  }

  for ( auto& i : patients )
      std::cout << i->name << " " << i->bmi << std::endl ;

  return 0 ;

}
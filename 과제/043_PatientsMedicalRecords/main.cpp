#include "patien.cpp"

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

    //implement your code

    return 0;

  }

}
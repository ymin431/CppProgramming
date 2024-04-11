#include <iostream>

enum TYPE {INT, LONG, FLOAT, DOUBLE};

TYPE getType(std::string type) {

  for (int i = 0; i < type.size(); i++) {
    type[i] = toupper(type[i]);

    if (type == "INT") return INT;
    else if (type == "LONG") return LONG;
    else if (type == "FLOAT") return FLOAT;
    else if (type == "DOUBLE") return DOUBLE;


  }

}

int main() {
  
  std::string str;
  std::cin >> str;
  TYPE type = getType(str);
  switch (type) {
      case INT:
          std::cout << "INT(" << type << ")" << std::endl;
          break;
      case LONG:
          std::cout << "LONG(" << type << ")" << std::endl;
          break;
      case FLOAT:
          std::cout << "FLOAT(" << type << ")" << std::endl;
          break;
      case DOUBLE:
          std::cout << "DOUBLE(" << type << ")" << std::endl;
          break;
  }

  return 0;

}
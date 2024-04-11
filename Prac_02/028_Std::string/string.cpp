#include <iostream>
#include <vector>

int countCharacter(const std::string& str, char ch) {

  int cnt = 0, i = 0;
  auto find_word = str.find(ch);

  while (find_word != std::string::npos) {

    i = find_word;
    cnt++;

    find_word = str.find(ch, i+1);

  }
  
  return cnt;

}



void toUpperCase(std::string& str) {

  for (int i = 0; i < str.size(); i++) {
    str[i] = toupper(str[i]);
  }
  
}



bool startsWith(const std::string_view str, const std::string_view prefix) {

  auto find_word = str.find(prefix);

  if (find_word != std::string::npos && find_word == 0)
    return 1;
  
  return 0;

}



int main() {

  std::vector<std::string> words = {"hello", "world", "example"};



  char characterToCount = 'l';

  for (const auto& word : words) {

    std::cout << "Count of '" << characterToCount << "' in \"" << word << "\": "

            << countCharacter(word, characterToCount) << std::endl;

  }

  std::cout << std::endl;



  for (auto& word : words) {

    toUpperCase(word);

    std::cout << "Modified string: " << word << std::endl;

  }

  std::cout << std::endl;



  std::string_view prefix = "EX";

  for (const auto& word : words) {

    std::cout << "Does \"" << word << "\" start with '" << prefix << "'? "

            << (startsWith(word, prefix) ? "Yes" : "No") << std::endl;

  }



  return 0;

}
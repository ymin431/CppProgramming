#include <iostream>
#include <vector>

int main() {

  int N;
  std::cin >> N;

  std::vector<int> vec(N);

  for (int i = 0; i < N; i++) 
    std::cin >> vec[i];
  
  int M, O;
  std:: cin >> M >> O;

  // A 명령 함수
  vec.erase(vec.begin()+M);

  // B 명령 함수
  int i = 0;
  while (i < vec.size()) {
    if (vec[i] == O)
      vec.erase(vec.begin()+i);
    else 
      i++;
  }

  std::cout << vec.size() << std::endl;

  for (int i = 0; i < vec.size(); i++)
    std::cout << vec[i] << " ";

  return 0;

}
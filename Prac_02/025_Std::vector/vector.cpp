#include <iostream>
#include <vector>

int main() {

  int N, M;

  std::cin >> N >> M;

  std::vector<std::vector<int>> vec(N);

  for (int i = 0; i < N; i++) {

    int O;
    std::cin >> O;
    vec[i].resize(O);

    for (int j = 0; j < O; j++)
      std::cin >> vec[i][j];

  }

  for (int i = 0; i < M; i++) {

    int I, J;
    std::cin >> I >> J;

    std::cout << vec[I][J] << std::endl;

  }

  return 0;

}
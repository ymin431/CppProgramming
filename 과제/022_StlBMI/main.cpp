#include "patient.cpp"

int main() {

  std::vector<PatienInfo> chart ;

  int num ;
  std::cin >> num ;

  for ( int i = 0 ; i < num ; i++ ) {
    std::unique_ptr<PatienInfo> patient ;
    std::cin >> (*patient).name >> (*patient).age >> (*patient).weight >> (*patient).height ;
    (*patient).BMI = (*patient).weight / pow((*patient).height, 2) ;
    chart.push_back((*patient)) ;
  }

  


  return 0 ;
  
}
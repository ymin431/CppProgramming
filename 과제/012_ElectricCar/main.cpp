#include <iostream>

int main( ) {

  double capacity ; // 배터리
  double efficiency ; // 전비
  double battery_level ; // 충전량(%)
  double distance ; // 목적지까지 거리

  // 출력할 때 소수점 자리 고정
  std::cout << std::fixed ;
  std::cout.precision( 2 ) ;


  // std::cin >> capacity >> efficiency >> battery_level >> distance ; // 값 입력
  capacity = 72.6 ;
  efficiency = 5.6 ;
  battery_level = 100 ;
  distance = 420 ;

  const double km_per_kW = capacity / 100 * efficiency ; // km_per_KW 계산식

  double now = 0 ; // 운전한 거리 (현재)

  // 충전량이 100% 일 때 출력
  std::cout << "Current battery level: " << battery_level << "%, after traveling " << now << " km." << std::endl ;


  while ( now < distance ) {

    battery_level-- ;

    now += km_per_kW ;

    // 충전량이 10 단위일 때 출력
    if ( static_cast<int>( battery_level ) % 10 == 0 ) 
      std::cout << "Current battery level: " << battery_level << "%, after traveling " << now << " km." << std::endl ;

    // 충전해야하는지 확인
    if ( static_cast<int>( battery_level ) / 10 == 2 && now / 100.0 >= static_cast<int>(now) / 100 ) {

      std::cout << "Current battery level: " << battery_level << "%, after traveling " << now << " km." << std::endl ;
      std::cout << "Battery at " << battery_level << "%, stopping at " ;

      // 충전 지역 정하기
      switch ( static_cast<int>( now ) / 100 ) {

        case 1 : 
          std::cout << "Gyeongsan for charging" << std::endl ;
          break;

        case 2 :
          std::cout << "Gimcheon for charging" << std::endl ;
          break;

        case 3 :
          std::cout << "Cheongju for charging" << std::endl ;
          break;

        case 4 :
          std::cout << "Anseong for charging" << std::endl ;
          break;

      }

      battery_level = 80 ;

    }

  }
  

  std::cout << battery_level << std::endl ;

  return 0 ;

}
// 72.6 5.6 100 420
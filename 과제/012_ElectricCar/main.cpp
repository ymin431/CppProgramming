#include <iostream>

int main( ) {

  double capacity ; // ���͸�
  double efficiency ; // ����
  double battery_level ; // ������(%)
  double distance ; // ���������� �Ÿ�

  // ����� �� �Ҽ��� �ڸ� ����
  std::cout << std::fixed ;
  std::cout.precision( 2 ) ;


  // std::cin >> capacity >> efficiency >> battery_level >> distance ; // �� �Է�
  capacity = 72.6 ;
  efficiency = 5.6 ;
  battery_level = 100 ;
  distance = 420 ;

  const double km_per_kW = capacity / 100 * efficiency ; // km_per_KW ����

  double now = 0 ; // ������ �Ÿ� (����)

  // �������� 100% �� �� ���
  std::cout << "Current battery level: " << battery_level << "%, after traveling " << now << " km." << std::endl ;


  while ( now < distance ) {

    battery_level-- ;

    now += km_per_kW ;

    // �������� 10 ������ �� ���
    if ( static_cast<int>( battery_level ) % 10 == 0 ) 
      std::cout << "Current battery level: " << battery_level << "%, after traveling " << now << " km." << std::endl ;

    // �����ؾ��ϴ��� Ȯ��
    if ( static_cast<int>( battery_level ) / 10 == 2 && now / 100.0 >= static_cast<int>(now) / 100 ) {

      std::cout << "Current battery level: " << battery_level << "%, after traveling " << now << " km." << std::endl ;
      std::cout << "Battery at " << battery_level << "%, stopping at " ;

      // ���� ���� ���ϱ�
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
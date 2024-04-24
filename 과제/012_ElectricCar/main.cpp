# include <iostream>

const double CriticalLevel = 20 ;

bool destination( double battery, double now, double km_per_kW, double distance ) ; // 목적지까지 배터리 계산

bool nextStation( double battery, double now, double km_per_kW ) ; // 다음 주유소까지 배터리 계산

int main() {

    // 소수점 둘째 자리로 고정
    std::cout << std::fixed ;
    std::cout.precision(2) ;

    double capacity ; // 배터리 용량
    double efficiency ; // 전비
    double battery_level ; // 충전량
    double distance ; // 목적지까지 거리

    std::cin >> capacity >> efficiency >> battery_level >> distance ; // 입력 받기

    const double km_per_kW = capacity / 100 * efficiency ;

    double now = 0 ;

    while ( now < distance ) {

        // battery_level이 10단위면 출력
        if (static_cast<int>(battery_level) % 10 == 0)
            std::cout << "Current battery level: " << battery_level << "%, after traveling " << now << " km." << std::endl ;

        int third_digit = static_cast<int>(now/100) * 100 ; // 백의 자리수
        double two_digits = now - third_digit ; // 십의 자리수부터

        if ( two_digits > 100 - km_per_kW) // km_per_kW에 따라 발생하는 오차범위 없애기
            third_digit += 100 ;

        // 현재 배터리가 critical level보다 높음 && 다음 정류장까지 가면 배터리가 critical level보다 낮음 && 오차범위 && 목적지까지 배터리가 critical level보다 낮음
        if ( battery_level > CriticalLevel && nextStation(battery_level, now, km_per_kW)
             && ( two_digits < km_per_kW || two_digits > 100 - km_per_kW ) && destination(battery_level, now, km_per_kW, distance) ) {

            std::cout << "Current battery level: " << battery_level << "%, after traveling " << now << " km." << std::endl ;
            std::cout << "Battery at " << battery_level << "%, stopping at " ;

            switch ( third_digit ) {
                case 100: { std::cout << "Gyeongsan for charging." << std::endl ; break ; }
                case 200: { std::cout << "Gimcheon for charging." << std::endl ; break ; }
                case 300: { std::cout << "Cheongju for charging." << std::endl ; break ; }
                case 400: { std::cout << "Anseong for charging." << std::endl ; break ; }
                default: { std::cout << "wrong place." << std::endl ; break ; }
            }

            now = third_digit ;
            battery_level = 80 ;
            std::cout << "Current battery level: " << battery_level << "%, after traveling " << now << " km." << std::endl ;

        }

        battery_level-- ;
        now += km_per_kW ;

    }

    std::cout << "Arrived in Seoul with " << battery_level << "% battery remaining." << std::endl ;

    return 0 ;

}

bool destination( double battery, double now, double km_per_kW, double distance ) {

    while ( now < distance ) {
        battery-- ;
        now += km_per_kW ;
    }

    if ( battery < CriticalLevel )
        return true;
    else
        return false ;

}

bool nextStation( double battery, double now, double km_per_kW ) {

    int now_third_digit = static_cast<int>(now/100) * 100 ;
    double two_digits = now - now_third_digit ;
    double target = now_third_digit ;

    if ( two_digits > 100 - km_per_kW ) {
        target += 200 ;
        now_third_digit += 100 ;
    }
    else {
        target += 100;
    }

    while ( now_third_digit != target && ( two_digits > km_per_kW || two_digits < 100 - km_per_kW ) ) {

        battery-- ;
        now += km_per_kW ;
        now_third_digit = static_cast<int>(now/100) * 100 ;
        two_digits = now - now_third_digit ;
        if ( two_digits > 100 - km_per_kW )
            now_third_digit += 100 ;

    }

    if ( battery < CriticalLevel )
        return true;
    else
        return false ;

}
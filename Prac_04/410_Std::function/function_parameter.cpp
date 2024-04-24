#include "Champion.h"

int main( ) {

    auto champions = createChampion() ;

    std::string input ;
    getline(std::cin, input) ;

    auto breakpoint = input.find(':') ;

    std::string key = input.substr(0,breakpoint) ;
    int value = stoi(input.substr(breakpoint + 1)) ;

    std::function<std::vector<Champion>(std::vector,int)>

    if ( key == "health" )
        auto condition = findChampionMoreThanHealth ;
    else if ( key == "attack" )
        auto condition = findChampionMoreThanAttack ;

    auto championsWithCondition = findChampionWithCondition(champions, [condition, value, champions](const Champion& champ){
        return condition(champions, value).size() > 0 ;
    }) ;

    printChampion(championsWithCondition) ;


    return 0 ;

}
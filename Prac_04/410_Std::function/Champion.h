#include <iostream>
#include <string>
#include <vector>
#include <functional>

struct Champion {

    std::string name;
    int health;
    int attack;

};
// bool
auto findChampionMoreThanHealth(std::vector<Champion> champions, int health) {



    return 1 ;

}

auto findChampionMoreThanAttack(std::vector<Champion> champions, int attack) {


}

auto findChampionWithCondition(std::vector<Champion> champions, std::function<bool(Champion)> condition) {



}

void printChampion(const std::vector<Champion> champions) {

    for ( const auto& i : champions )
        std::cout << i.name << " " << i.health << " " << i.attack << std::endl ;

}

std::vector<Champion> createChampion() {
    std::vector<Champion> champions;
    Champion tryndamere{"Tryndamere", 625, 72};
    Champion kled{"Kled", 740, 35};
    Champion garen{"Garen", 620, 66};
    champions.push_back(tryndamere);
    champions.push_back(kled);
    champions.push_back(garen) ;
    return champions;
}
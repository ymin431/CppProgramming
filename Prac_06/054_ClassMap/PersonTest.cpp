#include "Person.h"

int main() {

    std::map<std::string, Person> phone_book ;

    int input_num ;
    std::cin >> input_num ;

    for ( int i = 0 ; i < input_num ; i++ ) {

        std::string name, number ;
        std::cin >> name >> number ;

        Person person {name, number} ;

        std::pair<std::string, Person> info = {name, person} ;

        if ( !phone_book.count(name) )
            phone_book.insert(info) ;

    }

    std::string func ;

    while ( std::cin >> func ) {

        if ( func == "QUI"
            break ;

        else if ( func == "ADD" ) {

            std::string name, number ;
            std::cin >> name >> number ;

            Person person {name, number} ;

            std::pair<std::string, Person> info = {name, person} ;

            if ( !phone_book.count(name) )
                phone_book.insert(info) ;

        }

        else if ( func == "DEL" ) {

            std::string del_name ;
            std::cin >> del_name ;

            auto del_it = phone_book.erase(del_name);

        }

        else if ( func == "MOD" ) {

            std::string mod_name, mod_number ;
            std::cin >> mod_name >> mod_number ;

            phone_book.at(mod_name).Person::modifyNumber(mod_number) ;

        }

        else if ( func == "FIN" ) {
            std::string fin_name ;
            std::cin >> fin_name ;

            auto fin_it = phone_book.find(fin_name) ;

            fin_it->second.print() ;

        }

    }

    for ( auto i : phone_book )
        i.second.print() ;

    return 0 ;

}
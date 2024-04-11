#include <iostream>
#include <map>
#include <regex>
#include <vector>
#include <algorithm>

int main() {

    std::string str ;
    std::map<std::string, size_t> words ;
    int cnt = 0 ;

    while ( std::cin >> str && str != "^" ) {

        std::transform(str.begin(), str.end(), str.begin(), [](char c) { return std::tolower(c); }); // changed to std::tolower

        std::string filtered = std::regex_replace(str, std::regex("[.|,|:|;| ]"), "");

        auto search = words.find(filtered);

        if ( search != words.end() )
            words[filtered]++;
        else
            words.insert(std::make_pair(filtered, 1)); // changed to std::make_pair

        cnt++ ;

    }

    std::cout << "#Words: " << words.size() << std::endl ;

    std::vector<std::pair<std::string, int>> vec_words(words.begin(), words.end()) ;
    std::sort(vec_words.begin(), vec_words.end(), [](std::pair<std::string, int> a, std::pair<std::string, int> b) { return a.second > b.second; }); // removed extra space

    std::cout << "Top 5 Word Frequencies" << std::endl ;

    for ( int i = 0 ; i < 5 ; i++ )
        std::cout << i+1 << " " << vec_words[i].first << " : " << vec_words[i].second  << std::endl ;

    std::cout << "Find Word Frequencies" << std::endl ;

    std::string search ;

    while ( std::cin >> search ) {

        if ( search == "QUIT" ) {
            std::cout << "\nBye!" << std::endl ;
            break ;
        }

        std::transform(search.begin(), search.end(), search.begin(), [](char c) { return std::tolower(c); }); // changed to std::tolower

        auto it = words.find(search) ;
        if ( it != words.end() )
            std::cout << search << ": " << it->second << std::endl ;
        else
            std::cout << search << ": " << 0 << std::endl ;

    }

    return 0 ;

}

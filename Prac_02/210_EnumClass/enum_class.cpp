#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <numeric>
#include <string>
#include <algorithm>

enum class Genre { Action, Comedy, Drama, Romance, SciFi } ;
enum class StarRating { OneStar, TwoStars, ThreeStars, FourStars, FiveStars, Unrated } ;

struct Movie {
    std::string title ;
    Genre genre ;
    StarRating rating ;
};

// StarRating 관련 함수
StarRating stringToStarRating( const std::string& stars ) ; // 문자열 -> enum
int ratingToInt( StarRating rating ) ; // enum -> 정수
StarRating intToRating ( int rating ) ; // 정수 -> enum

// Genre 관련 함수
Genre stringToGenre( const std::string& genre ) ; // 문자열 -> enum
std::string genreToString( Genre genre ) ; // enum -> 정수


int main() {

    std::vector<Movie> movies ;
    Movie movie ;
    std::string str_genre ;
    std::string str_stars ;

    std::map<std::string, Genre> map_genre ; // 장르
    std::map<std::string, StarRating> map_rating ; // 평균 별점
    std::map<std::string, int> map_num ; // 리뷰 개수

    while ( getline(std::cin, movie.title, '\n') ) {

        // "q" 입력 받으면 종료
        if ( movie.title == "q" ) break ;

        getline(std::cin, str_genre, '\n') ;
        getline(std::cin, str_stars, '\n') ;

        movie.genre = stringToGenre(str_genre) ;
        movie.rating = stringToStarRating( str_stars) ;

        movies.push_back(movie) ;

    }

    std::sort(movies.begin(), movies.end(), [](Movie& a, Movie& b){return a.title < b.title;}) ;

    std::string tmp_title = movies[1].title ; // title과 비교를 위한 temp 변수
    std::vector<int> vec_rating ; // title이 바뀌기 전까지 별점들 저장할 벡터

    Movie empty = {"", Genre::Action, StarRating::Unrated};
    movies.push_back(empty) ;

    for ( int i = 0 ; i < movies.size() - 1 ; i++ ) {

        vec_rating.push_back(ratingToInt(movies[i].rating)) ;

        if ( movies[i].title != movies[i+1].title ) {

            int sum = std::accumulate(vec_rating.begin(), vec_rating.end(), 0) ;
            int avg = static_cast<int>(sum / vec_rating.size()) ;

            map_genre[movies[i].title] = movies[i].genre ;
            map_rating[movies[i].title] = intToRating(avg) ;
            map_num[movies[i].title] = static_cast<int>(vec_rating.size()) ;

            vec_rating.clear() ;

        }

    }

    auto itg = map_genre.begin() ; // 장르 이터레이터
    auto itr = map_rating.begin() ; // 평균 별점 이터레이터
    auto itn = map_num.begin() ; // 별점 개수 이터레이터

    while ( itg != map_genre.end() && itr != map_rating.end() && itn != map_num.end() ) {

        std::cout << itg->first << ": " << itn->second << " ratings, "
                  << "average rating " << ratingToInt(itr->second) << " stars, "
                  << "genre: " << genreToString(itg->second) << std::endl ;
        ++itg ;
        ++itr ;
        ++itn ;

    }

    return 0 ;

}

StarRating stringToStarRating( const std::string& stars ) {

    static const std::unordered_map<std::string, StarRating> ratingsMap = {

            {"★★★★★", StarRating::FiveStars},

            {"★★★★☆", StarRating::FourStars},

            {"★★★☆☆", StarRating::ThreeStars},

            {"★★☆☆☆", StarRating::TwoStars},

            {"★☆☆☆☆", StarRating::OneStar}

    } ;

    auto it = ratingsMap.find(stars) ;

    if (it != ratingsMap.end()) {

        return it->second;

    } else {

        return StarRating::Unrated;

    }

}

int ratingToInt( StarRating rating ) {

    switch (rating) {

        case StarRating::OneStar: return 1 ;

        case StarRating::TwoStars: return 2 ;

        case StarRating::ThreeStars: return 3 ;

        case StarRating::FourStars: return 4 ;

        case StarRating::FiveStars: return 5 ;

        case StarRating::Unrated: return 0 ;

        default: {std::cerr << "Invalid Rating"; return 0;}

    }
}

StarRating intToRating ( int rating ) {

    switch (rating) {

        case 1: return StarRating::OneStar ;

        case 2: return StarRating::TwoStars ;

        case 3: return StarRating::ThreeStars ;

        case 4: return StarRating::FourStars ;

        case 5: return StarRating::FiveStars ;

        case 0: return StarRating::Unrated ;

        default: {std::cerr << "Invalid Rating"; return StarRating::Unrated;}

    }

}

Genre stringToGenre( const std::string& genre ) {

    static const std::unordered_map<std::string, Genre> genreMap = {

            {"Action", Genre::Action},

            {"Comedy", Genre::Comedy},

            {"Drama", Genre::Drama},

            {"Romance", Genre::Romance},

            {"SciFi", Genre::SciFi}

    } ;

    auto it = genreMap.find(genre) ;

    return it->second ;

}

std::string genreToString( Genre genre ) {

    switch (genre) {

        case Genre::Action: return "Action" ;

        case Genre::Comedy: return "Comedy" ;

        case Genre::Drama: return "Drama" ;

        case Genre::Romance: return "Romance" ;

        case Genre::SciFi: return "SciFi" ;

        default: {std::cerr << "Invalid Genre"; return "None";}

    }

}
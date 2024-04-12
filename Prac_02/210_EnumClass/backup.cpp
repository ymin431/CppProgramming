#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <unordered_map>

enum class Genre { Action, Comedy, Drama, Romance, SciFi} ;
enum class StarRating { OneStar, TwoStars, ThreeStars, FourStars, FiveStars, Unrated } ;

struct Movie {

    std::string title ;
    Genre genre ;
    StarRating rating ;

} ;

int ratingToInt( StarRating rating ) ; // 별점 숫자로 변환하는 함수
std::string genreToString( Genre genre ) ; // 장르 string으로 변환하는 함수
StarRating stringToStarRating( const std::string& stars ) ; // 문자열로 된 별점 enum으로 변환하는 함수
Genre stringToGenre( const std::string& genre ) ; // 문자열로 된 장르 enum으로 변환하는 함수
bool compare(const Movie& a, const Movie& b) ; // 영화 제목을 기준으로 정렬하는 함수

int main() {

    std::vector<Movie> movies ; // map은 중복 Key 못받으니 일단 입력한거 모아보기

    std::map<std::string, Genre> movieGenre ; // 영화 장르를 저장한 map

    std::map<std::string, std::vector<int>> movieRatings ; // 영화에 달린 리뷰를 벡터로 만든 뒤 map에 저장

    Movie review ;
    std::string title ;
    std::string genre_str ; // 문자열로 입력받은 genre
    std::string rating_str ; // 문자열로 입력받은 rating


    while (1) {

        getline( std::cin, title, '\n') ; // getline은 공백을 포함하여 입력값을 받기 위해 사용

        if ( title == "q" ) break ; // q가 입력되면 영화 입력받기 종료

        getline( std::cin, genre_str, '\n') ;
        getline( std::cin, rating_str, '\n') ;

        review.title = title ; // review 구조체에 title 저장
        review.genre = stringToGenre( genre_str ) ; // review 구조체에 genre를 enum으로 변환 후 저장
        review.rating = stringToStarRating( rating_str ) ; // review 구조체에 rating을 enum으로 변환 후 저장

        movies.push_back(review) ; // 정보를 모두 입력 받은 구조체를 movies 벡터에 넣기

    }

    std::sort( movies.begin(), movies.end(), compare ) ; // movies 벡터 오름차순 정렬

    std::vector<int> rating_vec ; // movieRating의 value에 넣기위해 선언된 비어있는 구조체

    for ( auto i : movies ) {

        if ( title != i.title ) {
            movieRatings[title] = rating_vec ; // movieRating의 i.title key값에 value 넣기
            rating_vec.clear() ; // rating_vec 벡터 초기화
            title = i.title ; // 이전 타이틀 초기화
        }

        movieGenre[i.title] = i.genre ;
        rating_vec.push_back(ratingToInt(i.rating)) ;

    }

    movieRatings[title] = rating_vec ; // 마지막 title에 벡터 넣기

    auto it_g = movieGenre.begin();
    auto it_r = movieRatings.begin();

    while (it_g != movieGenre.end() && it_r != movieRatings.end()) {

        auto average = (std::accumulate(it_r->second.begin(), it_r->second.end(), 0.0))/it_r->second.size() ;
        std::cout << it_g->first << ": " << it_r->second.size() << " ratings, average rating " << average
                  << " stars, genre: " << genreToString(it_g->second) << std::endl ;

        ++it_g ;
        ++it_r ;
    }

}

int ratingToInt( StarRating rating ) {

    switch ( rating ) {

        case StarRating::OneStar: return 1 ;

        case StarRating::TwoStars: return 2 ;

        case StarRating::ThreeStars: return 3 ;

        case StarRating::FourStars: return 4 ;

        case StarRating::FiveStars: return 5 ;

        default: {std::cerr << "Invalid Rating"; return 0;}

    }

}

std::string genreToString( Genre genre ) {

    switch ( genre ) {

        case Genre::Action: return "Action" ;

        case Genre::Comedy: return "Comedy" ;

        case Genre::Drama: return "Drama" ;

        case Genre::Romance: return "Romance" ;

        case Genre::SciFi: return "SciFi" ;

        default: {std::cerr << "Invalid Genre"; return 0;}

    }

}

StarRating stringToStarRating( const std::string& stars ) {

    static const std::unordered_map<std::string, StarRating> ratingsMap = {

            {"★★★★★", StarRating:: FiveStars},

            {"★★★★☆", StarRating::FourStars},

            {"★★★☆☆", StarRating::ThreeStars},

            {"★★☆☆☆", StarRating::TwoStars},

            {"★☆☆☆☆", StarRating::OneStar}

    } ;



    auto it = ratingsMap.find(stars) ;

    if (it != ratingsMap.end()) {

        return it->second;

    } else {

        return StarRating::Unrated ;

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



    auto it = genreMap.find( genre ) ;

    if (it != genreMap.end()) {

        return it->second;

    }

}

bool compare(const Movie& a, const Movie& b) {

    return a.title < b.title ;

}
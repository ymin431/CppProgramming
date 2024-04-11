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

int ratingToInt( StarRating rating ) ;
std::string genreToString( Genre genre ) ; 
StarRating stringToStarRating( const std::string& stars ) ;
Genre stringToGenre( const std::string& genre ) ; 
bool compare(const Movie& a, const Movie& b) ;

int main() {

  std::vector<Movie> movies ;

  std::map<std::string, Genre> movieGenre ; 

  std::map<std::string, std::vector<int>> movieRatings ;

  Movie review ;
  std::string title ;
  std::string genre_str ;
  std::string rating_str ;


  while (1) {

    getline( std::cin, title, '\n') ;

    if ( title == "q" ) break ; 
    
    getline( std::cin, genre_str, '\n') ;
    getline( std::cin, rating_str, '\n') ;

    review.title = title ;
    review.genre = stringToGenre( genre_str ) ; 
    review.rating = stringToStarRating( rating_str ) ; 

    movies.push_back(review) ; 

  }

  std::sort( movies.begin(), movies.end(), compare ) ;

  std::vector<int> rating_vec ;

  for ( auto i : movies ) {

    if ( title != i.title ) {
      movieRatings[title] = rating_vec ;
      rating_vec.clear() ; 
      title = i.title ; 
    }
    
    movieGenre[i.title] = i.genre ;
    rating_vec.push_back(ratingToInt(i.rating)) ;

  }

  movieRatings[title] = rating_vec ; 

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
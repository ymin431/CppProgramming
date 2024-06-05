#ifndef ACCUMULATE_H
#define ACCUMULATE_H

// typename 대신 class 사용 가능, T, U는 관습적인 것 (변수명)
template<typename T, typename U>
U my_accumulate(T begin, T end, U init){
    while (begin != end) {
        init += *begin ;
        begin++ ;
    }
    return init ;
}

#endif //ACCUMULATE_H

#include <iostream>
#include <stack>

int main() {

    int N ;
    std::cin >> N ;

    std::stack<int> s;

    for (int i = 0 ; i < N ; i++) {
        std::string func ;
        std::cin >> func ;

        if (func == "push") {
            int num ;
            std::cin >> num ;
            s.push(num) ;
        }
        else if (func == "size") {
            std::cout << s.size() << std::endl ;
        }
        else if (func == "pop") {
            if (!s.empty()) {
                std::cout << s.top() << std::endl ;
                s.pop();
            }
            else
                std::cout << -1 << std::endl ;
        }
        else if (func == "empty") {
            std::cout << s.empty() << std::endl ;
        }

    }

    return 0 ;

}
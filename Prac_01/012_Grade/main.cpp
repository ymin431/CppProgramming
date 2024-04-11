#include <iostream>
#include <vector>
#include <utility>

int main() {

    int num, score;
    int high_score = 0, sum = 0;
    std::string name, high_name;

    std::vector<std::string> st_name;
    std::vector<int> st_score;

    std::cout << "# of students:" << std::endl;
    std::cin >> num;

    for (int i = 1; i <= num; i++) {
        std::cout << "name & score of student " << i << std::endl;
        std::cin >> name >> score;
        st_name.push_back(name);
        st_score.push_back(score);
        sum += score;
        if (score > high_score) {
            high_score = score;
            high_name = name;
        }
    }

    std::cout.precision(1);
    std::cout << "The average score of the students is " << sum/num << std::endl;
    std::cout << "The student with the highest score is " << high_name << " with a score of " << high_score << std::endl;

    return 0;
    
}
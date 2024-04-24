#include "patient.cpp"

int main() {

    std::vector<std::unique_ptr<PatientInfo>> patients ;

    int num_input ;
    std::cin >> num_input ;

    for ( int i = 0 ; i < num_input ; i++ ) {

        std::string name ;
        int age, weight ;
        double height ;

        std::cin >> name >> age >> weight >> height ;

        patients.push_back(createPatient(name, age, weight, height)) ;

    }

    std::cout << std::endl ;

    std::string func, opt = "Kevin";

    while ( std::cin >> func ) {

        std::cin >> opt;

        if ( func == "sort:" )
            SortBMI(patients, opt) ;
        else if ( func == "search:")
            Search(patients, opt) ;
        else if ( func == "list:")
            ViewOption(patients, opt) ;
        else if ( func == "remove:")
            Remove(patients, opt) ;

        std::cout << std::endl ;

    }

    return 0 ;

}
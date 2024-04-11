struct STUDENT {

    std::string name;

    int age;

};



std::unique_ptr<STUDENT> createStudent (std::string name, int age) {

    auto student = std::unique_ptr<STUDENT> (new STUDENT());

    student->name = name;

    student->age = age;

    return student;

}



void printStudentInfo(const STUDENT& student){

    std::cout << student.name << " " << student.age << std::endl;

}
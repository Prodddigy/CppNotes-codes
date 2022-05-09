#include <iostream>
#include <vector>
#include <algorithm>


auto printV(std::vector<int> const& z) -> void {
            //const - make it read only do not modify it
            //like final from java
    for(int a : z)
    {
        std::cout << a << " ";
    }
    std::cout << '\n';
   // z.clear();
}

auto modify(int& z) ->void {
    z=10;
}
auto modify(std::vector<int>& z) -> void {
    z.push_back(123);
}

struct student{
    std::string name;
    std::string surname;
    int s;
/*
    student(std::string name, std::string surname, int s )
    {
        name = name;
        surname = surname;
        s=s;
    }
    */

student(std::string name, std::string surname, int s)
: name(name), surname(surname), s(s)
    {
    std::cout << "student created \n";
    }

    student(student const& other)
    : name(other.name), surname(other.surname), s(other.s)
    {
        std::cout << "student copied \n";
    }

    ~student()
    {
    std::cout << "student destroyed \n";
    }
};

auto count_students_with_equal_name(std::vector<student> const& students, student const& to_search) {

    return std::ranges::count_if(students,[to_search](student const& s){
        return s.name == to_search.name;
    });
}

int main() {
    auto vec = std::vector<int>{1,2,3,1,2,3,4};

   // auto x= 5;
  //  modify(x);
   // auto& ref = x;
  //  ref = 10;

    //std::cout << x << '\n';

   // printV(vec);
  //  std::cout<< '\n';
  //  modify(vec);

   // printV(vec);
  //  printV(vec);

  ////  auto stud = student("Leo", "Da Vinci",66);

  ////  auto copy = stud;
 // stud.name = "Leonardo";
  ////std::cout << stud.name << '\n';

  ////  std::cout << copy.name << '\n';


   //// stud.name = "John";

////    std::cout << stud.name << '\n';
  ////  std::cout << copy.name << '\n';


    auto students = std::vector<student> {
            student("Damian", "Da Vinci",66),
            student("Leo", "Da Vinci",66),
            student("Ola", "Da Vinci",66),
            student("Leo", "Da Vinci",66),
            student("Saba", "Da Vinci",66),
            student("Saba", "Da Vinci",66)

    };
    std::cout << "copies ^ "<< '\n';

  std::cout << "how many saba's? :" <<  count_students_with_equal_name(students,student("Saba", "Da Vinci",66)) << '\n';

    std::cout << "copies ^ " << '\n';
}

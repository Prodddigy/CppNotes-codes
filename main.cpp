#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct student
{
    std::string name;
    std::string surname;
    int s;
};
int main() {

   // auto s1 = student("Michel","Smith",1234);
    //std::cout << s1.name << ' ' << s1.surname << ' ' << s1.s;

    auto students = std::vector<student>{
            student("Michel","Smith",1234),
            student("Ada","Smith",1334),
            student("Joe","Smith",1884)

    };

/*
    std::ranges::sort(students,[](student lhs, student rhs)->bool
    {
        return lhs.s > rhs.s;
    });




    for(auto sud : students)
    {
        std::cout << sud.name << ' ' << sud.surname << ' ' << sud.s<<'\n';
    }

    auto student_with_greatest_s = std::ranges::max(students,[](student lhs, student rhs)->bool
    {
        return lhs.s > rhs.s;
    });

    std::cout <<'\n' << student_with_greatest_s.name;
*/

/*
    std::cout << std::ranges::count_if(students, [](student s) -> bool {
       return s.name.size() <= 3;
    });
    */

/*
    auto vec = std::vector<int>{1,2,9,3,4,7};


    std::ranges::transform(vec, vec.begin(),[](int x)->int
    {
        return x *10;
    });

    for (auto e : vec)
    {
        std::cout << e << " ";
    }
*/
    auto student_with_greatest_s = std::ranges::max(students,{},[](student stud) -> int
    {
        return stud.s;
    }
    );

    std::cout << student_with_greatest_s.name;


}

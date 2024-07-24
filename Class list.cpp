#include <iostream>
#include "List.hpp"


int main(){
    setlocale(LC_ALL, "ru");
   


    List<int> List1;
    List1.push_back(15);
    List1.push_back(7);
    List1.push_front(42);
   // List1.clear();
    List1.print();
   //  List1.reverse_print();

    // List1.pop_back();
    List1.pop_front();
    List1.print();

    List<std::string>list2{ "Hello", "Wo", "Or", "App" };
    list2.print();


    return 0;
}

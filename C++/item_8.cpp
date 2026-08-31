#include <iostream>
#include <string>
#include <string_view>
#include <charconv>
#include <print>
#include <vector>
#include <memory> 


class Myclass {

public: 
   Myclass(int value);
   void set_value (int valuse);
   int get_value () const;
private: 
   int  m_value = { 0 }; 
}; 

Myclass::Myclass(int value){

    set_value(value);
    std::print("Object constructor has been call\n");
} 
void Myclass::set_value(int value) {
    m_value = value;
} 
int Myclass::get_value() const {
    return m_value;
} 
int main () {
    
auto Myclass_pointer { std::make_unique<Myclass>(5) }; 

Myclass* Myclass_pointer_2 { new Myclass { 20 } };

Myclass* Myclass_pointer_3 { nullptr };
Myclass_pointer_3 = new Myclass { 30 }; 


std::print("Pointer_1 value {}\n",Myclass_pointer->get_value()); 

std::print("Pointer_2 value {}\n",Myclass_pointer_2->get_value()); 

std::print("Pointer_3 value {}\n",Myclass_pointer_3->get_value()); 


delete Myclass_pointer_2;
Myclass_pointer_2 = nullptr;
delete Myclass_pointer_3;
Myclass_pointer_3 = nullptr;


  return 0;
}

#include <print>
#include <iostream>
#include <vector>
#include <charconv>
#include <string>
#include <string_view>
#include <memory>
#include <utility>
#include <algorithm> 

class Myclass {

    public:
        Myclass()  = default;
        Myclass (int value) {
            set_val(value);
            std::print("base class construction complete\n"); 
        }  
        void set_val(int value) { m_value = value; }
        int get_val() const { return m_value; } 
    private: 
        int m_value {0};     
};
struct A : Myclass {
    A(int value) : Myclass(value) 
    {
        std::print("A construction complete\n");
    } 
    int get_val_A() const {   return get_val();  } 
}; 

struct B : A {
    B(int value) : A(value)
    {
        std::print("B constuction complete\n"); 
    }
    int get_val_B() const { return get_val(); }
};
struct C : B {
    C(int value) : B(value)  {
        std::print("C construction complete\n"); 
    } 
}; 

int main () {
using namespace std;
  
  Myclass obj_1 { 0 }; 
  A a { 20  };
  B b { 20 };
  C c {0}; 
  print("{}\n",a.get_val_A());
  print("{}\n",b.get_val_B());
  print("{}\n",c.get_val()); 
   return 0;
}






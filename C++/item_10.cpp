#include <iostream>
#include <string_view>
#include <string>
#include <memory>
#include <charconv> 
#include <print>


class Myclass {
    
public:
       Myclass(int value,std::string text) : m_value(value) , m_string(text) 
    {
        std::print("parameter constructor called\n");
    }    
       Myclass(const Myclass& value):
           m_value(value.m_value), m_string(value.m_string) 
    {
        std::print("Copy constructor had been call\n");
    } 
private:
       int m_value {0} ;
       std::string m_string;
}; 






int main () {
using namespace std;
    
   Myclass src {10 , "Top"};
   Myclass dest = src;
   




    return 0; 
} 

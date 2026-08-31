#include <iostream>
#include <format>
#include <string>
#include <string_view>
#include <charconv> 
#include <print>
class Spreadsheet_cell{

public:
    void set_value(double value);
    double get_value() const;

    void set_string(std::string_view value);
    std::string get_string() const;
private:
    double m_value { 0 } ;
    std::string double_to_string(double value) const; 
    double string_to_double(std::string_view value) const; 
};

void Spreadsheet_cell::set_value(double value){

         m_value = value; 

} 
double Spreadsheet_cell::get_value () const {

          return m_value;
       
} 
void Spreadsheet_cell::set_string(std::string_view value){
        
         m_value = string_to_double(value); 
}  
std::string Spreadsheet_cell::get_string() const {

         return double_to_string(m_value); 
}
std::string Spreadsheet_cell::double_to_string(double value) const {
        return std::to_string(value); 

} 
double Spreadsheet_cell::string_to_double(std::string_view value) const{

        double number  { 0 };
        std::from_chars(value.data(),value.data() + value.size(),number); 
        return number;
}

int main () {

    Spreadsheet_cell* myCellp { new Spreadsheet_cell { } };
    myCellp->set_value(3.7);
    std::print("cell 1: {} {}", myCellp->get_value(), myCellp->get_string());
    delete myCellp;
    myCellp = nullptr;

    return 0;
} 

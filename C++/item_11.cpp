#include <iostream>
#include <string_view>
#include <string>
#include <memory>
#include <charconv>
#include <print>
#include <initializer_list>
#include <vector>
#include <utility>


class Myclass {
public:
    Myclass() = default;
    Myclass(double val) : m_value(val){} 
    Myclass(int  in_width , int in_height);
    Myclass& get_value_at(int x , int y); 

    void set_cell_at(int x , int y ,const Myclass& cell); 
    ~Myclass();
private:
    bool inRange(int val , int upper) const {
        if (val < 0 || val >= upper){
            return false;
        }  
        return true;
    } 
    int m_width {0};
    int m_height {0};
    Myclass **ptr_cell {nullptr};
    float m_value{0.0};
};

Myclass::Myclass(int in_width , int in_height): m_width {in_width} , m_height {in_height}
{
    std::print("Memory allocation constructor call\n"); 
         ptr_cell = new Myclass* [m_width];
             for (int i {0}; i < m_width; i++){
                 ptr_cell[i] = new Myclass[m_height];
             }
     std::print("Memory allocation constructor run out of scope\n"); 

}

void Myclass::set_cell_at(int x , int y ,const Myclass& cell)
{
    if (!inRange(x,m_width) || !inRange(y,m_height)){
        std::print("Out  bound\n"); 
        return;
    } 
 ptr_cell[x][y] = cell;
}
Myclass& Myclass:: get_value_at(int x , int y)
{
static Myclass error_cell {-1.0};
    if (!inRange(x , m_width) || !inRange(y , m_height)){
        std::print("Out  bound\n");
        return error_cell;
    } 
return ptr_cell[x][y];
} 
Myclass::~Myclass() {
    for (int i {0}; i < m_width ; i++ ){
        delete [] ptr_cell[i];
    } 
    delete [] ptr_cell;
    ptr_cell = nullptr;
    std::print("obj have been destroy\n"); 
} 

int main() {
    using namespace std;
Myclass test (4 , 5);

    return 0;
}

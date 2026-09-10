#include <iostream>
#include <string_view>
#include <string>
#include <memory>
#include <charconv>
#include <print>
#include <initializer_list>
#include <vector>

class Myclass {
public:
    Myclass();
    Myclass(std::initializer_list<double> gpa);
    Myclass(double initial_value);
    Myclass(std::string initial_value);
    Myclass(const Myclass& src);
    Myclass(double initial_value, std::string in_string);

    void set_value(double in_value) { m_initial_value = in_value; }
    double get_value() const { return m_initial_value; }

    void set_string(std::string in_String) { m_string = std::move(in_String); }
    std::string get_String() const { return m_string; }

    void get_value_list() const;

private:
    double m_initial_value{0.00};
    std::string m_string;
    std::vector<double> m_value_list;
};

// 1. PRIMARY CONSTRUCTOR: Does the real assignment work for values
Myclass::Myclass(double initial_value, std::string in_string)
    : m_initial_value(initial_value), m_string(std::move(in_string)) {
    std::print("Two-arg constructor called\n");
}

// 2. DELEGATING CONSTRUCTOR: Default constructor forwards to primary with default arguments
Myclass::Myclass() 
    : Myclass(0.00, "") {
    std::print("Default constructor called (via delegation)\n");
}

// 3. DELEGATING CONSTRUCTOR: double constructor forwards to primary
Myclass::Myclass(double initial_value) 
    : Myclass(initial_value, "") {
    std::print("double constructor call (via delegation)\n");
}

// 4. DELEGATING CONSTRUCTOR: string constructor forwards to primary
Myclass::Myclass(std::string initial_value) 
    : Myclass(0.00, std::move(initial_value)) {
    std::print("String constructor call (via delegation)\n");
}

// Copy Constructor
Myclass::Myclass(const Myclass& src)
    : m_initial_value(src.m_initial_value), m_string(src.m_string), m_value_list(src.m_value_list) {
    std::print("copy constructor called\n");
}

// Initializer List Constructor
Myclass::Myclass(std::initializer_list<double> gpa) : m_value_list(gpa) {
    std::print("initializer_list constructor call\n");
}

void Myclass::get_value_list() const {
    for (auto val : m_value_list) {
        std::print("{}\n", val);
    }
}

int main() {
    using namespace std;

    Myclass obj_1(10.00);             // Uses () to avoid initializer_list hijack
    Myclass obj_2{"Top_2"};
    Myclass src{10, "Top"};
    Myclass dest = src;
    Myclass obj_3{3.42, 3.53, 3.70};
    Myclass obj_4 = obj_3;

    print("{}\n", obj_1.get_value());
    print("{}\n", obj_2.get_String());
    print("{} , {}\n", src.get_value(), src.get_String());
    print("{} , {}\n", dest.get_value(), dest.get_String());

    obj_3.get_value_list();
    obj_4.get_value_list();

    return 0;
} 

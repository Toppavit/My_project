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
    // 1. Direct initializers prevent hidden temporary object creation during new[]
    Myclass() : m_value_2{0.0} {}
    
    // 2. Write directly to m_value_2 so get_value() reads the actual assigned value
    Myclass(double val) : m_value_2{val} {}
    
    Myclass(int in_width, int in_height);
    ~Myclass();

    Myclass& get_value_at(int x, int y);
    void set_cell_at(int x, int y, const Myclass& cell);

    double get_value() const { return m_value_2; }
    void set_value(double val) { m_value_2 = val; }

private:
    bool inRange(int val, int upper) const {
        return (val >= 0 && val < upper);
    }

    int m_width{0};
    int m_height{0};
    Myclass** ptr_cell{nullptr};
    double m_value_2{0.0};
};

Myclass::Myclass(int in_width, int in_height)
    : m_width{in_width}, m_height{in_height} {
    std::print("Memory allocation constructor call\n");
    ptr_cell = new Myclass*[m_width];
    for (int i{0}; i < m_width; i++) {
        ptr_cell[i] = new Myclass[m_height];
    }
    std::print("Memory allocation constructor finished\n");
}

Myclass& Myclass::get_value_at(int x, int y) {
    static Myclass error_cell{-1.0};
    if (!inRange(x, m_width) || !inRange(y, m_height)) {
        std::print("Out of bounds\n");
        return error_cell;
    }
    return ptr_cell[x][y];
}

void Myclass::set_cell_at(int x, int y, const Myclass& cell) {
    if (!inRange(x, m_width) || !inRange(y, m_height)) {
        std::print("Out of bounds\n");
        return; // Fixed: return added to prevent bad access
    }
    ptr_cell[x][y] = cell;
}

Myclass::~Myclass() {
    if (ptr_cell != nullptr) {
        for (int i{0}; i < m_width; i++) {
            delete[] ptr_cell[i];
        }
        delete[] ptr_cell;
        ptr_cell = nullptr;
    }
    std::print("obj has been destroyed\n");
}

int main() {
    using namespace std;
    Myclass test(4, 5);

    // Populate values directly on existing grid cells without spawning temporaries
    for (int i{0}; i < 4; i++) {
        for (int j{0}; j < 5; j++) {
            test.get_value_at(i, j).set_value(static_cast<double>(i + j));
        }
    }

    // Print values cleanly
    for (int k{0}; k < 4; k++) {
        for (int l{0}; l < 5; l++) {
            std::print("{}\n", test.get_value_at(k, l).get_value());
        }
    }

    return 0;
}

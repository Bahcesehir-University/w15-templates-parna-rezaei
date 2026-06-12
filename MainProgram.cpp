#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
 
// ================================
// CLASS / TEMPLATE DEFINITIONS
// ================================
 
// ---- Group 1: Basic function template -------------------------------------
template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}
 
// ---- Group 2: Function template with multiple type parameters --------------
template <typename T1, typename T2>
auto addValues(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
}
 
// ---- Group 3: Class template ----------------------------------------------
template <typename A, typename B>
class Pair {
private:
    A first_;
    B second_;
 
public:
    // constructor
    Pair(A first, B second)
        : first_(first), second_(second) {
    }
 
    // getters
    A getFirst() const {
        return first_;
    }
 
    B getSecond() const {
        return second_;
    }
 
    // setters
    void setFirst(A value) {
        first_ = value;
    }
 
    void setSecond(B value) {
        second_ = value;
    }
 
    // swap values (assume A == B when called)
    void swapValues() {
        auto temp = first_;
        first_ = second_;
        second_ = temp;
    }
};
 
// ---- Group 4: Generic container -------------------------------------------
template <typename T>
class Box {
private:
    std::vector<T> items_;
 
public:
    // add item
    void add(const T& item) {
        items_.push_back(item);
    }
 
    // size
    int size() const {
        return static_cast<int>(items_.size());
    }
 
    // get item
    T get(int index) const {
        if (index < 0 || index >= size()) {
            throw std::out_of_range("Invalid index");
        }
        return items_[index];
    }
 
    // total
    T total() const {
        T sum = T();
 
        for (const auto& item : items_) {
            sum += item;
        }
 
        return sum;
    }
};
 
// ---- Group 5: Template specialization -------------------------------------
template <typename T>
int describe(const T& value) {
    return 1;
}
 
// Full specialization for std::string
template <>
int describe<std::string>(const std::string& value) {
    return 2 + static_cast<int>(value.length());
}
 
// ---- Group 6: Non-type template parameter ---------------------------------
template <typename T, int N>
class FixedArray {
private:
    T data_[N];
 
public:
    // default constructor
    FixedArray() {
        for (int i = 0; i < N; ++i) {
            data_[i] = T();
        }
    }
 
    // capacity
    int capacity() const {
        return N;
    }
 
    // set
    void set(int index, const T& value) {
        if (index < 0 || index >= N) {
            throw std::out_of_range("Invalid index");
        }
        data_[index] = value;
    }
 
    // at
    T at(int index) const {
        if (index < 0 || index >= N) {
            throw std::out_of_range("Invalid index");
        }
        return data_[index];
    }
};
 
// ================================
// FUNCTION IMPLEMENTATIONS / main
// ================================
 
int main() {
    std::cout << "=== C++ Templates Lab ===\n";
 
    std::cout << "maxValue(3, 7) = " << maxValue(3, 7) << "\n";
 
    return 0;
}

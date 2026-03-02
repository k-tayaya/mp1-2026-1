#include <iostream>

class LengthConverter {
private:
    double meters; 

public:
    LengthConverter() {
        meters = 1;
    }
    LengthConverter(double m) {
        meters = m;
    }
    void setMeters(double m) {
        meters = m;
    }
    double getMeters() {
        return meters;
    }

    double perevod(int len) {
        if (len == 1) return meters * 3.281;
        if (len == 2) return meters * 1.094;
        if (len == 3) return meters / 0.711;
        if (len == 4) return meters * 0.547;
    }

    void print() {
        std::cout << "Длина: " << meters << " м\n";
    }
};

int main() {
    LengthConverter length;

    length.setMeters(5); 
    length.print();

    std::cout << "Выберите единицы измерения для перевода: 1 – фут, 2 – ярд, 3 – аршин, 4 – сажень\n";
    int res;
    std::cin >> res;
    std::cout << length.perevod(res) << "\n";

    return 0;
}
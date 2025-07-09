#include "DynamicBuffer.hpp"
#include <iostream>
#include <utility>

int main() {
    DynamicBuffer buf1(5);
    for (size_t i = 0; i < buf1.getSize(); ++i) buf1.get()[i] = int(i);

    DynamicBuffer buf2 = std::move(buf1);
    std::cout << "buf1 size: " << buf1.getSize() << "\n";
    std::cout << "buf2: ";
    for (size_t i = 0; i < buf2.getSize(); ++i) std::cout << buf2.get()[i] << ' ';
    std::cout << "\n";

    buf2.resize(3);
    std::cout << "buf2 resized to " << buf2.getSize() << "\n";

    std::cout << "buf2: ";
    for (size_t i = 0; i < buf2.getSize(); ++i) std::cout << buf2.get()[i] << ' ';
    std::cout << "\n";
    
    return 0;
}
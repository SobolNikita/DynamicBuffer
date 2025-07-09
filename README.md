# DynamicBuffer

**Используемое**:

* C++17
* CMake
* Правило пяти (Rule of Five)
* Управление динамической памятью
* Семантика перемещения (move semantics)
* RAII

---

## Пример использования

```cpp
#include "DynamicBuffer.hpp"
#include <iostream>
#include <utility>

int main() {
    // Создаём буфер на 5 элементов и заполняем его значениями 0–4
    DynamicBuffer buf1(5);
    for (size_t i = 0; i < buf1.getSize(); ++i) 
        buf1.get()[i] = int(i);

    // Перемещаем данные из buf1 в buf2
    DynamicBuffer buf2 = std::move(buf1);
    std::cout << "buf1 size: " << buf1.getSize() << "\n";

    std::cout << "buf2: ";
    for (size_t i = 0; i < buf2.getSize(); ++i) 
        std::cout << buf2.get()[i] << ' ';
    std::cout << "\n";

    // Меняем размер буфера buf2 на 3
    buf2.resize(3);
    std::cout << "buf2 resized to " << buf2.getSize() << "\n";

    std::cout << "buf2: ";
    for (size_t i = 0; i < buf2.getSize(); ++i) 
        std::cout << buf2.get()[i] << ' ';
    std::cout << "\n";
    
    return 0;
}
```

**Ожидаемый вывод**:

```
buf1 size: 0
buf2: 0 1 2 3 4 
buf2 resized to 3
buf2: 0 1 2 
```

#include <cstddef>

class DynamicBuffer {
    size_t size_;
    int* data_;
public:
    // Выделяет массив из n элементов
    explicit DynamicBuffer(size_t n);

    // Rule of Five:
    ~DynamicBuffer();

    // Копирующий конструктор
    DynamicBuffer(const DynamicBuffer& other);

    // Копирующее присваивание
    DynamicBuffer& operator=(const DynamicBuffer& other);

    // Перемещающий конструктор
    DynamicBuffer(DynamicBuffer&& other) noexcept;

    // Перемещающее присваивание
    DynamicBuffer& operator=(DynamicBuffer&& other) noexcept;

    // Изменяет размер буфера
    void resize(size_t newSize);

    size_t getSize() const;
    int* get() const;
};
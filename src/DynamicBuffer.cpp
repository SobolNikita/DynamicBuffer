#include <cstddef>
#include "DynamicBuffer.hpp"

// Выделяет массив из n элементов
DynamicBuffer::DynamicBuffer(size_t n): size_(n), data_(new int[n]){
    //
}

// Rule of Five:
DynamicBuffer::~DynamicBuffer(){
    delete[] data_;
}

// Копирующий конструктор
DynamicBuffer::DynamicBuffer(const DynamicBuffer& other): size_(other.size_){
    int* newData = new int[size_];
    for(size_t i = 0; i < size_; ++i){
        newData[i] = other.data_[i];
    }
    data_ = newData;
}

// Копирующее присваивание
DynamicBuffer& DynamicBuffer::operator=(const DynamicBuffer& other){
    if (this != &other){
        int* newData = new int[other.size_];
        size_ = other.size_;
        for(size_t i = 0; i < size_; ++i){
            newData[i] = other.data_[i];
        }
        delete[] data_;
        data_ = newData;
    }
    return *this;
}

// Перемещающий конструктор
DynamicBuffer::DynamicBuffer(DynamicBuffer&& other) noexcept : size_(other.size_), data_(other.data_){
    other.size_ = 0;
    other.data_ = nullptr;
}

// Перемещающее присваивание
DynamicBuffer& DynamicBuffer::operator=(DynamicBuffer&& other) noexcept{
    if(this != &other){
        delete[] data_;
        data_ = other.data_;
        size_ = other.size_;
        other.data_ = nullptr;
        other.size_ = 0;
    }
    return *this;
}

// Изменяет размер буфера
void DynamicBuffer::resize(size_t newSize){
    int* newData = new int[newSize];
    size_ = newSize;
    for(size_t i = 0; i < (size_ < newSize ? size_ : newSize); ++i){
        newData[i] = data_[i];
    }
    delete[] data_;
    data_ = newData;
}

size_t DynamicBuffer::getSize() const{
    return size_;
}

int* DynamicBuffer::get() const{
    return data_;
}
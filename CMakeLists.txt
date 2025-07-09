cmake_minimum_required(VERSION 3.10)
project(DynamicBuffer) 

# Настройка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Настройка структуры проекта
set(INCLUDE_DIR include)               # Путь к заголовкам
set(SRC_DIR src)                       # Путь к исходникам

# Добавляем заголовочные файлы
include_directories(
    ${PROJECT_SOURCE_DIR}/${INCLUDE_DIR}
)

# Список исходных файлов
set(SOURCE_FILES
    ${SRC_DIR}/DynamicBuffer.cpp
    ${SRC_DIR}/main.cpp
)

# Создаем исполняемый файл
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
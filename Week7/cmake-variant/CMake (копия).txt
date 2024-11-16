cmake_minimum_required(VERSION 3.21)
project(FibonacciPlot)

set(CMAKE_CXX_STANDARD 17)

include_directories("include")

# Установка исходных файлов
set(SOURCE_FILES
    src/main.cpp
    src/fibonacci.cpp
)

# Создание исполняемого файла
add_executable(FibonacciPlot ${SOURCE_FILES})

# Настройка цели для очистки, не используя имя 'clean'
add_custom_target(my_clean COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_CURRENT_BINARY_DIR}/FibonacciPlot)


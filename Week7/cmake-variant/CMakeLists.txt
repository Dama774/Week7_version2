cmake_minimum_required(VERSION 3.16)
project(FibonacciPlot)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)


set(SOURCE_FILES
    src/main.cpp
    src/fibonacci.cpp
)

add_executable(FibonacciPlot ${SOURCE_FILES})
#target_link_libraries(FibonacciPlot GnuplotIostream)

#add_custom_target(my_clean COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_CURRENT_BINARY_DIR}/FibonacciPlot)

include_directories(libs/gnuplot/gnuplot-iostream)
add_subdirectory(libs/gnuplot/gnuplot-iostream)

# Директория с библиотеками
link_directories("/usr/lib/x86_64-linux-gnu") 
target_link_libraries(FibonacciPlot PRIVATE gnuplot_iostream)
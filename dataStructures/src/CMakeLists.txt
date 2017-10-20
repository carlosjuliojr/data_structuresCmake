###############################################################################
# @file CMakeLists.txt
# @project server for the simulations of processes
# @brief  CMakeLists.txt principal for  the simulations of processes
# @details this doc contains all requirements needs for the execution
# @author Ronald Sulbaran and Julio Jaimes R, ronaldanto03@gmail.com, carlosjuliojr@hotmail.com
# @date 15/10/2016
###############################################################################

set (PROJECT DateStructures)

cmake_minimum_required(VERSION 3.5)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)


 # Widgets finds its own dependencies (QtGui and QtCore).
find_package(Qt5Widgets PATHS "/home/julio/Qt/5.6/gcc_64/lib/cmake" REQUIRED)
add_definitions(-std=c++11 -g)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(../include)
include_directories(.)


set(VPA_Libs
     CMakeLists.txt

     ../include/singlelist.h
     ../include/doublylist.h
     ../include/stack.h
     ../include/queue.h

     singlelist.cpp

    )


add_library(virtualprofessorassistant ${VPA_Libs})

add_executable(${PROJECT} main.cpp)


target_link_libraries(${PROJECT} virtualprofessorassistant)
#qt5_use_modules(virtualprofessorassistant Widgets)
#qt5_use_modules(${PROJECT} Widgets)




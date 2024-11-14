cmake_minimum_required(VERSION 3.28.1)
project(projekt)

set(CMAKE_CXX_STANDARD 20)

set(MYSQL_CONNECTOR_CPP_DIR "C:\\Users\\krzys\\CLionProjects\\oop_project\\mysql-connector-c++-9.1.0-winx64")
include_directories(${MYSQL_CONNECTOR_CPP_DIR}/include/jdbc)
link_directories(${MYSQL_CONNECTOR_CPP_DIR}/lib64)

add_executable(projekt main.cpp)

target_link_libraries(projekt mysqlcppconn)

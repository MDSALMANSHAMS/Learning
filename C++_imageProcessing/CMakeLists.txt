cmake_minimum_required(VERSION 3.10)

project(C++_imageProcessing)

set(OpenCV_DIR "D:/opencv_cpp/opencv_repo/build")
find_package(OpenCV REQUIRED) 
   
add_executable(${PROJECT_NAME} main_1.cpp)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS}) 
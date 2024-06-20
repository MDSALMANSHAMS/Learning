cmake_minimum_required(VERSION 3.10)

project(C++_imageProcessing)

set(OpenCV_DIR "D:/opencv_cpp/opencv_repo/build")
find_package(OpenCV REQUIRED) 
   
add_executable(${PROJECT_NAME} 1_geometric_operations/5_shear.cpp)
 
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS}) 

# mingw32-make
# .\C++_imageProcessing.exe
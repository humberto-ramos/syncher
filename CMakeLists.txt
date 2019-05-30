cmake_minimum_required(VERSION 2.8.3)
project(syncher)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
        roscpp
        rospy
        std_msgs
        sensor_msgs
        cv_bridge
        image_transport
        message_generation
)



find_package( OpenCV REQUIRED )

catkin_package(CATKIN_DEPENDS)

# include directories
INCLUDE_DIRECTORIES(include ${catkin_INCLUDE_DIRS}
)

#link libraries
LIST(APPEND LINK_LIBS
        ${catkin_LIBRARIES}

        )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -I /usr/include/eigen3")

add_executable(${PROJECT_NAME} src/synchronizer.cpp
         include/synchronizer.h src/synchronizer_node.cpp)


add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(${PROJECT_NAME}  ${catkin_LIBRARIES} )
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
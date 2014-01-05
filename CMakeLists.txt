cmake_minimum_required(VERSION 2.8.3)
project(ahrs_client)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)

add_message_files(
	FILES
	Data.msg
)

generate_messages()
catkin_package(CATKIN_DEPENDS message_runtime)

ADD_SUBDIRECTORY(${ahrs_client_SOURCE_DIR}/src/Client_ahrs)
ADD_SUBDIRECTORY(${ahrs_client_SOURCE_DIR}/src/Common_ahrs)

include_directories(
  /src
  /src/Client_ahrs
  /src/Common_ahrs
)

add_library(ahrs_client
   src/functions.cpp
   src/Client_ahrs/RPCCallerAHRS.cpp
   src/Common_ahrs/Frames.cpp
)

add_executable(ahrs_client_node src/klient_ahrs.cpp)
target_link_libraries(ahrs_client_node
  ${catkin_LIBRARIES}
  RPCCallerAHRS
  Frames
)
add_dependencies(ahrs_client_node ahrs_client_generate_messages_cpp)


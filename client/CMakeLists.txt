# CMake最低版本
cmake_minimum_required (VERSION 3.17)

# 工程信息
project (grpc_client)

# 设置编译器版本
set (CMAKE_CXX_STANDARD 17)

# 添加当前目录下的所有文件
aux_source_directory (. DIR_SRCS)
aux_source_directory (./../include DIR_SRCS)

# 引入外部的cmake文件
include(./../cmake/common.cmake OPTIONAL)

# 可执行程序
add_executable (${PROJECT_NAME} ${DIR_SRCS})

# 链接库
target_link_libraries (${PROJECT_NAME} 
                        ${_REFLECTION}
                        ${_GRPC_GRPCPP}
                        ${_PROTOBUF_LIBPROTOBUF}
                    )
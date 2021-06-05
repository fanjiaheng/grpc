# protobuf & grpc
set (protobuf_MODULE_COMPATIBLE TRUE)

find_package (Protobuf CONFIG REQUIRED)
find_package (gRPC CONFIG REQUIRED)

set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)
set(_GRPC_REFLECTION gRPC::grpc++_reflection)
set(_GRPC_GRPCPP gRPC::grpc++)

message(STATUS "Using gRPC ${gRPC_VERSION}")
message (STATUS "Using protobuf ${Protobuf_VERSION}")
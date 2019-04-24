protoc --cpp_out=./protobuf_test ./protobuf/Bombplane_Proto.proto
protoc --csharp_out=./protobuf ./protobuf/Bombplane_Proto.proto
copy ./protobuf_test/proto/Bombplane_Proto.pb.h.cc ./protobuf_test
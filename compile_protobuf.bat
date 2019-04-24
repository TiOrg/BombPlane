@echo off
echo 编译protobuf...
protoc --cpp_out=. ./protobuf/Bombplane_Proto.proto
protoc --csharp_out=./protobuf ./protobuf/Bombplane_Proto.proto
echo 编译完毕.
echo.

echo 复制到vs工程目录...
copy .\protobuf\Bombplane_Proto.pb.h .\protobuf_test\protobuf\
copy .\protobuf\Bombplane_Proto.pb.cc .\protobuf_test\
echo 复制完毕.
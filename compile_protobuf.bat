@echo off
echo ����protobuf...
protoc --cpp_out=. ./protobuf/Bombplane_Proto.proto
protoc --csharp_out=./protobuf ./protobuf/Bombplane_Proto.proto
echo �������.
echo.

echo ���Ƶ�vs����Ŀ¼...
copy .\protobuf\Bombplane_Proto.pb.h .\protobuf_test\protobuf\
copy .\protobuf\Bombplane_Proto.pb.cc .\protobuf_test\
echo �������.
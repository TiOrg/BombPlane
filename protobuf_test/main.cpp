#include <iostream>
#include <strstream>
#include "./protobuf/Bombplane_Proto.pb.h"
using namespace std;
using namespace bombplane_proto;

int main()
{
	OnlineUser user;
	cout << user.ByteSize() << ' ' << sizeof(user) << endl;
	user.set_userid(222);
	cout << user.DebugString();

	Message m;
	cout << m.DebugString() << endl;
	LoginRequest *lr = new LoginRequest;	//不允许局部变量
	lr->set_password("1");
	m.set_allocated_loginrequest(lr);
	cout << m.DebugString() << endl;

	//序列化及解析测试
	Message r;

	//array
	//不推荐
	//序列化时需要设定数组最大长度，可能会导致序列化失败

	//string
	//推荐
	//可以根据size()判断序列是否太长，从而优雅地处理
	string s;
	char buffer[1024];
	cout << "序列化结果：" << m.SerializeToString(&s) << endl;
	memcpy(buffer, s.data(), s.size());	//s.length()效果一样
	memcpy(buffer + s.size(), s.data(), s.size());	//连续复制一份，试错
	cout << "解析结果：" << r.ParseFromString(string(buffer, s.size())) << endl;
	cout << r.DebugString() << endl;

	//strstream
	//不推荐
	strstream ss;
	cout << "序列化结果：" << m.SerializeToOstream(&ss) << endl;
	cout << "解析结果：" << r.ParseFromIstream(&ss) << endl;
	cout << r.DebugString() << endl;
}
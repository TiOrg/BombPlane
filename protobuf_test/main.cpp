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
	LoginRequest *lr = new LoginRequest;	//������ֲ�����
	lr->set_password("1");
	m.set_allocated_loginrequest(lr);
	cout << m.DebugString() << endl;

	//���л�����������
	Message r;

	//array
	//���Ƽ�
	//���л�ʱ��Ҫ�趨������󳤶ȣ����ܻᵼ�����л�ʧ��

	//string
	//�Ƽ�
	//���Ը���size()�ж������Ƿ�̫�����Ӷ����ŵش���
	string s;
	char buffer[1024];
	cout << "���л������" << m.SerializeToString(&s) << endl;
	memcpy(buffer, s.data(), s.size());	//s.length()Ч��һ��
	memcpy(buffer + s.size(), s.data(), s.size());	//��������һ�ݣ��Դ�
	cout << "���������" << r.ParseFromString(string(buffer, s.size())) << endl;
	cout << r.DebugString() << endl;

	//strstream
	//���Ƽ�
	strstream ss;
	cout << "���л������" << m.SerializeToOstream(&ss) << endl;
	cout << "���������" << r.ParseFromIstream(&ss) << endl;
	cout << r.DebugString() << endl;
}
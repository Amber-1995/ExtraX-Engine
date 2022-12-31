#include <ExtraX/Events/EventManager.h>
#include <iostream>

using namespace ExtraX;

class A
{
public:
	int a = 10000;

	void fun()
	{
		std::cout << a << std::endl;
	}
};

int main()
{
	A* a = new A();

	Event<EVEVT_TYPE::None> e;

	EventFuncion<EVEVT_TYPE::None> f1 = MakeEventFuncion<EVEVT_TYPE::None>(&A::fun, a);
	EventFuncion<EVEVT_TYPE::None> f2 = MakeEventFuncion<EVEVT_TYPE::None>(&A::fun, a);



	EventManager::BindEvent<EVEVT_TYPE::None>(f1);
	EventManager::BindEvent<EVEVT_TYPE::None>(f2);

	f1.reset();

	EventManager::OnEvent<EVEVT_TYPE::None>(e);
}
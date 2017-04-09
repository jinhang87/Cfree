#include <iostream>
#include <memory>

using namespace std;

class Lock{
public:
	explicit Lock()
	{
		cout<<"Lock!"<<endl;
	}
private:
	auto_ptr<int> mutexPtr;
};

int main(int argc, char *argv[])
{
	Lock ml;
	return 0;
}

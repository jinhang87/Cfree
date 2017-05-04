#include <iostream>	//std::cout
#include <map> //std::map
#include <unordered_map> //std::unordered_map
#include <string> //std::string
#include <functional> //std::function
#include <tuple>// std::tuple

using namespace std;
extern void example_has_member();
extern void example_producer_consumer();

typedef std::tuple<std::string, std::string, std::function<void(void)>> TUPLE_FUCTIONS;
typedef std::map<std::string, TUPLE_FUCTIONS> MAP_FUCTIONS;
MAP_FUCTIONS map_functions = 
{
	{ "a", std::make_tuple("has member", "use to know whether class has member", example_has_member) }, 
	{ "b", std::make_tuple("producer_consumer", "Consumer and producer problem", example_producer_consumer) }, 
};

//一键多值应用 

void help()
{
	auto i = 0;
	for(auto it : map_functions)
	{
		cout << it.first << ": " <<std::get<0>(it.second) << "\t";
		cout << std::get<1>(it.second) << endl;
	}	
}

int main(int argc, char *argv[])
{
	help();
	std::string strcin; 
	cout<<endl;
	cout<<endl;
	cout<<"Please Input Number>> ";
	cin>>strcin;
	
	MAP_FUCTIONS::iterator it = map_functions.find(strcin); 
	if(it != map_functions.end())
	{
		cout << std::get<0>(it->second) << " start :" << endl;
		std::get<2>(it->second)();
		
	}
	
	//cout<<map_functions[0].first<<endl; 
	cout<<"Hello C-Free!"<< strcin <<endl;
	return 0;
}

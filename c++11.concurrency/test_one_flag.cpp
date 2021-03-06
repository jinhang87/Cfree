#include <iostream>  
#include <thread>  
#include <mutex>

/*
	Lazy initialization
*/
struct data_packet
{
};
struct connection_info
{	
};
struct connection_handle
{	
	void send_data(data_packet const& data);
	data_packet receive_data();
};


class X
{ 
private:
	connection_info connection_details;
	connection_handle connection;
	std::once_flag connection_init_flag;
	void open_connection()
	{
		//�ӳٳ�ʼ������ 
		//connection=connection_manager.open(connection_details);
	}
public:
	X(connection_info const& connection_details_): connection_details(connection_details_)
	{
	}
	
	void send_data(data_packet const& data) // 1
	{
		std::call_once(connection_init_flag,&X::open_connection,this); // 2
		connection.send_data(data);
	} 
	data_packet receive_data() // 3
	{
		std::call_once(connection_init_flag,&X::open_connection,this); // 2
		return connection.receive_data();
	}
};
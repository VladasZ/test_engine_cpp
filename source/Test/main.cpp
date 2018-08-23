
#include "Log.hpp"

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <list>
#include <iostream>

#include <boost/chrono.hpp>
#include <boost/thread/thread.hpp> 

using namespace boost::asio;
using namespace boost::asio::ip;

template <size_t buffer_size, class Protocol>
class BaseConnection
{
	char _buffer[buffer_size];

public:


};


char _buffer[10000];

void receive_tcp(tcp::socket& socket, boost::asio::io_service& service) {
	socket.async_receive(boost::asio::buffer(_buffer), 0, [&](const boost::system::error_code& error, std::size_t bytes_transferred) {

		//receive_tcp(socket, service);

		if (bytes_transferred)
		{
			Info("TCP packet: ");
			Info(_buffer);
			service.stop();
		}
	});
}

void receive_udp(udp::socket& socket, boost::asio::io_service& service, boost::asio::ip::udp::endpoint _remote_endpoint) {
	socket.async_receive_from(boost::asio::buffer(_buffer), _remote_endpoint, [&](const boost::system::error_code& error, std::size_t bytes_transferred) {

		receive_udp(socket, service, _remote_endpoint);

		if (bytes_transferred)
		{
			Info("UDP packet: ");
			Info(_buffer);
		}
	});
}

void udp_test(udp::socket& _udp_socket, boost::asio::ip::udp::endpoint& _remote_endpoint, boost::asio::io_service& service) {

	boost::system::error_code ec;
	PING;

	_udp_socket.set_option(udp::socket::reuse_address(true), ec);
	if (ec)
		Logvar(ec.message());
	_udp_socket.set_option(socket_base::broadcast(true), ec);
	if (ec)
		Logvar(ec.message());
	_udp_socket.bind(udp::endpoint(udp::v4(), 1500), ec);
	if (ec)
		Logvar(ec.message());
	PING;

	receive_udp(_udp_socket, service, _remote_endpoint);
	PING;

}

void call_acceptor(boost::asio::io_service& tcp_service, tcp::socket& socket, tcp::endpoint& endpoint) {
	PING;
	tcp::acceptor acceptor(tcp_service, endpoint);
	PING;
	receive_tcp(socket, tcp_service);
	PING;
	acceptor.accept(socket);
	PING;
	call_acceptor(tcp_service, socket, endpoint);
	PING;
}

int main()
{
	boost::asio::io_service tcp_service;
	boost::asio::io_service udp_service;

	tcp::endpoint endpoint(tcp::v4(), 1500);
	tcp::socket socket(tcp_service);

	//tcp_test(socket, tcp_service);

	boost::asio::ip::udp::endpoint _remote_endpoint;
	udp::socket  _udp_socket(udp_service, udp::v4());

	PING;

	udp_test(_udp_socket, _remote_endpoint, udp_service);
	PING;

	auto work = std::thread([&] {
		PING;
		//tcp_service.run();
		PING;
	});

	auto udp_work = std::thread([&] {
		PING;
		udp_service.run();
		PING;
	});

	std::thread([&] {
		PING;
		//	call_acceptor(tcp_service, socket, endpoint);
		PING;
	}).detach();

	PING;


	boost::this_thread::sleep_for(boost::chrono::seconds(100));

	work.join();
	udp_work.join();
}


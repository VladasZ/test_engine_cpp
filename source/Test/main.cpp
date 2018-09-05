
#include "Log.hpp"

#include <memory>

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <list>
#include <iostream>

#include <boost/chrono.hpp>
#include <boost/thread/thread.hpp> 

using namespace boost::asio;
using namespace boost::asio::ip;

using SocketPointer = std::shared_ptr<tcp::socket>;

char _buffer[10000];

void call_acceptor(tcp::acceptor& acceptor, tcp::endpoint& endpoint);

void receive_tcp(SocketPointer socket, tcp::acceptor& acceptor, tcp::endpoint& endpoint) {
	socket->async_receive(boost::asio::buffer(_buffer), 0, [&](const boost::system::error_code& error, std::size_t bytes_transferred) {

		PING;

		if (bytes_transferred)
		{
			Info("TCP packet: ");
			Info(_buffer);
		}
		else
		{
			Info("no bytes");
		}

		call_acceptor(acceptor, endpoint);

	});
}

void call_acceptor(tcp::acceptor& acceptor, tcp::endpoint& endpoint) {
	PING;
	auto socket = std::make_shared<tcp::socket>(acceptor.get_io_service());
	PING;
	acceptor.async_accept(*socket, [&acceptor, &endpoint, socket](const boost::system::error_code& error) {
		PING;
		receive_tcp(socket, acceptor, endpoint);
		PING;
	});
}

int main()
{
	boost::asio::io_service tcp_service;
	tcp::endpoint tcp_endpoint(tcp::v4(), 1500);
	tcp::acceptor acceptor(tcp_service, tcp_endpoint);

	PING;

	call_acceptor(acceptor, tcp_endpoint);

	PING;

	tcp_service.run();

	PING;

	boost::this_thread::sleep_for(boost::chrono::seconds(100));
}


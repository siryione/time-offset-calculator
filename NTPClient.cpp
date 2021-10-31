#include <cstdint>
#include "NTPClient.h"

NTPClient::NTPClient(std::string i_hostname) : _host_name(i_hostname), _port(123) {}

int64_t NTPClient::unix_millis() {

	time_t timeRecv;
	time_t timeRecvf;

	boost::asio::io_service io_service;

	boost::asio::ip::udp::resolver resolver(io_service);
	boost::asio::ip::udp::resolver::query query(
		boost::asio::ip::udp::v4(),
		_host_name,
		"ntp");

	boost::asio::ip::udp::endpoint receiver_endpoint = *resolver.resolve(query);

	boost::asio::ip::udp::socket socket(io_service);
	socket.open(boost::asio::ip::udp::v4());

	boost::array<unsigned char, 48> sendBuf = {010, 0, 0, 0, 0, 0, 0, 0, 0};

	socket.send_to(boost::asio::buffer(sendBuf), receiver_endpoint);

	boost::array<uint32_t, 1024> recvBuf;
	boost::asio::ip::udp::endpoint sender_endpoint;

	try	{
		size_t len = socket.receive_from(
			boost::asio::buffer(recvBuf),
			sender_endpoint);

		timeRecv = ntohl((time_t)recvBuf[10]);
		timeRecvf = ntohl((time_t)recvBuf[11]);

		timeRecv -= 2208988800U;
		timeRecv *= 1000;
		while (timeRecvf > 1000) {
			timeRecvf /= 10;
		}
		timeRecv += timeRecvf;
	}
	catch (std::exception &e) {

		std::cerr << e.what() << std::endl;
	}

	return (int64_t)timeRecv;
}
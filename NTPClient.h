#ifndef NTPClIENT_H
#define NTPCLIENT_H

#include <string>
#include <iostream>

#include <boost/array.hpp>
#include <boost/asio.hpp>


class NTPClient {
private:
	std::string _host_name;
	unsigned short _port;

public:
	NTPClient(std::string i_hostname);
	int64_t unix_millis();
};

#endif
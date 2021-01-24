#ifndef __HTTP_SERVER_H__

#define __HTTP_SERVER_H__

#include <boost/asio.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/system/error_code.hpp>
#include <iostream>
#include <string>

namespace asio = boost::asio;
namespace ip = asio::ip;

namespace nori{

	class HttpServer{
		public:
			HttpServer();
			~HttpServer();

			void StanbyServer(u_short port);
		protected:
			
			void WaitingConnectFromClient();
		private:

			asio::streambuf receiveBuffer;

			asio::io_service ioService;
			boost::system::error_code errorCode;

			ip::tcp::socket* httpServerSocket;
			ip::tcp::acceptor* httpSocketAcceptor;
			
			u_short port;
			
			std::string packetBuffer;

	};

};

#endif

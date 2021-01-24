#include "HTTPServer.h"
#include <boost/asio/buffer.hpp>
#include <boost/asio/completion_condition.hpp>
#include <boost/asio/error.hpp>
#include <boost/asio/read.hpp>
#include <boost/system/error_code.hpp>

nori::HttpServer::HttpServer(){
	this->httpServerSocket = new ip::tcp::socket(this->ioService);

}

nori::HttpServer::~HttpServer(){
	delete this->httpServerSocket;
	delete this->httpSocketAcceptor;
}

void nori::HttpServer::WaitingConnectFromClient(){
	std::cout << "Stanby OK!" << std::endl;
	//asio::read(this->httpServerSocket,this->receiveBuffer,asio::transfer_at_least(1),this->errorCode);
	if(this->errorCode && this->errorCode != asio::error::eof)
		std::cout << "receive failed: " << this->errorCode.message() << std::endl;
	else if (asio::buffer_cast<const char*>(this->receiveBuffer.data()) == std::string("end")){
		std::cout << "クライアントが接続を切りました。" << std::endl;
	}

	//最初はどんな接続に対しても「HTTP1.1 200 OK」を返すことにする
	this->packetBuffer="HTTP1.1 200 OK";
	asio::write(*(this->httpServerSocket),asio::buffer(this->packetBuffer));

}

void nori::HttpServer::StanbyServer(u_short port){


	std::cout << "Stanby OK!" << std::endl;
	this->port=port;
	
	this->httpSocketAcceptor = new ip::tcp::acceptor(this->ioService,ip::tcp::endpoint(ip::tcp::v4(),this->port));

	this->httpSocketAcceptor->accept(*(this->httpServerSocket));

	this->WaitingConnectFromClient();
}

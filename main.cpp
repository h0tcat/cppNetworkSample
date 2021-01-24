#include "HTTPServer.h"

int main(void){
	nori::HttpServer httpServer;
	httpServer.StanbyServer(8080);
	return 0;
}

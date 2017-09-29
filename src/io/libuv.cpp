#include <cassert>
#include "libuv.h"
#include "reponse.h"
#include "string.h"

using namespace std;

int IIOService::listen(const char *host, int port) {
	
  printf("######## start futures service HOST: %s PORT: %d ######### \n", host, port);  
	
	Response::loop = uv_default_loop(); 
  
  uv_tcp_init(Response::loop, &Response::server);  
  uv_ip4_addr(host, port, &Response::addr);
  uv_tcp_bind(&Response::server, (const struct sockaddr*)&Response::addr, 0);
  
	int listen_status = uv_listen((uv_stream_t*)&Response::server, Response::default_backlog, Response::onConnect);   
	
  if(listen_status) {   
  	fprintf(stderr, "Listen error %s\n", uv_strerror(listen_status));
  	return 1;  
  } 
  
	return uv_run(Response::loop, UV_RUN_DEFAULT);

}

int IIOService::connect() {

  printf("######## /home/zhang/Projects/libuv-service/data/trader ######### \n");
  	
	CThostFtdcTraderApi * createClient = CThostFtdcTraderApi::CreateFtdcTraderApi("/home/zhang/Projects/libuv-service/data/trader");
 	MarketDataCollector mdCollector(createClient);
  
	createClient->RegisterSpi(&mdCollector);
  createClient->RegisterFront("tcp://127.0.0.1:17001");
  
	createClient->SubscribePrivateTopic(THOST_TE_RESUME_TYPE);
  createClient->SubscribePublicTopic(THOST_TE_RESUME_TYPE);
  
	createClient->Init();
	createClient->Join();
	
	return 0;

}

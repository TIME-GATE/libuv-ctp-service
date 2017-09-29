#include "response.h"

using namespace std;

void Response::read(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf) {
  buf->base = (char*) malloc(suggested_size);  
  buf->len = suggested_size; 
}

void Response::write(uv_write_t *req, int status) {  
    if (status) fprintf(stderr, "Write error %s\n", uv_strerror(status));
    free(req);  
} 

void Response::send(uv_stream_t *client, ssize_t nread, const uv_buf_t *buff) {
  if(nread < 0) {
    if(nread != UV_EOF) fprintf(stderr, "read error %s \n", uv_err_name(nread));
    uv_close((uv_handle_t*) client, NULL);
  } else {
		uv_write_t *req = (uv_write_t *) malloc(sizeof(uv_write_t));
    
    // 转发到交易中心 
    Routes *route = new Routes();
    char *futures_str = route->getCThostFtdcTraderApi();
    uv_buf_t wrbuf = uv_buf_init(futures_str, strlen(futures_str));
    
    uv_write(req, client, &wrbuf, 1, Response::write);
	}

  printf("echo_read:%s\r\n", buff->base);
  
  if(buff->base) free(buff->base);

}

void Response::onConnect(uv_stream_t *server, int status) {
  if (status < 0) {   
    fprintf(stderr, "one new connection have been error %s\n", uv_strerror(status));  
    return;
  }   
        
  uv_tcp_t *client = (uv_tcp_t*) malloc(sizeof(uv_tcp_t));  
  uv_tcp_init(loop, client);
  
  if (uv_accept(server, (uv_stream_t*) client) == 0) {   
    uv_read_start((uv_stream_t*) client, Response::read, Response::send);  
  } else {   
    uv_close((uv_handle_t*) client, NULL);  
  }   
  
  printf("one new connection have been OK, status:%d\r\n", status);   

}

#include <cassert>
#include "libuv.h"
#include "../routes.h"
#include <vector>
#include <uv.h>

using namespace std;

// 处理层
class Response {

  public : 

    Response() {}; 
    virtual ~Response () {}; 
  
  public :

    // 读数据
    static void read(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf);   	
 
    // 写数据
    static void write(uv_write_t *req, int status);
    
    // 发送数据
    static void send(uv_stream_t *client, ssize_t nread, const uv_buf_t *buff);	
    
    // 监听新链接
    static void onConnect(uv_stream_t *server, int status);
    
  public : 
  
    // 事件句柄
    static uv_loop_t *loop;

    // 服务
    static uv_tcp_t server;
		
		// 地址
    static struct sockaddr_in addr;
		
		// 握手buffer最大值
    static const int  default_backlog = 128;

};


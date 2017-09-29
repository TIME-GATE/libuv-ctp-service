#ifndef __LIBUV_IO_SERVICE__
#define __LIBUV_IO_SERVICE__

#include <vector>
#include <string>
#include <uv.h>

// 通信层
class IIOService {

  public : 

    IIOService() {};
    virtual ~IIOService () {};
  
  public :

    // 本地连接/监听
    int listen(const char *host, int port);
    
    // 连接交易中心
    int connect(const char *host, uint16_t port, int32_t seconds);

    // 停止本地服务/交易中心服务连接
    //void shutdown();

};

#endif

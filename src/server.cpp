#include "./io/libuv.h"

int main(int argc, char ** argv){
  
  printf("###################### START SERVICE ######################\n");
  
  IIOService server;
  
  // 开启监听线程
  if(!server.listen("0.0.0.0", 7000)) {
    printf("###################### START SERVICE FAILED ######################\n");
  }

  // 开启交易线程
  if(!server.connect()) {
    printf("###################### CONNECT FTP FAILED ######################\n");
  }
  
  return 1;

}

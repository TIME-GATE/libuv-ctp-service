#ifndef __SRC_DATASERVERS_MYSQLENGINE_H__
#define __SRC_DATASERVERS_MYSQLENGINE_H__

#include <vector>
#include <string>

#include <stdint.h>
#include <mysql/mysql.h>

// 结果集
typedef std::vector<std::string>        Result;
typedef std::vector<Result>             Results;

class MysqlEngine {
public :
	MysqlEngine(const std::string & host, uint16_t port);
	~MysqlEngine();

public :
	// 选择数据库
  void selectdb( const std::string & database );

  // 设置字符集
  void setCharsets( const std::string & charsets );

  // 设置访问权限
  void setToken( const std::string & user, const std::string & passwd );

public :
  // 初始化
  bool initialize();

  // 销毁
  void finalize();

  // 保活
  void keepalive();

  // 转义
  void escape( const std::string & src, std::string & dst );

  // 插入
  bool insert( const std::string & sqlcmd, uint64_t & insertid );
  
	// 查询
  bool query( const std::string & sqlcmd, Results & results );
    
	// 更新
  bool update( const std::string & sqlcmd, uint32_t & naffected );
  
	// 删除
  bool remove( const std::string & sqlcmd, uint32_t & naffected );

private :
  enum {
    eMysqlEngine_ConnectTimeout        = 5,    // 连接超时时间
    eMysqlEngine_ReadTimeout           = 5,    // 读超时时间
    eMysqlEngine_WriteTimeout          = 5,    // 写超时时间
  };

private :
  std::string         m_Host;         // 主机地址
  uint16_t            m_Port;         // 端口号
  std::string         m_Username;     // 用户名
  std::string         m_Password;     // 密码
  std::string         m_Database;     // 数据库名
  std::string         m_Charsets;     // 字符集

private :
  MYSQL *             m_DBHandler;    // 数据库句柄
};

#endif

#include <string.h>

#include "base/base.h"
#include "mysqlengine.h"

MysqlEngine::MysqlEngine( const std::string & host, uint16_t port )
  : m_Host( host ),
    m_Port( port ),
    m_DBHandler( NULL ){}

MysqlEngine::~MysqlEngine(){}

void MysqlEngine::selectdb( const std::string & database ) {
  m_Database = database;
  
  if ( m_DBHandler != NULL ) {
    mysql_select_db( m_DBHandler, m_Database.c_str() );
  }
}

void MysqlEngine::setCharsets( const std::string & charsets ) {
  m_Charsets = charsets;
}

void MysqlEngine::setToken( const std::string & user, const std::string & passwd ) {
  m_Username = user;
  m_Password = passwd;
}

bool MysqlEngine::initialize() {
  // 初始化句柄
  m_DBHandler = mysql_init( NULL );
  
  if ( m_DBHandler == NULL ) {
    return false;
  }

  // 设置属性
  bool flags = true;
  int32_t timeout = 0;
  
  // 尝试重新连接
  mysql_options( m_DBHandler, MYSQL_OPT_RECONNECT, (const char *)&flags );
  
  // 设置字符集
  mysql_options( m_DBHandler, MYSQL_SET_CHARSET_NAME, m_Charsets.c_str() );
  
  // 连接超时
  timeout = eMysqlEngine_ConnectTimeout;
  
  mysql_options( m_DBHandler, MYSQL_OPT_CONNECT_TIMEOUT, (const char *)&timeout );
  
  // 读超时
  timeout = eMysqlEngine_ReadTimeout;
  mysql_options( m_DBHandler, MYSQL_OPT_READ_TIMEOUT, (const char *)&timeout );
  
  // 写超时
  timeout = eMysqlEngine_WriteTimeout;
  mysql_options( m_DBHandler, MYSQL_OPT_WRITE_TIMEOUT, (const char *)&timeout );
  
  // 连接MySQL服务器
  if ( mysql_real_connect( m_DBHandler, m_Host.c_str(), m_Username.c_str(), m_Password.c_str(), m_Database.c_str(), m_Port, NULL, 0 ) == NULL ) {
    mysql_close( m_DBHandler );
    m_DBHandler = NULL;
    return false;
  }
  
  return true;
}

void MysqlEngine::finalize() {
  if ( m_DBHandler != NULL ) {
    mysql_close( m_DBHandler );
    m_DBHandler = NULL;
  }
}

void MysqlEngine::keepalive() {
 
  int32_t rc = 0;
  
  rc = mysql_ping( m_DBHandler );
  if ( rc != 0 ) {
    LOG_ERROR( "MysqlEngine::keepalive() : Result:%d, Error:(%d,'%s') .\n", rc, mysql_errno(m_DBHandler), mysql_error(m_DBHandler) );
  }
}

void MysqlEngine::escape( const std::string & src, std::string & dst ) {
 
  // 重置dst长度
  dst.resize( src.size() * 2 + 1 );
  
  char * to = const_cast<char *>( dst.data() );
  size_t len = mysql_real_escape_string(
    m_DBHandler,
    to, (const char *)src.data(), src.size() );
    
    dst.resize( len );
}

bool MysqlEngine::insert( const std::string & sqlcmd, uint64_t & insertid ) {
 
  int32_t rc = 0;
  
  rc = mysql_real_query( m_DBHandler, sqlcmd.data(), sqlcmd.size() );
  
  if ( rc != 0 ) {
    LOG_ERROR( "MysqlEngine::insert(SQLCMD:'%s') : Result:%d, Error:(%d,'%s') .\n",
      sqlcmd.c_str(), rc, mysql_errno(m_DBHandler), mysql_error(m_DBHandler) );
    return false;
  }
  
  // 获取返回的自增ID
  insertid = mysql_insert_id( m_DBHandler );
  
  LOG_TRACE( "MysqlEngine::insert(SQLCMD:'%s') : InsertID:%lu .\n", sqlcmd.c_str(), insertid );
  return true;
}

bool MysqlEngine::query( const std::string & sqlcmd, Results & results ) {
	
  int32_t rc = 0;
  rc = mysql_real_query( m_DBHandler, sqlcmd.data(), sqlcmd.size() );
  if ( rc != 0 ) {
    LOG_ERROR( "MysqlEngine::query(SQLCMD:'%s') : Result:%d, Error:(%d,'%s') .\n",
      sqlcmd.c_str(), rc, mysql_errno(m_DBHandler), mysql_error(m_DBHandler) );
    return false;
	}
  
  MYSQL_RES * result = mysql_store_result( m_DBHandler );
  if ( result == NULL ) {
    LOG_ERROR( "MysqlEngine::query(SQLCMD:'%s') : Store Result Failed .\n", sqlcmd.c_str() );
    return false;
  }
  
  MYSQL_ROW row;
  uint32_t nfields = mysql_num_fields( result );
  while ( (row = mysql_fetch_row(result)) != NULL ) {
    Result tmpresult;
    uint64_t * lengths = mysql_fetch_lengths( result );
    
    for ( uint32_t i = 0; i < nfields; ++i ) {
      tmpresult.push_back( std::string( row[i], lengths[i] ) );
    }
    
    results.push_back( tmpresult );
  }
  
  mysql_free_result( result );
  LOG_TRACE( "MysqlEngine::query(SQLCMD:'%s') : ResultCount:%lu .\n", sqlcmd.c_str(), results.size() );
  
  return true;
}

bool MysqlEngine::update( const std::string & sqlcmd, uint32_t & naffected ) {
  int32_t rc = 0;
  
  rc = mysql_real_query( m_DBHandler, sqlcmd.data(), sqlcmd.size() );
  if ( rc != 0 ) {
    LOG_ERROR( "MysqlEngine::update(SQLCMD:'%s') : Result:%d, Error:(%d,'%s') .\n",
      sqlcmd.c_str(), rc, mysql_errno(m_DBHandler), mysql_error(m_DBHandler) );
		
    return false;
  }
  
  // 获取影响的行数
  naffected = mysql_affected_rows( m_DBHandler );
  LOG_TRACE( "MysqlEngine::update(SQLCMD:'%s') : AffectedRows:%u .\n", sqlcmd.c_str(), naffected );
  
  return true;
}

bool MysqlEngine::remove( const std::string & sqlcmd, uint32_t & naffected ) {
  int32_t rc = 0;
  
  rc = mysql_real_query( m_DBHandler, sqlcmd.data(), sqlcmd.size() );
  if ( rc != 0 ) {
    LOG_ERROR( "MysqlEngine::remove(SQLCMD:'%s') : Result:%d, Error:(%d,'%s') .\n",
      sqlcmd.c_str(), rc, mysql_errno(m_DBHandler), mysql_error(m_DBHandler) );
    return false;
  }
  
  // 获取影响的行数
  naffected = mysql_affected_rows( m_DBHandler );
  LOG_TRACE( "MysqlEngine::remove(SQLCMD:'%s') : AffectedRows:%u .\n", sqlcmd.c_str(), naffected );
  
  return true;
}

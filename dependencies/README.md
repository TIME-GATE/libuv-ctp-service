###  项目依赖安装 LINUX环境

#### 1 LIBUV

```text
sudo apt-get install automake

sudo apt-get install libtool

git clone https://github.com/libuv/libuv.git && cd libuv

sh autogen.sh

./configure

make && make check

sudo make install
```

#### 2 PROTOBUFF

```text

git clone https://github.com/google/protobuf.git

cd protobuf && ./configure

make && make check

sudo make install && sudo ldconfig

```

#### 3 交易所SDK

```text
略
```

#### 4 MYSQL

```text
略
```

#### 5 REDIS

```text
略
```

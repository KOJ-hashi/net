#ifndef NET_H
  #define NET_H
  
  #include "mbed.h"
  #include "EthernetInterface.h"
  #include "TCPSocket.h"
  
  class Net {
  public:
      void start();          // 接続開始
      void send_ip();        // IP送信
  
  private:
      EthernetInterface net;
      TCPSocket server;
      TCPSocket *client = nullptr;
      SocketAddress ip;
  };
  
  #endif

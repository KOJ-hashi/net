#include "net.h"
#include <cstdio>

#define PORT 5000//ポート番号の設定

void Net::start() {
    // ネット接続
    net.connect();

    // IP取得
    net.get_ip_address(&ip);

    // サーバ準備
    server.open(&net);
    server.bind(PORT);
    server.listen();

    // 接続待ち
    client = server.accept();
}

void Net::send_ip() {
    if (client != nullptr) {
        char buf[64];
        int len = sprintf(buf, "IP: %s\r\n", ip.get_ip_address());
        client->send(buf, len);
    }
}

#pragma once

#include "IConnectionClient.h"
#include <QWebSocket>
#include <QUrl>

class WebSocketClient : public IConnectionClient
{
    Q_OBJECT

public:
    explicit WebSocketClient(const QUrl& url, QObject* parent = nullptr);

    void connectToHost() override;
    void disconnectFromHost() override;    

private slots:
    void onConnected();
    void onDisconnected();
    void onTextMessageReceived(const QString& message);
    void onErrorOccurred(QAbstractSocket::SocketError error);

private:
    QWebSocket m_socket;
    QUrl m_url;
};

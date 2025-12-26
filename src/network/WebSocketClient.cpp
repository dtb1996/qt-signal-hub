#include "WebSocketClient.h"

WebSocketClient::WebSocketClient(const QUrl &url, QObject *parent)
    : IConnectionClient(parent)
    , m_url(url)
{
    connect(&m_socket, &QWebSocket::connected, this, &WebSocketClient::onConnected);
    connect(&m_socket, &QWebSocket::disconnected, this, &WebSocketClient::onDisconnected);
    connect(&m_socket, &QWebSocket::textMessageReceived, this, &WebSocketClient::onTextMessageReceived);
    connect(&m_socket, QOverload<QAbstractSocket::SocketError>::of(&QWebSocket::errorOccurred), this, &WebSocketClient::onErrorOccurred);
}

void WebSocketClient::connectToHost()
{
    m_socket.open(m_url);
}

void WebSocketClient::disconnectFromHost()
{
    m_socket.close();
}

void WebSocketClient::onConnected() {
    emit connected();
}

void WebSocketClient::onDisconnected() {
    emit disconnected();
}

void WebSocketClient::onTextMessageReceived(const QString &message)
{
    emit messageReceived(message.toUtf8(), QStringLiteral("default"));
}

void WebSocketClient::onErrorOccurred(QAbstractSocket::SocketError error)
{
    Q_UNUSED(error)
    emit errorOccurred(m_socket.errorString());
}


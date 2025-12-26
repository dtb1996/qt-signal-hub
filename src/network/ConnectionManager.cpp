#include "ConnectionManager.h"
#include "WebSocketClient.h"

ConnectionManager::ConnectionManager(QObject *parent)
    : QObject(parent)
{
    m_client = nullptr;
}

Connection::State ConnectionManager::state() const
{
    return m_state;
}

Connection::Type ConnectionManager::activeProtocol() const
{
    return m_activeProtocol;
}

void ConnectionManager::setProtocol(Connection::Type type)
{
    if (m_activeProtocol == type)
        return;

    m_activeProtocol = type;
    emit activeProtocolChanged();
}

void ConnectionManager::connect()
{
    if (m_client)
    {
        m_client->disconnectFromHost();
        m_client->deleteLater();
        m_client = nullptr;
    }

    m_client = new WebSocketClient(QUrl("ws://localhost:12345"), this);
    attachClientSignals(m_client);

    setState(Connection::State::Connecting);
    m_client->connectToHost();
}

void ConnectionManager::disconnect()
{
    if (m_client)
    {
        m_client->disconnectFromHost();
    }
}

void ConnectionManager::setState(Connection::State state)
{
    if (m_state == state)
    {
        return;
    }

    m_state = state;
    emit stateChanged();
}

void ConnectionManager::attachClientSignals(IConnectionClient *client)
{
    QObject::connect(client, &IConnectionClient::connected, this, [this]() { setState(Connection::State::Connected); });
    QObject::connect(client, &IConnectionClient::disconnected, this, [this]() { setState(Connection::State::Disconnected); });
    QObject::connect(client, &IConnectionClient::messageReceived, this, &ConnectionManager::messageReceived);
    QObject::connect(client, &IConnectionClient::errorOccurred, this, &ConnectionManager::errorOccurred);
}

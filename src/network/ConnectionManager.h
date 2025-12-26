#pragma once

#include <QObject>
#include "ConnectionTypes.h"
#include "IConnectionClient.h"

class ConnectionManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Connection::State state READ state NOTIFY stateChanged)
    Q_PROPERTY(Connection::Type activeProtocol READ activeProtocol NOTIFY activeProtocolChanged)

public:
    explicit ConnectionManager(QObject* parent = nullptr);

    Connection::State state() const;
    Connection::Type activeProtocol() const;

    Q_INVOKABLE void setProtocol(Connection::Type type);
    Q_INVOKABLE void connect();
    Q_INVOKABLE void disconnect();

signals:
    void stateChanged();
    void activeProtocolChanged();
    void messageReceived(QByteArray payload, QString channel);
    void errorOccurred(QString error);

private:
    void setState(Connection::State state);
    void attachClientSignals(IConnectionClient* client);

    Connection::State m_state { Connection::State::Disconnected };
    Connection::Type m_activeProtocol { Connection::Type::Websocket };
    IConnectionClient* m_client { nullptr };
};

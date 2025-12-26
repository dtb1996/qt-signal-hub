#pragma once

#include <QObject>
#include <QString>
#include <QByteArray>

class IConnectionClient : public QObject
{
    Q_OBJECT

public:
    explicit IConnectionClient(QObject* parent = nullptr) : QObject(parent) {}

    virtual ~IConnectionClient() = default;

    virtual void connectToHost() = 0;
    virtual void disconnectFromHost() = 0;

signals:
    void connected();
    void disconnected();
    void messageReceived(QByteArray payload, QString channel);
    void errorOccurred(QString error);
};

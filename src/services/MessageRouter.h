#pragma once

#include <QObject>
#include "MessageParser.h"

class MessageRouter : public QObject
{
    Q_OBJECT

public:
    explicit MessageRouter(QObject* parent = nullptr);

signals:
    void messageReady(const MessageItem& item);

public slots:
    void routeMessage(const QByteArray& payload, const QString& channel);

private:
    MessageParser m_parser;
};

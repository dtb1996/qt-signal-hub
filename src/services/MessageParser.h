#pragma once

#include <QObject>
#include <QByteArray>
#include "../models/MessageItem.h"

class MessageParser : public QObject
{
    Q_OBJECT

public:
    explicit MessageParser(QObject* parent = nullptr);

    MessageItem parse(const QByteArray& payload, const QString& channel);
};

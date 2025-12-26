#pragma once

#include <QString>
#include <QDateTime>

struct MessageItem
{
    QString channel;
    QString payload;
    QDateTime timestamp;
};

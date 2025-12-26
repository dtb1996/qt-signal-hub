#include "MessageParser.h"
#include <QJsonDocument>
#include <QJsonObject>

MessageParser::MessageParser(QObject *parent)
    : QObject(parent)
{

}

MessageItem MessageParser::parse(const QByteArray &payload, const QString &channel)
{
    MessageItem item;
    item.channel = channel;
    item.timestamp = QDateTime::currentDateTime();

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(payload, &error);
    if (error.error == QJsonParseError::NoError && doc.isObject())
    {
        QJsonObject obj = doc.object();
        item.payload = QString::fromUtf8(QJsonDocument(obj).toJson(QJsonDocument::Compact));
    }
    else
    {
        item.payload = QString::fromUtf8(payload);
    }

    return item;
}

#include "MessageRouter.h"

MessageRouter::MessageRouter(QObject *parent)
    : QObject(parent)
{

}

void MessageRouter::routeMessage(const QByteArray &payload, const QString &channel)
{
    MessageItem item = m_parser.parse(payload, channel);
    emit messageReady(item);
}

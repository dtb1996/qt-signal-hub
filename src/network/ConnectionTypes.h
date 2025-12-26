#pragma once

#include <QObject>

namespace Connection {
    Q_NAMESPACE

    enum class Type
    {
        Websocket,
        Mqtt
    };
    Q_ENUM_NS(Type)

    enum class State
    {
        Disconnected,
        Connecting,
        Connected,
        Error
    };
    Q_ENUM_NS(State)
}

Q_DECLARE_METATYPE(Connection::State)
Q_DECLARE_METATYPE(Connection::Type)

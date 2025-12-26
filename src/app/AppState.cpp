#include "AppState.h"
#include <QMetaEnum>

AppState::AppState(QObject *parent)
    : QObject(parent)
    , m_connectionState(Connection::State::Disconnected)
    , m_error("")
{

}

Connection::State AppState::connectionState() const
{
    return m_connectionState;
}

QString AppState::connectionStateText() const
{
    const QMetaObject &mo = Connection::staticMetaObject;
    int index = mo.indexOfEnumerator("State");
    QMetaEnum metaEnum = mo.enumerator(index);

    return QString::fromLatin1(
        metaEnum.valueToKey(static_cast<int>(m_connectionState))
    );
}

QString AppState::error() const
{
    return m_error;
}

void AppState::setConnectionState(Connection::State state)
{
    if (m_connectionState == state)
        return;

    m_connectionState = state;
    emit connectionStateChanged();
}

void AppState::setError(const QString &error)
{
    if (m_error == error)
        return;

    m_error = error;
    emit errorChanged();
}

#pragma once

#include <QObject>
#include <QString>
#include "../network/ConnectionTypes.h"

class AppState : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Connection::State connectionState READ connectionState NOTIFY connectionStateChanged)
    Q_PROPERTY(QString connectionStateText READ connectionStateText NOTIFY connectionStateChanged)
    Q_PROPERTY(QString error READ error NOTIFY errorChanged)

public:
    explicit AppState(QObject* parent = nullptr);

    Connection::State connectionState() const;
    QString connectionStateText() const;
    QString error() const;

public slots:
    void setConnectionState(Connection::State state);
    void setError(const QString& error);

signals:
    void connectionStateChanged();
    void errorChanged();

private:
    Connection::State m_connectionState { Connection::State::Disconnected };
    QString m_error;
};

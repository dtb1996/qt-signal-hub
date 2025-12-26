#pragma once

#include <QAbstractListModel>
#include "MessageItem.h"

class MessageFeedModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)

public:
    enum Roles
    {
        ChannelRole = Qt::UserRole + 1,
        PayloadRole,
        TimestampRole
    };

    explicit MessageFeedModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    int count() const;

    Q_INVOKABLE void clear();

public slots:
    void addMessage(const MessageItem& item);

signals:
    void countChanged();

private:
    QList<MessageItem> m_items;
    const int m_maxItems = 500;
};

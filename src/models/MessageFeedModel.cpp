#include "MessageFeedModel.h"

MessageFeedModel::MessageFeedModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

int MessageFeedModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_items.count();
}

QVariant MessageFeedModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_items.size())
        return {};

    const auto& item = m_items.at(index.row());

    switch (role)
    {
    case ChannelRole:
        return item.channel;
    case PayloadRole:
        return item.payload;
    case TimestampRole:
        return item.timestamp.toString(Qt::ISODate);
    default:
        return {};
    }
}

QHash<int, QByteArray> MessageFeedModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ChannelRole] = "channel";
    roles[PayloadRole] = "payload";
    roles[TimestampRole] = "timestamp";
    return roles;
}

int MessageFeedModel::count() const
{
    return m_items.count();
}

void MessageFeedModel::clear()
{
    if (m_items.isEmpty())
        return;

    beginResetModel();
    m_items.clear();
    endResetModel();

    emit countChanged();
}

void MessageFeedModel::addMessage(const MessageItem &item)
{
    // Remove oldest item if at max capacity
    if (m_items.size() >= m_maxItems)
    {
        beginRemoveRows(QModelIndex(), 0, 0);
        m_items.removeFirst();
        endRemoveRows();
    }

    // Append new item
    const int row = m_items.size();
    beginInsertRows(QModelIndex(), row, row);
    m_items.append(item);
    endInsertRows();

    emit countChanged();
}

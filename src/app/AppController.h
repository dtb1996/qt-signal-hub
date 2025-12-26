#pragma once

#include <QObject>
#include "../network/ConnectionManager.h"
#include "../models/MessageFeedModel.h"
#include "../services/MessageRouter.h"
#include "../app/AppState.h"

class AppController : public QObject
{
    Q_OBJECT

public:
    explicit AppController(QObject* parent = nullptr);

    ConnectionManager* connectionManager() { return &m_connectionManager; }
    MessageFeedModel* messageModel() { return &m_messageModel; }
    AppState* appState() { return &m_appState; }

private:
    ConnectionManager m_connectionManager;
    MessageFeedModel m_messageModel;
    MessageRouter m_messageRouter;
    AppState m_appState;
};

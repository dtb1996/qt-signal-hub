#include "AppController.h"


AppController::AppController(QObject *parent)
    : QObject(parent)
{
    // Forward ConnectionManager messages to router
    connect(&m_connectionManager, &ConnectionManager::messageReceived, &m_messageRouter, &MessageRouter::routeMessage);

    // Forward parsed messages to the model
    connect(&m_messageRouter, &MessageRouter::messageReady, &m_messageModel, &MessageFeedModel::addMessage);

    // Forward connection state/errors to AppState
    connect(&m_connectionManager, &ConnectionManager::stateChanged, this, [this]() {
        m_appState.setConnectionState(m_connectionManager.state());
    });
    connect(&m_connectionManager, &ConnectionManager::errorOccurred, &m_appState, &AppState::setError);
}

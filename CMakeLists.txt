cmake_minimum_required(VERSION 3.16)

project(QtSignalHub VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Quick
    WebSockets
)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appQtSignalHub
    src/main.cpp
)

qt_add_qml_module(appQtSignalHub
    URI QtSignalHub
    VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}
    QML_FILES
        qml/Main.qml
        qml/views/FeedView.qml
        qml/views/ConnectionView.qml
        qml/components/MessageCard.qml

    SOURCES
    src/app/AppController.h src/app/AppController.cpp
        src/app/AppState.h src/app/AppState.cpp
        src/network/ConnectionManager.h src/network/ConnectionManager.cpp
        src/network/IConnectionClient.h
        src/network/WebSocketClient.h src/network/WebSocketClient.cpp
        src/services/MessageRouter.h src/services/MessageRouter.cpp
        src/services/MessageParser.h src/services/MessageParser.cpp
        src/models/MessageFeedModel.h src/models/MessageFeedModel.cpp
        src/models/MessageItem.h

        src/workers/ParsingWorker.h src/workers/ParsingWorker.cpp
        SOURCES src/network/ConnectionTypes.h
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appQtSignalHub PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appQtSignalHub
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appQtSignalHub
    PRIVATE Qt6::Quick
    PRIVATE Qt6::WebSockets
)

include(GNUInstallDirs)
install(TARGETS appQtSignalHub
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

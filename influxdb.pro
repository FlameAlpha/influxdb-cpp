#-------------------------------------------------
#
# Project created by QtCreator 2019-09-03T10:26:12
#
#-------------------------------------------------

QT       -= core gui

TARGET = influxdb
TEMPLATE = app # app
#CONFIG += staticlib # staticlib or sharedlib

CONFIG += c++17
# CONFIG += console # terminal
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += INFLUXDB_WITH_BOOST
DEFINES += ONLY_HTTP
#DEFINES += DEBUG_OUTPUT
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/HTTP.cxx \
    src/InfluxDB.cxx \
    src/InfluxDBFactory.cxx \
    src/Point.cxx \
#    src/UDP.cxx \
#    src/UnixSocket.cxx \
    example.cpp

HEADERS += \
    boost/asio.hpp \
    boost/lexical_cast.hpp \
    boost/property_tree/ptree.hpp \
    boost/property_tree/json_parser.hpp \
    include/HTTP.h \
#    include/UDP.h \
#    include/UnixSocket.h \
    include/UriParser.h \
    include/InfluxDB.h \
    include/InfluxDBFactory.h \
    include/Point.h \
    include/Transport.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

LIBS += -L$$PWD/lib/ -llibcurl
LIBS += -L$$PWD/lib/ -llibboost_date_time-vc141-mt-x64-1_67
LIBS += -L$$PWD/lib/ -llibboost_system-vc141-mt-x64-1_67
LIBS += -L$$PWD/lib/ -llibboost_regex-vc141-mt-x64-1_67

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

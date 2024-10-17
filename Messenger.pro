QT += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# 프로젝트에 포함할 include 경로 설정
INCLUDEPATH += header   \
               header/model \
               header/view  \
               header/controller

# 소스 파일
SOURCES += \
    main.cpp \
    $$files($$PWD/source/model/*.cpp)   \
    $$files($$PWD/source/view/*.cpp)   \
    $$files($$PWD/source/controller/*.cpp) \
    network/tcp_client.cpp \
    network/tcp_server.cpp

# 헤더 파일
HEADERS += \
    $$files($$PWD/header/model/*.h)   \
    $$files($$PWD/header/view/*.h)   \
    $$files($$PWD/header/controller/*.h) \
    network/tcp_client.h \
    network/tcp_server.h

# UI forms 파일
FORMS += \
    $$files($$PWD/source/ui/*.ui) \

# MOC 파일을 저장할 디렉토리 (선택사항)
# MOC_DIR = moc

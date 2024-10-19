[network]
tcp_server : QTcpServer
explicit TCPserver(QObject *parent = nullptr);
    - incomingConnection(qintptr socketDescriptor)
    - 
    - 

tcp_thread : QThread
explicit TCPthread(qintptr socketDescriptor, QObject *parent = nullptr);
    - start(~)  //내장함수 
    - exec()    //내장함수 
    - run()     //내장함수
    - quit()    //내장함수
    - moveToThread()    //내장함수
        - start() -> run() -> exec()

tcp_handler : QObject
    - handler_login(const QString& id, const QString& pw)
    - handler_register

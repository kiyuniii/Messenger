/project_root
├── /build                         # 빌드 파일
├── /src                           # 소스 코드 파일
│   ├── /model                     # 데이터 관리 및 비즈니스 로직
│   │   ├── user_model.cpp         # 사용자 정보 관련 데이터 처리
│   │   ├── user_model.h
│   │   └── message_model.cpp      # 메시지 데이터 처리
│   │   └── message_model.h
│   ├── /view                      # UI 구성 요소 (Qt Designer .ui 파일 등)
│   │   ├── mainwindow.ui          # 메인 윈도우의 UI 정의 (.ui 파일)
│   │   ├── chatwindow.ui          # 채팅 화면 UI 정의 (.ui 파일)
│   ├── /controller                # 이벤트 핸들러 및 로직 제어
│   │   ├── mainwindow_controller.cpp  # 메인 화면 제어 로직
│   │   ├── mainwindow_controller.h
│   │   ├── chatwindow_controller.cpp  # 채팅 화면 제어 로직
│   │   ├── chatwindow_controller.h
├── /include                       # 헤더 파일
│   ├── model                      # 모델 관련 헤더 파일
│   │   └── model_headers.h
│   ├── view                       # 뷰 관련 헤더 파일
│   │   └── view_headers.h
│   ├── controller                 # 컨트롤러 관련 헤더 파일
│   │   └── controller_headers.h
├── /resources                     # 리소스 파일 (아이콘, 이미지 등)
│   └── icons/
├── /tests                         # 테스트 파일
│   ├── model_tests.cpp            # 모델 유닛 테스트
│   ├── view_tests.cpp             # 뷰 유닛 테스트
│   └── controller_tests.cpp       # 컨트롤러 유닛 테스트
├── CMakeLists.txt                 # CMake 빌드 스크립트
└── Makefile                       # Make 빌드 스크립트


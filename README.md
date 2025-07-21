# raspi
라즈베리파이 공부 

- 라즈베리 파이 설정 

    Raspberry Pi OS 설치 및 무선 설정 가dlem

    1. Raspberry Pi Imager 다운로드 및 실행
        - Raspberry Pi 공식
        - https://www.raspberrypi.com/software/
        - 다운로드 버튼 클릭 exe파일 다운
        - 다운로드 환료 후 실행
    2. 설치 및 설정
        1. 장치 선택 
            - 사용하는 라즈베리 파이 모델 선택
        2. OS 선택
            - 사용하는 라즈베리 파이 OS선택
        3. 저장 장치 선택
            - 마이크로 SD카드 선택
        4. 설정 편집
            - 라즈베리 파이의 네트워크 이름 지정
            - 사용자 이름 및 버번 SSH 접속용 계정 설정
            - 무선 네트워크 설정 
                - SSID : Wi-Fi 이름 입력(공유기의 네트워크 이름 확인 후 입력)
                - 비번 : Wi-Fi 비번 입력
                - 무선 LAN 국가: KR(대한민국)
            - 로케일 설정
                - 키보드 레이아웃 : KR
                - 언어/지역은 한국으로 
            - 서비스 
                - SSH활성화 체크 : 원격접속에 필요한 확인
    3. 공유기에서 Wi-Fi 정보확인

        - 웹브라우저에서 IP(공유기)입력해서 접속
        - 로그인 > 관리도구 > 무선랜 관리 > Wi-Fi 기본설정 메뉴 이동
        - 네트워크 이름(SSID) 및 비밀번호 확인

    4. 소프트웨어 추가 다운로드 

    VNC Viewer 공식 다운로드 (원격 데스크탑 연결용)

    - VNC Viewer 공식 다운로드 페이지 

        - https://www.realvnc.com/en/connect/download/viewer/

    - 사용 중인OS에 맞는 설치 및 다운로드

    SD Card Formatter 다운로드 (SD카드 초기화용)
    - SD카드 포맷 공식 유틸리티
        - https://www.sdcard.org/downloads/formatter/
    - Windows or MacOS 다운
    - 마이크로 SD카드 꽂고 포맷 

    5. Raspberry Pi VNC 원격접속 설정 (이걸쓰는 편임)

        - SSH 접속(PuTTY 사용)
        1. PuTTY 실행
        2. Host Name에 라즈베리파이 IP주소 입력
        3. 기본 포트는 22 연결타입은 SSH로 오픈 
        4. 로그인 화면에서 로그인

        - 라즈베리 파이 설정 

        - 라즈베리파이 업데이트     
            `sudo apt update `
        - 라즈베리파이 업그레이드 
            `sudo apt upgrade` 
        - 가상환경 생성
            `python -m venv --system-site-package env`
        - 가상환경 진입
            `source env/bin/activate`

        - putty 종료 명령어 
            `sudo shutdown -h now`
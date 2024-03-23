# embedded-system-2024
IoT 개발자 임베디드 시스템 학습 리포지토리

##1일차(2024-03-12)
- 개발환경 설치
	- Visual Studio 2022 Community 설치
	- 라즈베리파이 설치 : https://www.raspberrypi.com/software/
	- sd card formatter 설치 : https://www.sdcard.org/downloads/formatter/sd-memory-card-formatter-for-windows-download/
		- sd카드 리더기를 usb포트에 삽입 후 포맷작업
	- putty 설치 : https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html
	- C, C++ 소스코드 실행
	- C++에 대해 설명

##2일차(2024-03-13)
- 라즈베리파이 업데이트
	- sudo apt update
	- sudo apt upgrade -y
	- clear = 편집기: 코드 작업할 때 사용하는 프로그램(nano) = 한글->
	- 기본 명령어(C) = 기존 PC 같이 사용 안됨 -> 순서에 맞추어서 사용(동작 중에 다른 명령어 처리 안됨)
- cd / ls / pwd / mkdir etc...
- <흰색은 파일, 파란색은 폴더
- 리눅스 명령어
  (https://m.hanbit.co.kr/channel/category/category_view.html?cms_code=CMS6390061632)
- func(함수 정의 -> 함수 호출)
	- 함수 선언 -> 함수 호출 -> 함수 정의
- input 선언
- C언어로 계산기 만들기
- node로 이용한 list
	- FreeList
	- ShowNode
	- AddNode(전위함수)
	- AppendNode(후위함수)
	- 연결 리스트의 노드 구조체 정의
	- delete
- sudo nano /etc/nanorc -> 관리자 권한(sudo)으로 실행
		
##3일차(2024-03-14)
- VNC Viewer 설치 : https://www.realvnc.com/en/connect/download/viewer/
	- putty -> vncserver-virtual
- 기본 명령어(추가)
	- <초록색은 실행파일>
	- gcc: 컴파일 -> 형식: gcc -o 만들실행파일명 소스파일명 ->
		- gcc test01.c => a.out이라는 기본적인 실행파일 생성(출력(./a.out)은 동일하게 됨)
	- ./: 출력
	- mv: 파일이동, 수정 -> ex) mv test01.c test02.c => test01.c를 test02.c로 수정(변경)
	- cp: 파일 복사 -> ex) cp test03.c test02.c => test.c를 복사하여 test03.c를 생성
- 입력과 출력 // 파일: printf01.c/ printf02.c/ prinf03.c/ func01.c/ func02.c / tri01.c
	- printf : 출력
	- 

##4일차(2024-03-15)
- 연결리스트 : 하나의 노드가 값과 다음 노드를 가리키는 노드로 이루어진 자료구조, 배열의 단점 보완 (배열은 칸 자체를 삭제할 수 없지만 연결리스트는 노드 자체를 삭제할 수 있음.)
	- head 포인터 : 연결리스트에서 첫 번째 노드의 주소를 가지는 포인터
	- 노드 : 연결 리스트의 아이템
		- 데이터 필드 : 연결 리스트의 각 노드에 저장된 데이터
		- 링크 필드 : 다른 노드의 주소를 저장하는 부분


##5일차(2024-03-18)


##6일차(2024-03-19)


##7일차(2024-03-20)


##8일차(2024-03-21)


##9일차(2024-03-22)


##10일차(2024-03-25)


##11일차(2024-03-26)


##12일차(2024-03-27)


@구조체(structure)
하나 이상의 변수(포인터 변수와 배열 포함)을 묶어서
새로운 자료형으로 정의하는 도구이다.

프로그램상에서 마우스의 좌표정보를 저장하고 관리해야 한다고 가정해보자.
마우스가 움직인다면, 두 변수의 저장된 값이 동시에 갱신되어야 한다.

이 둘을 묶어놓으면 프로그램상에서 데이터 표현과 관리가 용이할텐데..
해서 생긴 녀석이 구조체다.
struct point->point라는 이름의 구조체 정의
{
	int xpos;->point 구조체를 구성하는 멤버 xpos
		int ypos;->point 구조체를 구성하는 멤버 ypos
};

point라는 이름이 int나 double처럼 자료형의 이름이 된다.
이를 가리켜 '사용자 정의 자료형'(user defined data type)이라 한다.

@구조체 변수의 선언과 접근
struct type_name val_name;->구조체 변수선언의 기본 형태
	ex)
	struct pos
{
	int xpos;
	int ypos;
};

pos.xos = 20; ->구조체 변수 pos의 맴버 xpos에 20을 저장
printf("%s \n", pos.xos);
두 점의 거리를 계산하는 공식

구조체의 맴버로 배열이 선언되면 배열의 접근방식을 취하면 되고,
구조체의 맴버로 포인터 변수가 선언되면 포인터 변수의 접근방식을 취하면 된다.

struct point
{
	int xpos;
	int ypos;
}pos1, pos2, pos3;->구조체의 정의와 변수의 선언

struct point
{
	int xpos;
	int ypos; ,
};
struct point pos1, pos2, pos3;->구조체 변수의 선언


	@구조체 변수의 초기화
	struct person {
	char name[20];
	char phoneNum[20];
	int age;
};
struct person = { "paul", "010-2084-0358",26 }

	초기화 과정에서는 문자열 저장을 위해서 strcpy 함수를 호출하지 않아도 된다.

	@구조체 배열의 선언과 접근
	선언 방식은 일반적인 배열과 동일하다.

	struct point {
	int xpos;
	int ypos;
};
struct point arr[3];
for (int i = 0; i < 3; i++)
{
	printf("점의 좌표: ");
	scanf("%d %d", &arr[i].xpos, &arr[i].ypos);
}
for (int i = 0; i < 3; i++)
	printf("[%d %d]", arr[i].xpos, arr[i].ypos);

@구조체 배열의 초기화
struct person arr[3] = {
	{ "종현", "123-456-678", "12" },
	{ "민수", "563-453-558", "22" },
	{ "우마", "123-412-777", "16" }
}

@구조체 변수와 포인터
pptr.xpos = 10; == pptr->xpos = 10;
pptr->xpos += 1;

@포인터 변수를 구조체의 맴버로 선언하기
struct point {
	int xpos;
	int ypos;
	struct point* ptr;->구조체 point의 포인터 변수 선언
};

@구조체 변수의 주소 값과 첫 번째 맴버의 주소 값
구조체 변수의 주소값은 구조체 변수의 첫 번째 맴버의 주소 값과 동일하다.

바이트 얼라인먼트(byte alignment)
구조체 멤버의 크기가 다를 경우 멤버 사이에 빈 패딩바이트를 넣어 멤버를 정렬함.
이를 바이트 얼라인먼트라 함.
구조체 순서를 바꿔주면 패딩 바이트를 줄일 수 있음

- 배열, 포인터, 다른 구조체도 멤버로 넣어 확장 가능
- 자료형이 같은 구조체 변수는 대입 연산 가능, 함수의 매개변수로 가능

84.구조체 포인터와->연산자
구조체 변수의 주소는 구조체 포인터에 저장하며 구조체 변수 전체를 가르킨다.
struct score* ps = &yuni;
(*ps).kor;
ps->eng;
배열 표현
lp[i].name
포인터 표현
(*(lp + i)).name
->연산자 사용
(lp + i)->name

85.자기 참조 구조체
연결 리스트
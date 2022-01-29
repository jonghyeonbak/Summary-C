@typedef 선언
typedef 선언은 기존에 존재하는 자료형의 이름에,
새 이름을 부여하는 것을 목적으로 선언한다.

typedef 선언에 있어서,
새로운 이름의 부여는 가장 마지막에 등장하는 단어를 중심으로 이뤄진다.

@구조체의 정의와 typedef 선언
typedef struct point {
	int xpos;
	int ypos;
}point;
이게 일반적이다.
struct 선언의 생략을 위해 구조체의 이름을 대상으로 선언을 한다.

	typrdef struct point
{
	int xpos;
	int ypos;
} point;

point pos1;		    typedef 선언을 이용한 변수의 선언 ok!
struct point pos2;  struct 선언을 추가한 형태의 변수 선언 ok!

	@구조체의 이름
	typedef struct A
{

}B;
라고 했을 때 보통 typedef로 정의된 이름으로 해당 구조체를 가르키는 게 일반적이다.

@구조체의 이름 생략
typedef struct person
{
	char name[20];
	char phoneNum[20];
	int age;
}Person;

typedef struct
{
	char name[20];
	char phoneNum[20];
	int age;
}Person;

이렇게 생략해도 되지만, 이렇게 선언하면, struct person man; 이런 선언은 못한다.
프로그래머의 프로그래밍 성향에 따라서 구조체의 이름을 생략하는 경우도 흔하니,
구조체의 이름이 생략 가능함을 잊지 않길 바란다.

@함수로의 구조체 변수 전달과 반환
@함수의 인자로 전달되고 return문에 의해 반환되는 구조체 변수
void SimpleFunc(int num) { .... }
int main(void)
{
	int age = 24;
	SimpleFunc(age);->age에 저장된 값이 매개변수 num에 복사(전달)
}

@구조체 변수를 대상으로 가능한 연산
구조체 변수간 대입연산의 결과로 맴버 대 맴버의 복사가 이뤄진다.
typedef struct point {
	int xpos;
	int ypos;
}point;

point pos1 = { 1,2 };
point pos2;
pos2 = pos1;
cout << pos1 << pos2;->같다.

@구조체의 유용함에 대한 논의와 중첩 구조체
@구조체를 정의하는 이유
구조체를 통해서 연관 있는 데이터를 하나로 묶을 수 있는 자료형을 정의하면,
데이터의 표현 및 관리가 용이해지고, 그만큼 합리적인 코드를 작성할 수 있게 된다.


@중첩된 구조체의 정의와 변수의 선언
배열이나 포인터 변수가 구조체의 맴버로 선언될 수 있듯이, 구조체 변수도 구조체의 맴버로 선언될수 있다.
구조체 안에 구조체 변수가 맴버로 존재하는 경우를 가리켜 '구조체의 중첩'이라 한다.
사실 명칭을 부여하면서 까지 공부할 내용은 아니다.

@공용체(union type)의 정의와 의미
구조체와 비슷하면서 다르다.
typedef struct sbox {
	int mem1;
	int mem2;
	double mem3;
}Sbox;

typedef union sbox {
	int mem1;
	int mem2;
	double mem3;
}Ubox;
sizeof(Sbox) -> 16   모든 맴버의 크기를 합한 결과
sizeof(Ubox) -> 8    맴버 중에서 가장 크기가 큰 double의 크기만 계산된 결과

cout << ubox.num1 << ubox.num2 << ubox.num3 < endl;
셋 다 주소값이 똑같다.->공용체의 할당특성
공용체의 맴버들이 메모리 공간을 공유하고 있다.

@공용체의 유용함은 다양한 접근방식을 제공하는 데 있다.
'하나의 메모리 공간을 둘 이상의 방식으로 접근할 수 있다'
typedef struct dbshort {
	unsigned short upper;
	unsigned short lower;
}DBShort;
typedef union dbshort {
	int iBuf;
	char bBuf[4];
	DBShot sBuf;
}RdBuf;

RDBuf buf;
printf("정수 입력: ");
scanf("%d", &(buf.iBuf));

printf("상위 2바이트: %u \n", buf.sBuf.upper);
printf("하위 2바이트: %u \n", buf.sBuf.lower);
printf("상위 1바이트 아스키 코드: %c \n", buf.bBuf[0]);
printf("하위 1바이트 아스키 코드: %c \n", buf.bBuf[3]);

@열거형(Enumerated Type)의 정의와 의미
@열거형의 정의와 벼수의 선언
구조체와 공용체는 맴버에 저장할 값의 유형을 결정했었다.(자료형의 선언을 통해서)
하지만 열거형의 경우에는 저장이 가능한 값 자체를 정수의 형태로 결정한다.
enum syllable
{
	Do = 1, Re = 2, Mi = 3, Fa = 4, So = 5, La = 6, Ti = 7
};
Do를 정수 1을 의미하는 상수로 정의한다.
그리고 이 값은 syllable형 변수에 저장이 가능하다.
typedef enum syllable
{
	Do = 1, Re = 2, Mi = 3, Fa = 4, So = 5, La = 6, Ti = 7
}syllable;

void sound(syllable sy)
{
	switch (sy)
	{
	case Do:
		puts("도는 하얀 도라지 "); return;
	case Re:
		puts("레는 둥근 레코드 "); return;
	case Mi:
		puts("미는 파란 미나리 "); return;
	case Fa:
		puts("파는 예쁜 파랑새 "); return;
	case So:
		puts("솔은 작은 솔방울"); return;
	case La:
		puts("라는 라디오고요~"); return;
	case Ti:
		puts("시는 졸졸 시냇물~"); return;
	}
	puts("다 함께 부르세~ 도레미파 솔라시도 솔 도~ 짠~");
}

int main()
{
	syllable tone;
	for (tone = Do; tone <= Ti; tone += 1)
		sound(tone);
	return 0;
}
열거형 상수들은 int형으로 표현되는 상수이기 때문에 1, 2, 3, ..을 대신해도 된다.

@열거형 상수의 값이 결정되는 방식
값을 명시하지 않으면 열거형 상수의 값은 0에서부터 시작해서 1씩 증가하는 형태로 결정된다.

@열거형의 유용함은 이름있는 상수의 정의를 통한 의미의 부여에 있다.
구조체와 공용체는 자료형의 정의에 의미가 있다.
즉, 변수를 선언하기 위해서 자료형을 정의하는 것이다.그렇다면 열거형은 ?
Do, Re, Mi와 같이 연관이 있는 이름을 동시에 상수로 선언할 수도 있다.

"열거형의 유용함은 둘 이상의 연관이 있는 이름을 상수로 선언함으로써,
"프로그램의 가독성을 높이는 데 있다."

88.typedef 형 재정의

- 구조체도 자료형이 같으면 배열을 선언 가능
- 자기 참조 구조체는 연결 리스트를 만들 때 사용
- 공용체 변수의 크기는 멤버의 수에 비례 ㄴㄴ
- 열거형 멤버는 열거형 변수에 저장될 값을 나열
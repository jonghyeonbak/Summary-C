@파일의 분할
컴파일러는 파일 단위로 컴파일을 진행한다.

@외부에 선언 및 정의되었다고 컴파일러에게 알려주기
extern int num;  int형 변수 num이 외부에 선언되어 있다.

num.c
int num = 0;

func.c
extern int num;

void increment(void)
num++;
int getnum(void)
return num;

main.c
extern void increment(void);
extern intgetnum();
int main()
printf(...);
increment();

@다른 파일에서 접근 못하게 막기
static 전역 변수를 사용하면 된다.

static int num = 0;
int형 변수  num의 접근범위는 파일 내부로 제한한다.

@둘 이상의 파일을 컴파일하는 방법, static에 대한 고찰
@파일 정리
#첫 번째 방법: 이미 만들어진 파일을 ㅍ프로젝트에 추가하는 방법
#두 번째 방법: 프로젝트에 파일 추가한 후, 코드를 삽입하여 컴파일 하는 방법

@함수에도 static 선언 가능
static void MinCnt()  외부 파일에서 호출 불가능
{
	cnt--;
}
함수를 위처럼 정의하면 extern 선언을 하더라도 접근 불가능.
파일 내에서만 호출할 경우, 코드의 안정성을 부여하기 위해 사용한다.

@헤더파일의 디자인과 활용
#include 지시자의 의미
파일의 내용을 단순히 포함시키는 용도로 사용된다.

@헤더파일을 include 하는 두 가지 방법
#include <헤더파일>
#include "헤더파일"

두 방법의 차이점은 포함시킬 헤더파일의 기본 경로이다.
1번 방법은 표준 헤더파일에 사용.
2번 방법은 프로그래머가 정의한 헤더파일을 포함시킬 때 사용

@절대경로
드라이브명과 디렉토리 명을 명시하는 경로
절대 경로가 변경되지 않는다.
컴퓨터가 바뀌어도 말이다.

@상대경로
실행하는 컴퓨터의 환경에 따라 경로가 바뀌는 것

@헤더파일에 담으면 좋은 것
매크로의 명령문도 파일 단위로만 유효하다.

@구조체는 어디에 둘까
구조체의 선언과 정의는 헤더파일에 삽입해도 좋고,
하나의 소스파일 내에서만 사용되는 구조체면 소스파일에 정의하는 것도 좋다.

@조건부 컴파일을 활용한 중복 삽입 문제의 해결
#ifndef __STDIV2_H__
#define __STDIV2_H__

typedef struct div
int quotient; 몫
int remainder; 나머지
div;

#endif

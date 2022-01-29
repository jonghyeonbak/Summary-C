함수
반환형태    함수이름    입력형태
int           main         (void)
{
	함수의 몸체
}

함수를 만드는 이유?
문제의 발생이나 프로그램의 요구사항 변경으로 인한 소스코드의 변경이 필요할 때,
변경의 범위를 축소 및 제한할 수 있다.

printf 함수도 반환을 한다.

전달인자의 유무와 반환값의 유무에 따라서 함수를 4가지 형태로 나눈다.

A.매개변수  B.함수이름        C. 매개변수(parameter)      (함수원형)(function type)
@int            Add          (int num1, int num2)
{
	int result = num1 + num2;
	return result;         return에 저장된 값을 Add 함수를 호출한 영역으로 전달.         D.값의 반환
}
전달인자는 int형 정수 둘, 이 둘을 이용한 덧셈 진행
덧셈결과는 반환되며, 반환형도 int로 선언.
함수의 이름은 Add.

@void ShowAddResult (int num)   인자 전달 o, 반환 값 x
{
	printf("덧셈 결과 출력: %d ", num);
}
void print(char ch, int count)->데이터를 받아 화면에 출력하는 함수에 주로 사용

@int ReadNum(void) 인자 전달 x, 반환 값 o
{
	int num;
	scanf("%d", &num);
	return num;
}
int get_num(void)->키보드에서 입력받은 값을 반환할 때 주로 사용
음수가 입력되면 경고 메세지 출력 후 다시 입력.
예외 처리 - 프로그램 실행후 발생 가능한 예외 상황을 대비해 코드 추가

@void HowToUseThisProg(void)  인자 전달 x, 반환 값 x
{
	printf("두 개의 정수를 입력하면 덧셈 결과 출력");
printf("자! 그럼 두 개의 정수를 입력해라!");
}
29.매개변수, 반환 값 둘다 없는 함수
void print_line()->일정한 문자열을 여러 번 출력하는 경우

return의 2가지 의미중 한가지 의미만 살리기
1.함수를 빠져 나간다.
2.값을 반환한다.

ex)void NoReturnType(int num)
{
	if (num < 0)
		return;
}

컴파일은 위에서 아래로 순서대로 내려가므로 
함수를 미리 선언하고 정의를 따로 해야 사용가능하다.

함수의 선언에는 매개변수의 이름을 생략해서 선언해도 가능하다.
==========================================================================================
변수의 존재기간과 접근범위

@지역변수(local variable)의 특징
1.함수 내에서만 존재 및 접근이 가능하다.
2.중괄호 내에 선언되는 변수는 모두 지역변수다.
3.해당지역을 벗어나면 자동으로 소멸된다.
4.따라서 해당 지역이 다르면 이름이 같아도 무방하다.
5.stack이라는 메모리 영역에 할당된다.
6.접시를 쌓듯이 할당된다.
7.해당 선언이 실행될 때 메모리 공간에 할당되었다가, 선언문이 존재하는 함수가 반환(종료)을 하면 메모리 공간에서 소멸된다.
8.반복문이나 조건문에도 선언이 가능하다.
9.for문에 의한 반복은 중괄호의 진입과 탈출을 반복하면서 이루어진다.
10.if문 내에서는 main함수의 동일한 이름의 변수에 가려진다.
11.함수를 선언할 때 정의하는 매개변수도 지역변수의 일종이다.
12.지역변수는 자동변수라고도 불린다.(automatic variable)
===============================================================================================
@전역변수의 특징 global variable
1.프로그램 전체 영역 어디서든 접근이 가능하다.
2.프로그램의 시작과 동시에 메모리 공간에 할당되어 종료 시까지 존재한다.
3.초기화 하지 않으면 0으로 초기화된다.
4.전역변수와 동일한 이름의 지역변수가 선언되면, 해당 지역 내에서는 전역변수가 가리워지고, 지역변수로의 접근이 이루어진다.
5.전역변수의 수가 증가하면, 좋은 프로그램이 되기 어렵다.(스파게티 코드)
===================================================================================================
@static 변수의 특징 static variable
1.선언된 함수 내에서만 접근이 가능하다.
2.전역변수나 지역변수 둘다 선언가능하다.
3.딱 1회 초기화되고 프로그램 종료 시까지 메모리 공간에 존재한다.
=========================================================
@register 변수의 특징 register variable
1.레지스터는 CPU내에 존재하는 가장 작은메모리이며, 연산이 매우 빠르다.
2.레지스터 연산은 레지스터의 활용을 위해 선언하지만, 컴파일러가 직접 판단하여 결정내린다.
========================================================================================
@재귀함수
함수 내에서 자기 자신을 호출한다.
void fruit(int count);
int main()
fruit(1)->처음 호출하니 인수는 1

void fruit(int count) - 호출 횟수를 매개변수에 저장
printf("apple\n");
if (count == 3)return;   -호출 횟수가 3이면 반환
fruit(count + 1);           -재호출 할 때 호출 횟수 1 증가
printf("jam\n");
apple
apple
apple
jam
jam

재귀 함수는 직전에 호출한 곳으로 돌아간다.

함수 정의부
선언부

69.값 복사 전달 call - by - value
70.주소 전달 방법 call - by - reference

- 값을 복사해서 인수로 전달하면 호출하는 함수의 값은 변하지 않음
- 호출하는 함수의 값이 바뀌려면 주소를 인수로 전달 해야 함.
- static 변수나 전역 변수같이 함수가 반환 후에도 메모리가 유지되면 주소를 반환한다.

값을 넘겨준다							값을 반환
호출하는 함수 int a = 10; func(a);      int a; a = fun();
호출되는 함수 void func(int b);         return b;
주소를 넘겨준다                         주소 반환
호출하는 함수 int a = 10; func(&a);     void func(int* p);
호출되는 함수 int* p; p = func();       int b = 10; return &b;

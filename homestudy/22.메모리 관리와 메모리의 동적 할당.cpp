@C언어의 메모리 구조
프로그램을 실행하면 해당 프로그램의 실행을 위한 메모리 공간이 운영체제에 의해서 미리 마련된다.
그리고 이 메모리 공간 내에서 변수가 선언되고, 문자열이 선언되는 것이다.

@메모리의 구성
code  영역
data  영역
heap  영역
stack 영역

@메모리 영역별로 저장되는 데이터 유형
#code area
실행할 프로그램의 코드가 저장되는 메모리 공간

#data area
전역변수와 static변수가 할당된다.
프로그램 시작할 때 메모리 공간에 할당, 종료시까지 남아있는다.

#stack area
지역변수와 매개변수가 할당된다.
함수가 시작될 때 메모리 공간에 할당, 함수를 빠져나가면 소멸

#heap area
사용자가 원할 때 할당, 소멸

@프로그램의 실행에 따른 메모리의 상태 변화
스택 영역은 쟁반 위에 접시를 쌓아 올리고 나서,
위에서부터 접시를 하나씩 내려 놓는다고 생각해보자.

가장 아래에 위치한 접시가 마지막에 내려질 것이다.

@메모리의 동적 할당
#malloc 과 free 함수
heap 영역의 메모리 공간 할당과 해제
#include <stdlib.h>
void* malloc(size_t size);->haep 영역으로 메모리 공간 할당
void free(void* ptr);->heap 영역에 할당된 메모리 공간 해제

ex)
void* ptr1 = malloc(4);  -> 4바이트가 heap 영역에 할당
void* ptr2 = malloc(12);  -> 4바이트가 heap 영역에 할당

free(ptr1); ptr1이 가르키는 4바이트 메모리 공간 해제
free(ptr2); ptr2이 가르키는 12바이트 메모리 공간 해제

@malloc 함수의 반환형이 void형 포인터인 이유와 heap 영역으로의 접근
malloc함수의 반환형은 void형 포인터이다.
void* ptr = malloc(sizeof(int)); int형 변수 크기의 메모리 공간 할당
*ptr = 20->에러

int* ptr1 = (int*)malloc(sizeof(int));
double* ptr2 = (double*)malloc(sizeof(double));
int* ptr3 = (int*)malloc(sizeof(int) * 7);
double* ptr4 = (double*)malloc(sizeof(double) * 9);

malloc 함수는 메모리 공간의 할당에 실패할 경우 null을 반환한다.
메모리 할당의 성공여부를 확인하려면 ?
int* ptr = (int*)malloc(sizeof(int));
if (ptr == null)
{
	메모리 할당 실패에 따른 오류 처리
}

malloc 함수의 호출을 통한 메모리 공간을 가리켜 '동적 할당(dynamic allocation)'이라 한다.
할당되는 메모리의 크기를 컴파일러가 결정하지 않고, 프로그램의 실행 중간에 호출되는 malloc 함수가
결정하기 때문이다.

@free 함수를 호출하지 않으면 프로그램이 종료 후에도 메모리가 남나요?
프로그램이 종료되면 운영체제에 의해 메모리 공간이 전부 해제된다.
하지만 메모리 공간 정리라고 생각하고 malloc 함수의 호출 횟수만큼 free함수를 호출 하는 게 중요!

@문자열을 반환하는 함수를 정의하는 문제의 해결
#include <stdion.h>
#include <stdlib.h>

char* ReadUserName()
{
	char* name = (char*)malloc(sizeof(char) * 30);
	printf("What's your name?");
	gets(name);
	return name;
}
int main()
{
	char* name1;
	char* name2;
	name1 = ReadUserName();
	printf("name1: %s \n", name1);
	name2 = ReadUserName();
	printf("name2: %s \n", name2);

	printf("againg name1: %s \n", name1);
	printf("againg name2: %s \n", name2);
	free(name1);
	free(name2);
	return 0;
}

@malloc 함수의 사촌 뻘 calloc 함수
#include <stdlib.h>
coid* calloc(size_t elt_count, size_t elt_size)
malloc 함수와의 유일한 차이점은 메모리 공간의 할당을 위한 인자의 전달방식에 있다.

malloc 함수의 호출방식
"총 120바이트를 heap 영역에 할당 해주세요"

calloc 함수의 호출방식
"4 바이트 크기의 블록(elt_size)30개를(elt_count) heap 영역에 할당해주세요."

malloc과 calloc의 유일한 차이점 2가지
1.함인자를 전달하는 방식
2.malloc은 초기화 하지 않으면->쓰레기 값, calloc은 초기화 하지 않으면 -> 0으로 자동 초기화

@heap에 할당된 메모리 공간 확장 시 호출하는 realloc 함수
#include <stdlib.h>
void* realloc(void* ptr, size_t size);

"ptr이 가르키는 메모리의 크기를 size 크기로 조절해줘(늘려줘)"

int* arr = (int*)malloc(sizeof(int) * 3);   ->길이가 3인 int형 배열 할당
arr = (int*)realloc(arr, sizeof(int) * 5);  ->길이가 5인 int형 배열로 확장

malloc 함수가 반환한 주소 값과 realloc 함수가 반환한 주소 값이 같은 경우
기존에 할당된 메모리 공간의 뒤를 이어, 확장할 영역이 넉넉한 경우에 발생한다.

malloc 함수가 반환한 주소 값과 realloc 함수가 반환한 주소 값이 같지 않은 경우
힙의 다른 위치에, 
새로이 요구하는 크기의 메모리 공간을 별도로 할당해서 이전 배열에 저장된 값을 복사하기도 한다.


##메모리 동적할당
79.malloc, free 함수
#include <stdlib.h>
void* malloc(unsigned int size);
void free(void* p);

메모리 해제를 안하면 메모리 누수가 발생 될 수 있음.

동적 할당 배열처럼 쓰기
pi = (int*)mallco(5 * sizeof(int));

calloc 함수
0으로 초기화 해줌
double* pd;
pd = (double*)calloc(5, sizeof(double));

recalloc 함수
함수의 크기를 조절함
pi = (int*)recalloc(pi, 10 * sizeof(int));

80.메모리 영역
code area - 실행 파일을 위한 영역(함수)
stack area - 지역 변수
data area - 전역 변수ㅡ 정적 변수
heap - 동적 할당, 사용한 후 nullptr로 초기화 시켜줘야함

81.동적 할당을 사용한 문자열 처리
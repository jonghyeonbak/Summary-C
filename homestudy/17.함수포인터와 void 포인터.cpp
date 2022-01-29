@함수 포인터의 이해
프로그램 실행의 흐름을 구성하는 함수들도 바이너리 형태로 메모리 공간에 저장되어서 호출 시 실행된다.
이렇게 메모리상에 저장된 함수의 주소 값을 저장하는 포인터 변수가 바로 '함수 포인터 변수'이다.

배열의 이름이 배열의 시작주소 값을 의미하듯,
함수의 이름도 함수가 저장된 메모리 공간의 주소 값을 의미한다.

int SimpleFunc (int num){....}  -> 기본 선언
반환형		  int
매개변수 선언 int num
이 상황에서 함수의 이름 SimpleFunc는 
SimpleFunc 함수의 주소 값을 의미하는 상수형태의 함수 포인터이다.

함수이름의 포인터 형은 반환형과 매개변수의 선언을 통해서 결정짓도록 약속되어 있다.
따라서, 반환형이 int이고 매개변수로 int형 변수 하나가 선언된 포인터 형(type)이다.

@적절한 함수 포인터 변수의 선언
int (*fptr) (int) 
반환형이 int이고, 매개변수 선언이 int 하나인 fptr이름의 함수 포인터

ex)
int SoSimple(int num1, int num2){...}
int(*fptr)(int, int);
fptr = SoSimple;
fptr(3, 4) == SoSimple(3, 4);

void SimpleAdder(int n1, int n2)
{
	printf("%d + %d = %d \n", n1, n2, n1 + n2);
}
void ShowString(char* str)
{
	printf("%s \n", str);
}
void main()
{
	char* str = "Function Pointer";
	int num1 = 10, num2 = 20;

	void(*fptr1)(int, int) = SimpleAdder;
	void(*fptr2)(char* ) = ShowString;

	fptr1(num1, num2);
	fptr2(str);
}

@형(type)이 존재하지 않는 void 포인터
void* ptr;
void 포인터는 무엇이든 담을 수 있는 바구니에 비유할 수 있다.
어떠한 변수의 주소 값, 함수의 주소 값도 담을 수 있다.

void SoSimpleFunc(void)
{
	printf("I'm so simple");
}

int main()
{
	int num = 20;
	void* ptr;

	ptr = &num;
	prinrf("%p \n", ptr);   -> 변수 num의 주소 값 저장

	ptr = SoSimpleFunc;
	printf("%p \n", ptr);   -> 함수 SoSimpleFunc의 주소 값 저장
	return 0;
}

좋게만 보일 수도 있지만,
void형 포인터 변수는 어떠한 포인터 연산도 하지 못한다.
값의 변경이나 참조또한 불가능하다. 

void형 포인터 변수에는 가르키는 대상에 대한 어떠한 형(type)정보도 담겨있지 않기 때문이다.
int main()
{
	int num = 20;
	void* ptr = &num;
	*ptr = 20;   -> 컴파일 에러
	ptr++;		 ->컴파일 에러
}
포인터 형은 일단 주소 값에만 의미를 두고, 포인터의 형은 나중에 결정한다.

@main 함수로의 인자 전달
int main(void){...} -> int main(int argc, char* argv[]){...} -> 이것도 가능

@main함수를 통한 인자의 전달
{
	int i = 0;
	printf("전달딘 문자열의 수: %d \n", argc);

	for (i = 0; i < argc; i++)
		printf("%d번째 문자열: %s \n", i + 1, argv[i]);
	return 0;
}
프로그램 실행과정에서 입력한 내용이 프로그램 안으로 전달되어서 출력이 이뤄진다.

@char* argv[]
void SimpleFunc(TYPE* arr) { .... }
void SimpleFunc(TYPE arr[]) { .... }

void SimpleFunc(char** arr) { .... }
void SimpleFunc(char* arr[]) { .... }

main함수의 매개변수 argv는 char형 더블 포인터 변수이고,
이는 char형 포인터 변수로 이뤄진 1차원 배열의 이름을 전달받을 수 있는 매개변수이다.

void ShowAllString(int agrc, char* argv[])    
{
	int i;
	for (i = 0; i < argc; i++)
		printf("%s \n", argv[i]);
}

int main()
{
	char* str[3] = { "A", "B", "C" };
	ShowAllString(3, str);
	return 0;
}
argv는 char형 더블 포인터 변수이다.
따라서 argv에는 char** 형 데이터(주소 값)가 전달될 수 있다.

배열이름 str이 가르키는 첫 번째 요소가 char* 형 데이터이므로,
배열이름 str의 형은 char** 이다.그래서 위 함수의 두 번째 인자로 전달이 가능하다.

@인자의 형성과정
c : \ > ArgcArgv I like you
문자열1 "ArgcArgv"
문자열2 "I"
문자열3 "like"
문자열4 "you"
공백이 문자열을 나누는 기준이다.
총 4개의 문자열이 하나의 배열에 묶여서 main함수의 두 번째 인자로 저달이 되며,
첫 번째 인자로는 문자열의 수가 전달된다.

strArr[0]	  ->"ArgcArgv\0"
strArr[1]	  ->"I\0"
strArr[2]     ->"like\0"
strArr[3]     ->"you\0"
strArr[4] null

char* strArr[5]; -> 인자의 구성
main(4, strArr) 
main함수는 이런 형태로 호출된다.
	
int ary[3][4] = { { 1,2,3,4, },{ 5,6,7,8 },{ 9,10,11,12 } };
int(*pa)[4];
int i, j;
pa = ary;

함수명은 함수 정의가 있는 메모리의 시작 위치다.
int(*fp)(int, int);
int res;

fp = sum;
res = fp(10, 20);
printf("result: %d\n", res);

int sum(int a, int b) {
	return a + b;
}
함수의 형태만 같으면 모든 함수에 사용 가능
78.void 포인터
가리키는 자료형이 정해지지 않은 포인터
void* vp;
어떤 주소든 저장 가능하지만 포인터연산 불가

- 함수 포인터에 함수명을 대입하면 함수처럼 호출 가능
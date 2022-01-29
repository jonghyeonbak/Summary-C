모든 상수 문자는 아스키 코드 값으로 바뀌어 숫자로 저장되고 연산
49.%c 변환 문자는 화이트 스페이스(공백, 탭, 개행문자)도 입력하며, %c앞에 공백을 넣으면,
화이트 스페이스를 입력에서 제외할 수 있다.
50.버퍼
프로그램을 실행하는 중에 운영체제가 자동으로 할당되는 메모리의 저장 공간
51.입출력 함수가 버퍼를 사용하면 좋은점
1.데이터를 안정적으로 입력받을 수 있음
2.입력장치와 독립적으로 사용 가능
52.eof end of file
res = scanf("%c", &ch);->scanf 함수의 반환값을 res에 저장
if (res == EOF) break;->EOF는 - 1로 바뀌므로 결국 res와 - 1을 비교

- scanf 함수가 데이터를 입력할 땐 가장 먼저 버퍼의 상태를 확인
- 버퍼에 저장되는 데이터의 끝에는 항상 개행 문자가 있음
- scanf 함수는 ctrl + z 를 누르면 eof(-1) 반환

##문자열(상수)
53.문자열은 배열의 구조를 가지며 첫 번째 문자의 주소로 쓰인다.
- 주소로 접근해서 문자열을 바꾸면 안된다.ex) *"apple" = 't';
54.문자열은 주소이므로 char 포인터에 대입 가능
char* dessert = "apple";
dessert = "banana";
->banana
55.scanf 함수는 공백이 없는 연속 문자열만 입력받는다.
ex) apple jam 이라고 입력하면 jam은 버퍼에 남아있는다.
56.문자열 입력함수 fgets
최대 배열의 크기까지만 문자열을 입력함
fgets(배열명, 배열의 크기 확인, 표준 입력)
fgets(str, sizeof(str), stdin);
배열의 크기 - 1까지 저장함으로 항상 유의해야 함
57.개행 문자 제거
str[strlen(str) - 1] = '\0';
58.표준 입력 함수의 버퍼 공유 문제
printf("나이 입력: ");
scanf("%d", &age);
printf("이름 입력: ");
get(name);
printf("나이: %d, 이름: %s\n", age, neme);

키보드 입력 17->버퍼 1 7 \n
scanf에서 17이 빠져나가고 버퍼에 \n 개행이 남아있음
따라서 get(name)에는 남은 개행이 입력됨

@스트림과 데이터의 이동
데이터의 입력과 출력은 프로그램의 흐름을 뜻한다.
프로그램을 중심으로 프로그램 안으로 데이터가 흘러 들어오는 것이 입력,
프로그램 밖으로 데이터가 흘러 나가는 것이 출력이다.
대표적인 입력장치 - 키보드, 파일
대표적인 출력 장치 - 모니터

@데이터의 이동수단이 되는 스트림
프로그램 상에서 모니터와 키보드를 대상으로 데이터를 입출력하기 위해서는
이들을 연결 시켜주는 다리가 필요하다.이러한 다리의 역할을 하는 매개체를
스트림(stream)이라고 한다.
(출력 스트림)
실행중인 프로그램->모니터
(입력 스트림)
실행중인 프로그램 < -모니터

스트림은 운영체제에서 제공하는 소프트웨어적인 가상의 다리이다.
다시 말해, 운영체제는 외부장치와 프로그램과의 데이터 송수신의 도구가 되는 스트림을 제공한다.

@스트림의 생성과 소멸
콘솔(일반적으로 키보드와 모니터를 의미)입출력을 위한 '입력 스트림'과 '출력 스트림'은
프로그램이 실행되면 자동으로 생성되고, 프로그램이 종료되면 자동으로 소멸되는 스트림이다.

이 둘은 기본적으로 제공하는 '표준 스트림'이다.
stdin   표준 입력 스트림  키보드 대상으로 입력
stdout  표준 출력 스트림  모니터 대상으로 출력
stderr  표준 에러 스트림  모니터 대상으로 출력

스트림은 '한 방향으로 흐르는 데이터의 흐름'을 뜻한다.
스트림이란 단어에는 단 방향으로만 데어의 전송이 이뤄진다는 뜻이 담겨있다.

@문자 단위 입출력 함수
#putchar, fputc
문자 출력 함수
#include<stdio.h>
int putchar(int c);
int fputc(int c, FILE* stram);
인자로 전달된 문자를 모니터로 출력하는 함수이다.
인자로 전달된 문자정보를 stdout으로 표현되는 표준 출력 스트림에 전송하는 함수이다.

fputc 함수는 문자를 전송할 스트림을 지정할 수 있다.
즉 fputc 함수는 stdout뿐 아니라, 파일을 대상으로도 데이터를 전송할 수 있다.
fputc 함수의 두 번째 매개변수 stream은 문자를 출력할 스트림의 지정에 사용된다.
따라서 이 인자에 표준 출력 스트림을 의미하는 stdout을 전달하면, putchar 함수와 동일한 함수가 된다.

fputc 함수의 두 번째 인자로 파일의 스트림 정보를 전달하면, 해당 파일로 문자가 전달된다.

#getchar, fgetc
문자 입력 함수
#include<stdio.h>
int getchar();
int fgetc(int c, FILE* stram);

stdi으로 표현되는 표준 입력 스트림으로부터 하나의 문자를 입력받아서 반환하는 함수이다.
fgetc 함수도 하나의 문자를 입력받는 함수이다.
다만 getchar 함수와 달리 문자를 입력 받을 스트림을 지정할 수 있다.

int ch1, ch2;
ch1 = getchar(); 문자 입력
ch2 = fgetc(stdin); 엔터 키 입력


putchar(ch1);  문자 출력
fputc(ch2, stdout); 엔터 키 출력
return 0;
사실 두 개의 문자를 입출력하고 있지만,
'엔터 키'는 아스키코드 값이 10인 '\n'이기에 출력이 하나처럼 보인다.
getchar와 fgetc 함수의 반환형이 int이기 때문에 선언도 int로 해야 한다.

@문자 입출력에서의 EOF(End Of File)
파일의 끝을 표현하기 위해 정의해 놓은 상수이다.
파일을 대상으로 fgetc 함수가 호출되면, 그리고 그 결과로 EOF가 반환되면,
이는 '파일의 끝에 도달해서 더 이상 읽을 내용이 없다'는 뜻이다.

키보드를 대상으로 하는 fgetc 함수와 getchar함수는 언제 EOF를 반환할까 ?
-함수 호출의 실패
- Windows에서 ctrl + z, Linux에서 ctrl + d가 입력될 때.

ex)
int ch;
while (1)
{
	ch = getchar();
	it(ch == EOF)
		break;
	putchar(ch);
}
return 0;

@반환형이 int이고, int형 변수에 문자를 담는 이유?
EOF는 -1로 정의된 상수이다.
따라서 어떠한 상황에서도 -1을 인식할 수 있는 int형으로 반환형을 정의해 놓은 것이다.

@문자 단위 입출력 함수의 존재이유?
printf와 scanf는 본래 서식지정을 통해 새로운 입출력의 형태를 구성하는 함수다.
화려한 기능을 제공하는 만큼 데이터 공간도 크고, 속도가 느리기 때문에 
문자 단위는 문자 단위 입출력 함수를 사용하는 것이 좋다.

@문자열 단위 입출력 함수
#puts, fputs
문자열 출력 함수
#include<stdio.h>
int puts(const int char* s);
int fputs(const int char* s, FILE* stram);
puts함수는 출력의 대상이 stdout, fputs 함수는 두 번째 인자를 통해서 출력의 대상을 정할 수 있다.

puts 함수가 호출되면 문자열 출력 후 자동으로 개행이 이뤄지지만,
fputs 함수가 호출되면 문자열 출력 후 자동으로 개행이 이뤄지지 않는다.

int puts(const char *str) - > 문자열 출력 후 자동 줄 바꿈
int fputs(const char *str, FILE* stream)
정상 출력하면 0반환, 실패하면 - 1(eof)반환

char str[80] = "apple juice";
char* ps = "banana";

puts(str);
fputs(ps, stdout);
puts("milk");
->apple juice
->bananamilk

- 문자열은 첫 번째 문자가 저장된 메모리의 주소로 바뀐다
- scanf함수는 중간에 공백이 포함된 문자열을 입력할 수 없다.
- gets 함수는 한 줄의 데이터를 char 배열에 저장한다.
- fgets 함수는 배열의 크기를 검사하는 기능을 가진 문자열 입력 함수다.

구분                char 포인터					char 배열
초기화			   char* pc = "mango";		char str[80] = "mango";
대입			   pc = "banana";			strcpy(str, "banana");
크기			   sizeof(pc) -> 4byte		sizeof(pc) -> 80byte
수정			   pc[0] = 't'; xxx		    pc[0] = 't'; ooo
입력			   scanf("%s", pc); xxx	    scanf("%s", str); ooo


#gets, fgets
#include<stdio.h>
int gets(char* s);
int fgets(char* s, int n, FILE* stram);
char str[7];  -> 7바이트의 메모리 공간 할당
gets(str);->입력 받은 문자열을 배열 str에 저장

미리 마련해 놓은 배열을 넘어서는 길이의 문자열이 입력되면, 할당 받지 않은 메모리 공간을 침범하여,
실행 중 오류가 발생할 수도 있다.그래서 가급적이면 fgets 함수로 호출하는 것이 좋다.

char str[7];
fgets(str, sizeof(str), stdin)->stdin으로부터 문자열 입력 받아서 str에 저장
stdin으로부터 문자열을 입력 받아서 배열 str에 저장하되, sizeof(str)의 길이만큼만 저장해라!

문자열을 입력 받으면 문자열의 끝에 자동으로 널 문자가 추가되기 때문에,
하나가 작은 길이의 문자열이 저장된다.

char str[7]
int i;

for (i = 0; i < 3; i++)
{
	fgets(str, sizeof(str), stdin);
	printf("Read %d: %s \n", i+1, str)
}

fgets 함수는 \n을 만날 때 까지 문자열을 읽어 들이는데,
\n을 제외시키거나 버리지 않고 문자열의 일부로 받아들인다.

@표준 입출력과 버퍼(buffer)
표준 입출력 함수를 통해서 데이터를 입출력 하는 경우,
해당 데이터들은 운영체제가 제공하는 '메모리 버퍼'를 중간에 통과하게 된다.

메모리 버퍼
데이터를 임시로 모아두는 메모리공간
				 (출력 버퍼)
실행중인 프로그램	 ->		모니터
				 (입력 버퍼)
실행중인 프로그램	 <-		모니터

키보드를 통해 입력되는 데이터는, 일단 입력버퍼에 저장된 다음에(버퍼링) 프로그램에 읽혀진다.
키보드로부터 입력된 데이터가 입력 스트림을 거쳐서 입력 버퍼로 들어가는 시점은 엔터 키가 눌릴 때.
엔터 키가 눌리기 전에는 입력 버퍼가 비워져있기에, fgets 함수가 문자열을 읽어 들이지 못한다.

@'버퍼링(Buffering)'을 하는 이유?
데이터 버퍼링을 하는 가장 큰 이유는 '데이터 전송의 효율성'때문이다.
데이터를 한 데 묶어서 이동시켜준다.
ex) 창고에 물건을 나를 때, 손으로 하나씩 나르는 것보다 손수레에 가득 채워 나르는 것이 빠른 것처럼.

#fflush 함수
출력 버퍼를 지워준다.
그 말 뜻은 출력버퍼에 저장된 데이터가 버퍼를 떠나서 목적지로 이동됨을 뜻한다.
#include<stdio.h>
int fflush(FILE* stream);

fflush(stdout);  -> 표준 출력버퍼를 비워라!

@입력버퍼는 어떻게 비우는가?
'입력버퍼의 비워짐'은 데이터의 소멸을 의미한다.

@입출력 이외에 문자열 관련 함수(strlen, strcmp, strcpy_s, strcat_s)
#strlen
문자열의 길이를 반환하는 함수
#include <string.h>
size_t strlen(const char* s);
순수 문자열의 길이를 반환한다.(null문자 제외)

size_t는 일반적으로
typedef unsigend int size_t 로 선언되어 있다.
따라서,
size_t == unsigned int
가 가능하다.

ex)
char str[] = "1234567";
printf("%u \n", strlen(str));  문자열의 길이 7이 출력된다.
함수의 반환 값이 unsigned int 이므로 서식문자 %u 사용이 적합하다.

하지만 문자열이 아무리 길어도 길이정보는 int형 변수에 저장이 가능하기 때문에,
strlen 함수의 반환 값을 int형 변수에 저장하고 서식문자 %d로 출력하는 게 더 흔하다.

strlen(str)
#include <string.h>
char* resp;
printf("2개의 과일 입력: ");
scanf("%s%s", str1, str2");
	if (strlen(str1) > strlen(str2))
		resp = str1;
	else
		resp = str2;
printf("%s", resp);

sizeof 와 strlen의 차이
sizeof 연산자는 배열 전체의 크기,
strlen은 순수 문자열 길이

#strcpy
문자열을 복사하는 함수
#include <string.h>
char* strcpy(char* dest, const char* src);
char str1[30] = "Simple String";
char str2[30];
strcpy(str2, str1);
문자열이 복사될 배열의 길이가 문자열의 길이보다 적지 않도록 주의해야 한다.
strcpy(str2, str1, sizeof(str2);
str1에 저장된 문자열을 str2에 복사하되, str1의 길이가 매우 길다면,
sizeof(str2)가 반환한 값에 해당하는 문자의 수 만큼만 복사를 진행하라.
strcpy(str3, str1, sizeof(str3) - 1);
str3(sizeof(str3) - 1) = 0;
세 번째 인자로 배열의 실제길이보다 하나 작은 값을 전달해서 널 문자가 삽입될 공간을 남겨두고 복사를
진행해햐 한다.그리고 이어서 배열의 끝에 널 문자를 삽입해야 한다.

strcpy(복사 받을 곳, 복사할 내용)
strcpy(str1, str2)
strcpy 함수는 char 배열에 문자열을 복사하는 대입 연산 기능을 수행한다.
#include <string.h>
char str1[80] = "strawberry";
char* ps1 = "banana";
printf("%s \n, str1");
strcpy(str1, ps1);
printf("%s \n, str1");
->strawberry
->banana

문자열 복사는 첫 번째 문자부터 널 문자가 나올 때 까지 문자를 하나씩 옮겨 배열에 저장한다.
첫 번째 인수는 char 배열이나 배열명을 저장한 포인터만 사용 가능
두 번째 인수는 문자열 시작 위치를 알면 어떤 거든 사용 가능

#strncpy
원하는 개수의 문자만 복사
strncpy(str, "apple-pie", 5);
배열명 복사할문자열 복사할 문자 수

#strcat
문자열을 덧붙이는 함수
#include <string.h>
char* strcat(char* dest, const char* src);

char str1[30] = "First";
char str2[30] = "Second";
strcat(str1, str2)
-> "First Second"

strcatr(str1, str2, 3)
-> "First Sec"
str2의 문자열 중 최대 3개를 str1의 뒤에 덧붙여라!

strcat 함수는 메모리 영역을 침범한다.
->배열의 크기 확인 필요
strcat 함수 사용할 때는 배열을 초기화해야함
#strcmp
문자열을 비교하는 함수
#include <string.h>
int strcmp(const char* s1, const char* s2)
두 문자열의 내용이 같으면 0, 같지 않으면 1을 반환

char str1[20];
char str2[20];
printf("문자열 입력 1: ");
scanf("%s", str1);
printf("문자열 입력 2: ");
scanf("%s", str2);

if (!strcmp(str1, str2))->사전편찬 순서를 기준으로 앞에 위치한 문자열이 작은 문자열이다.
{                                      s1이 사전편찬 순서상 뒤에 위치하면 0보다 큰 값 반환
puts("두 문자열은 동일합니다.");
}
else
{
	puts("두 문자열은 다릅니다.");

	if (!strcmp(str1, str2, 3))
		puts("하지만 앞 세 글자는 동일합니다.");
}

@그 이외의 변환 함수들
int atoi(const char* str)->문자열의 내용을 int형으로 변환

strcmp(str1, str2);
str1이 str2보다 사전에 나중에 나오면 1 반환
str1이 str2보다 사전에 먼저 나오면 - 1 반환
str1과 str2가 같은 문자열이면        0 반환
char str1[80] = "pear", char str2[80] = "peach";
if (strcmp(str1, str2) > 0)
printf("%s\n", str1);

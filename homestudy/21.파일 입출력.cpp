@파일과 스트림, 기본적인 파일의 입출력

파일은 운영체제에 의해서 관리가 되기 때문에, 운영체제와 파일의 관계에 대해 먼저 알아야 한다.

@프로그램상에서 파일에 저장된 데이터를 참조(읽기)를 원한다면 ?
스트림(stream)이라는 가상의 다리를 놓아야 한다.
프로그램과 파일 사이에 스트림을 형성해야 데이터를 주고 받을 수 있다.

하지만, 스트림은 운영체제에 의해서 형성되는 소프트웨어적인 상태를 의미하는 것일 뿐이기 때문에,
"파일로부터 데이터를 읽어 들일(파일에 데이터를 쓸)기본적인 준비가 완료되었다" 라고 생각해라.

@운영체제의 역할
1.파일의 구조를 결정하고 관리한다.
2.스트림의 형성을 담당한다.

#fopen
스트림을 형성할 때 호출하는 함수이다.
이 함수의 호출을 통해 프로그램상에서 파일과의 스트림을 형성할 수 있다.
#include <stdio.h>
FILE* fopen(const char* filename, const char* mode);
1번 인자 - 스트림을 형성할 파일의 이름
2번 인자 - 형성할 스트림의 종류에 대한 정보를 문자열의 형태로 전달
fopen 함수는 해당 파일의 스트림을 형성하고 스트림 정보를 FILE 구조체 변수에 담아 그 변수의 주소 값을 반환한다.

fopen의 반환형은 FILE 구조체이다.
하지만 FILE 구조체 변수의 멤버에 직접 접근 할 일이 없기 때문에, 어떻게 정의되었는 가 알 필요 없다.
위 함수가 반환하는 FILE 구조체 포인터는 파일을 가르키기 위한 용도로 사용된다.

이 포인터를 이용해 파일에 데이터를 저장하거나 파일에 저장된 데이터를 읽게 된다.

fopen 함수를 불러들이면 일어나는 3가지
1.fopen 함수가 호출되면 FILE 구조체 변수가 생성된다.
2.생성된 FILE 구조체 변수에는 파일에 대한 정보가 담긴다.
3.FILE 구조체의 포인터는 사실상 파일을 가리키는 '지시자'의 역할을 한다.

@입력 스트림과 출력 스트림의 생성
FILE* fp = fopen("data.txt", "wt"); ->출력 스트림 생성
"파일 data.txt와 스트림을 형성하되 wt모드로 스트림을 형성해라."
wt모드의 스트림 == 텍스트 데이터를 쓰기 위한 출력 스트림

출력 스트림은 파일에 데이터를 쓸 수는 있어도, 읽지는 못한다.

FILE* fp = fopen("data.txt", "rt");->입력 스트림 생성
"파일 data.txt와 스트림을 형성하되 rt모드로 스트림을 형성해라."
rt모드의 스트림 = 텍스트 데이터를 읽기 위한 입력 스트림

fopen 함수의 호출을 통해 파일과의 스트림이 형성되면, '파일이 개방(오픈)되었다'라고 표현한다.

@파일에 데이터 쓰기
fputc('A', fp);

FILE* fp = fopen("data.txt", "Wt");
if (fp == NULL) {
	puts("파일오픈 실패!");
	return -1; -> 비정상적 종료를 의미하기 위해 -1 반환
}
fputc("A", fp);
fputc("B", fp);
fputc("C", fp);
fclose(fp); ->스트림 종료
fclose 함수가 호출되면 데이터가 저장되고, 출력 스트림은 소멸된다.

출력 스트림을 형성하면 해당 파일이 생성된다.
실행 방법에 따라, 실행 환경 및 설정에 따라 파일 생성 위치가 달라진다.

FILE* fp = fopen("C:\\project\\data.txt", "wt");->이렇게 저장하면 해당 경로에 파일이 생성된다.

#fclose
스트림의 소멸을 요청하는 함수
#include <stdio.h>
int fclose(FILE* stream);

개방되었던 파일을 닫아줘야 하는 이유 ?
1.운영체제가 할당한 자원의 반환
2.버퍼링 되었던 데이터의 출력

@fflush 함수
스트림을 종료하지 않고 버퍼만 비우고 싶을 때 호출한다.
#include <stdio.h>
int fflush(FILE* stream);

입출력 버퍼를 비운다는 것은 ?
-출력버퍼를 비우면 출력버퍼에 저장된 데이터를 목적지로 전송한다는 의미
- 입력버퍼를 비우면 입력버퍼에 저장된 데이터를 소멸시킨다는 의미
- fflush 함수는 출력버퍼를 비우는 함수이다, 입력버퍼를 대상으로 호출 불가

파일에 저장된 데이터는 원할 때 언제든 읽을 수 있고, 읽혀진 데이터는 입력버퍼에서 지워진다.
따라서 입력버퍼를 비우는 함수는 필요없다.

@파일로 데이터 읽기
int ch, i;
FILE* fp = fopen("data.txt", "rt");
if (fp == NULL) {
	puts("파일오픈 실패");
	return -1;

	for (i = 0; i < 3; i++) {
		ch = fgetc(fp);
		printf("%c \n", ch);}
	fclose(fp);
}

@파일의 개방 모드(mode)
스트림을 구분하는 기준
1.읽기 위한 스트림 or 쓰기 위한 스트림
2.텍스트 데이터를 위한 스트림 or 바이너리 데이터를 위한 스트림

@읽기 위한 스트림 or 쓰기 위한 스트림
데이터의 이동방향을 기준으로 4가지 구분
- 데이터 READ 스트림 - 읽기만 가능
- 데이터 WRITE 스트림 - 쓰기만 가능
- 데이터 APPEND 스트림 - 쓰되 덧붙여 쓰기만 가능
- 데이터 READ / WRITE 스트림 - 읽기, 쓰기 모두 가능

MODE               스트림의 성격				파일이 없으면
r					읽기 가능						에러
w					쓰기 가능						생성
a					파일 끝에 덧붙여 쓰기 가능      생성
r + 읽기 / 쓰기 가능					에러
w + 읽기 / 쓰기 가능					생성
a + 읽기 / 덧붙여 쓰기 가능			생성

모드의 + 는 읽기, 쓰기 모두 가능한 스트림의 형성을 의미
모드의 a는 쓰기가 가능한 스트림을 형성, 단 덧붙이기만 가능

r + , w + , a + 는 읽기와 쓰기가 모두 가능하지만, 읽기에서 쓰기, 쓰기에서 읽기로 작업할 때마다
메모리 버퍼를 비워줘야 하기 때문에 "r, w, a"중 하나를 선택해 사용하는 것이 일반적인 선택이다.

@텍스트 파일과 바이너리 파일
#text file
사람이 인식할 수 있는 문자를 담고 있는 파일
ex)개인이 소유하는 독서의 목록, 슈퍼마켓의 물품 가격

#binary file
컴퓨터가 인식할 수 있는 데이터를 담고 있는 파일
ex)영화 타이타닉의 영상파일, 소녀시대의 히트곡 음원파일

데이터의 입출력을 위해 스트림 형성할 땐, '문장의 끝을 의미하는 개행의 표현방식만 신경쓰면 된다.'

@\n는 개행이 아니다 ?
개행은 줄이 바뀌었다는 현상이지 그 자체가 하나의 데이터로 존재하는 대상은 아니다.
"오직 C언어 에서만 개행을 \n으로 표시한다."
MS = DOS(Windows)의 파일 내 개행  \r\n
MAC(Mackintosh)의 파일 내 개행  \r
Unix 계열의파일 내 개행         \n

파일을 텍스트 모드로 개방하면 다른 운영체제일 지라도, 개행 정보를 형 변환해서 파일에 저장해준다.

@스트림을 구분하는 기준2 텍스트모드, 바이너리 모드
텍스트 모드
개행을 자동으로 형 변환해준다.
텍스트 모드의 파일 개방을 위해선 fopen의 두 번째 인자로 다음 중 하나를 전달해야 한다.
rt, wt, at, r + t, w + t, a + t

바이너리 모드
형 변환이 일어나면 안될 때 사용한다.
텍스트 모드의 파일 개방을 위해선 fopen의 두 번째 인자로 다음 중 하나를 전달해야 한다.
rb, wb, ab, r + b, w + b, a + b

w + t == wt +
w + b == wb +

@파일 입출력 함수의 기본
wrtie.c
FILE* fp = fopen("Simple.txt", "wt");
if (fp = NULL) {
	puts("파일 오픈 실패!");
	return -1;
}

fputc('A', fp);
fputc("My Name is Paul \n", fp);
fclose(fp);

Read.c
char str[30];
int ch;
FILE* fp = fopen("Simple.txt", "rt");
if (fp == NULL) {
	puts("파일오픈 실패!");
	return -1;
}
ch = fgetc(fp);
printf("%c \n", ch);

fgets(str, sizeof(str), fp);
printf("%s", str);;

fclose(fp);

문자열의 끝에는 \n 이 존재한다.
파일에서는 개행을 기준으로 문자열을 구분한다.
fgets 함수의 호출을 통해 읽어 들일 문자열의 끝에는 반드시
\n 문자가 존재해야 한다.

@feof 함수 기반의 파일 복사 프로그램
파일의 끝을 확인하는 목적으로 정의된 함수

#include <stdio.h>
int feof(FILE* stream);->파일의 끝에 도달한 경우 0이 아닌 값 반환

FILE* src = fopen("src.txt", "rt");
FILE* des = fopen("dst.txt", "wt");
int ch;

if (src == NULL || des == NULL) {
	puts("파일오픈 실패!");
	return -1;
}

while ((ch = fgetc(src)) != EOF)
fputc(ch, des);

if (feof(src) != 0)
puts("파일복사 완료!");
else
puts("파일복사 실패!");

fclose(src);
fclose(des);

src의 내용을 dst라는 이름의 파일을 생성해서 복사하기 위해,
src를 읽기모드, dst를 쓰기 모드로 개방하고 있다.

@바이너리 데이터의 입출력 : fread, fwrite
#fread
바이너리 데이터의 입력 함수
#include <stdio.h>
size_t fread(void* buffer, size_t size, size_t count, FILE* stream);

int buf[12];
fread((void*)buf, sizeof(int), 12, fp); fp는 FILE의 구조체 포인터
sizeof(int)크기의 데이터 12개를 fp로부터 읽어들여서 배열 buf에 저장하라!
함수의 호출이 성공했지만 파일에 끝에 도달해서 12개를 모두 읽어 들이지 못했거나,
오류가 발생하는 경우 12보다 작은 값이 반환된다.

#fwrite
바이너리 데이터의 출력 함수
#include <stdio.h>
size_t fwrite(const void* buffer, const size_t size, const size_t count, const FILE* stream);

int buf[7] = { 1,2,3,4,5,6,7 };
fwrite((void*)buf, sizeof(int), 7, fp);
sizeof(int)크기의 데이터 7개를 buf로 읽어서 fp에 저장하라!

FILE* src = fopen("src.bin", "rb");
FILE* des = fopen("dst.bin", "wb");
char buf[20];
int readCnt;

if (src == NULL || des == NULL) {
	puts("파일 오픈 실패!");
	return -1;
}

while (1) {
	readCnt = fread((void*)buf, 1, sizeof(buf), src);

	if (readCnt < sizeof(buf)) {
		if (feof(src) != 0) {
			fwrite((void*)buf, 1, readCnt, des);
			puts("파일복사 완료");
			break;
		}
		else
			puts("파일복사 실패");
	}
	fwrite((void*)buf, 1, sizeof(buf), des);
}

fclose(scr);
fclose(des);

fread 함수의 두 번째 전달인자 1, 세번째 인자가 sizeof(buf)이니
읽어 들이는 데이터의 크기는 총 1xsizeof(buf)바이트가 된다.
if문은 fread 함수가 sizeof(buf)의 반환 값보다 작은 값을 반환할 때 '참'이 된다.
이는 오류가 발생했거나, 파일의 끝에 도달한 것이니 feof 함수의 호출을 통해 무슨 상황인지 판단해야 한다.
if 안의 if문은
파일의 끝에 도착해서 sizeof(buf)의 반환 값보다 적은 수의 바이트가 읽혀졌을 때 실행되는 영역이다.
적은 수의 바이트가 읽혀졌어도 이 역시 파일의 일부이므로 fwrite 함수 호출을 통해 복사해야한다.

음원이나 이미지 같은 바이너리 데이터의 복사를 해봐라.
복사 프로그램의 성격
- READ / WRITE를 동시에 진행해야 한다.
- 파일의 끝에 도달했는지 확인 해야 한다.

이 두 가지는 파일 입출력의 가장 중요한 부분이기 때문이다.

@텍스트 데이터와 바이너리 데이터를 동시에 입출력하기
@서식에 따른 데이터 입출력 : fprintf, fscanf
char name[10] = "홍길동";->텍스트 데이터
char sex = "M";->텍스트 데이터
int age = 24;->바이너리 데이터
fprintf(fp, "%s %c %d", name, sex, age)->fp는 FILE의 구조체 포인터

fprintf는 FILE의 구조체 포인터가 첫 번째 전달 인자이다.
그리고 첫 번째 인자로 전달된 FILE 구조체의 포인터가 지칭하는 파일로 출력이 이뤄진다.

char name[10];
char sex;
int age;

FILE* fp = fopen("friend.txt", "wt");
int i;

for (i = 0; i < 3; i++) {
	printf("이름 성별 나이 순 입력: ");
	scanf("%s %c %d", name, &sex, &age);
	getchar();->버퍼에 남아있는 \n을 소멸하기 위해
	fprintf(fp, "%s %c %d", name, sex, age);
}
fclose(fp)

#fscanf
char name[10];
char sex;
int age;
fscanf(fp, "%s %c %d", name, &sex, &age);

char name[10];
char sex;
int age;

FILE* fp = fopen("friend.txt", "rt");
int ret;

while (1) {
	ret = fscanf(fp, "%s %c %d", name, sex, age);
	if (ret == EOF)
		break;
	printf("%s %c %d \n", name, sex, age);
}
fclose(fp);

@텍스트와 바이너리 데이터의 집합체인 구조체 변수의 입출력
typedef struct fren {
	char name[10];
	char sex;
	int age
}Friend;

구조체 변수를 하나의 바이너리 데이터로 인식하고 처리가 가능하다.
typedef struct fren {
	char name[10];
	char sex;
	int age
}Friend;

int main()
{
	FILE* fp;
	Friend myfren1;
	Friend myfren2;

	//file write
	fp = fopen("friend.bin", "wb");
	printf("이름, 성별 나이 순 입력 ");
	scanf("%s %c %d", myfren1.name, &(myfren1.sex), &(myfren1).age);
	fwrite((void*)&myfren1, sizeof(myfren1), 1, fp);
	fclose(fp);

	//file read
	fp = fopen("friend.bin", "rb");
	fread((void*)&myfren2, sizeof(myfren2), 1, fp);
	printf("%s %c %d \n", myfren2.name, myfren2.sex, myfren2.age);
	fclose(fp);
}
@임의 접근을 위한 '파일 위치 지시자'의 이동
경우에 따라 파일의 중간 또는 마지막 부분에 저장된 데이터를 읽어야 할 경우,
'파일 위치 지시자'를 파일의 중간 혹은 마지막 부분으로 이동시켜야 한다.

@파일 위치 지시자
FILE 구조체의 멤버 중에 파일의 위치 정보를 저장하는 멤버가 있다.
이 멤버의 값은 fgets, fputs, fread, fwrite 함수가 호출될 때마다 참조 및 갱신된다.
이 멤버에 저장된 위치 정보의 갱신을 통해 데이터를 읽고 쓸 위치 정보가 유지된다.
따라서 이를 '파일 위치 지시자'라고 부른다.

파일이 처음 개방되면 무조건 파일의 맨 앞을 가리킨다.
따라서, 파일의 중간 혹은 마지막 부분에서 데이터를 읽거나 쓰기를 원하면 '파일위치지시자'를 옮겨야 함

@파일 위치 지시자의 이동 : fseek
파일위치 지시자를 이동시키고자 할때 호출하는 함수
#include <stdio.h>
int fseek(FILE* stream, long offset, int wherefrom);
stream으로 전달된 파일 위치 지시자를 wherefrom에서부터 offset 바이트만큼 이동시켜라.

매개변수 wherefrom이                  파일 위치 지시자는
SEEK_SET(0)이라면                     파일 맨 앞에서부터 이동을 시작
SEEK_SET(1)이라면                     현재 위치에서부터 이동을 시작
SEEK_SET(2)이라면                     파일 맨 끝에서부터 이동을 시작

매개변수 offset에는 음의 정수도 전달 가능하다.
양의 정수가 전달되면 파일의 마지막을 향해 파일 위치 지시자가 이동.
음의 정수는 그 반대

SEEK_SET 전달 시 처 번째 바이트에서부터 이동을 시작한다.
SEEK_END 전달 시 EOF에서부터 이동을 시작한다.
fseek 함수의 두 번째 인자로 음수가 전달되면 앞쪽(왼쪽)으로 이동한다.

일반적으로 SEEK_END가 전달되면 파일의 끝에서부터 이동이 시작된다.
여기서 말하는 파일의 끝은 파일의 마지막 데이터가 아닌 EOF를 의미한다.

//파일 생성
FILE* fp = fopen("text.txt", "wt");
fputs("123456789", fp);
fclose(fp);

//파일 개방
fp = fopen("text.txt", "rt");

//SEEK_END 
fseek(fp, -2, SEEK_END);
putchar(fgetc(fp));

//SEEK_SET
fseek(fp, 2, SEEK_SET);
putchar(fgetc(fp));

//SEEK_CUR 
fseek(fp, 2, SEEK_CUR);
putchar(fgetc(fp));

fclose(fp);

#ftell
현재 파일 위치 지시자의 정보를 확인하는 함수
#include <stdio.h>
long ftell(FILE* stream);
파일 위치 지시자의 위치 정보를 반환한다.
파일 위치 지시자가 첫 번째 바이트를 가리킬 경우 0을 반환, 세 번째 바이트를 가리킬 경우 2를 반환

long fpos;
int i;

//파일 생성
FILE* fp = fopen("text.txt", "wt");
fputs("1234-", fp);
fclose(fp);

//파일 개방
fp = fopen("text.txt", "rt");

for (i = 0; i < 4l i++) {
	putchar(fgetc(fp));
	fpos = ftell(fp);
	fseek(fp, -1, SEEK_END);
	putchar(fgetc(fp));
	fseek(fp, fpos, SEEK_SET);
}
fclose(fp);
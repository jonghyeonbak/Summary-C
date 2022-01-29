2차원 배열이름의 포인터형
int arr2d[3][3];
cout << arr2d;		 4585464
cout << arr2d[0];	 4585464
cout << arr2d[0][0]; 4585464

cout << arr2d[1];	 4585476
cout << arr2d[1][0]; 4585476

cout << arr2d[2];    4585488
cout << arr2d[2][0]; 4585464

cout << sizeof(arr2d);    36
cout << sizeof(arr2d[0]); 12
cout << sizeof(arr2d[1]); 12
cout << sizeof(arr2d[2]); 12

2차원 배열의 이름은 더블 포인터형이 아니다!!!!

arr2d는 첫 번째 요소를 가르키면서 배열 전체를 의미한다.
arr2d[0]은 첫 번째 요소를 가르키되 1행만을 의미한다.
그래서 sizeof 연산의 결과가 다르다.

@배열 이름 기반의 포인터 연산
int iarr[3];
double darr[7];
printf("%p", iarr + 1);      +4
printf("%p", darr + 1);      +8
배열이름 iarr은 int형 포인터이므로 iarr + sizeof(int)의 계산 결과 출력

int iarr1[3][2];
int iarr2[3][2];
printf("%p", iarr1 + 1);
-> &iarr1[1][0]
2차원 배열을 대상으로 증감연산을 할 경우, 연산결과는 각 행의 첫 번째 요소의 주소 값이 된다.

@2차원 배열이름의 포인터 형
1.가르키는 대상은 무엇인가 ?
2.배열이름(포인터)를 대상으로 값을 1 증가 및 감소 시 실제로는 얼마가 증가 및 감소하는가 ?
ex) int arr[3][4];
"arr은 가르키는 대상이 int형 변수이고,"
"포인터 연산 시 sizeof(int)*4의 크기 단위로 값이 증감하는 포인터 형이다."

int(*ptr)[4];
ptr은 포인터,
int형 변수를 가르키는 포인터이며, 포인터 연산 시 4칸씩 건너 뛰는 포인터를 뜻한다.

@2차원 배열의 포인터 형을 결정짓는 연습
char(*arr1)[4];
double(*arr2)[7];
== == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==

@2차원 배열 이름의 특성과 주의사항
'배열 포인터'와 '포인터 배열' 혼동 금지
int* whoA[4];  포인터 배열
int(*whoB)[4]; 배열 포인터

whoA는 포인터 선언이고,
whoB는 포인터 변수의 선언이다.
whoA는 int 형 포인터 변수로 이뤄진 ing형 포인터 배열이고,
whoB는 가로길이가 4인 int형 2차원 배열을 가르키는 용도의 포인터 변수이다.

int num1 = 10, num2 = 20, num3 = 30, num4 = 40;
int arr2d[2][4] = { 1,2,3,4,5,6,7,8 };
int i, j;
int* whoA[4] = { &num1, &num2, &num3, &num4 }; ->포인터 배열
int(*whoB)[4] = arr2d; ->배열 포인터
cout << *whoA[0] << *whoA[1] << *whoA[2] << *whoA[3];
for (i = 0; i < 2; i++)
{
	for (j = 0; j < 4; j++)
		cout << (*whoB)[i][j];
	cout << "\n";
}

@2차 배열을 함수의 인자로 전달
int arr1[2][7];
double arr2[4][5];
simplefunc(arr1, arr2);

int(*parr1)[7];
double(*parr2)[5];

void simplefunc(int(*parr1)[7], double(*parr2)[5]){...}
void simplefunc(int parr1[][7], double parr2[][5]){ ... }

int(*parr1)[7]
int parr1[][7]

double(*parr2)[5]
double parr2[][5]
둘은 같다

@2차원 배열 또한 arr[i] == *(arr + i)
int arr[3][2] = { {1,2},{3,4},{5,6} };
arr[2][1] = 4;
(*(arr + 2))[1] = 4;
*(arr[2] + 1) = 4;
*(*(arr + 2) + 1) = 4;

for (i = 0; i < 3; i++) {
	for (j = 0; j < 4; j++) {
		printf("5d", pa[i][j]);
	}
	printf("\n");
}
-포인터도 주소가 있다
- 이중 포인터에 *를 사용하면 싱글 포인터가 된다.
- 2차원 배열의 배열명은 첫 번째 부분 배열의 주소가 된다.
- 배열 포인터에 간접 참조 연산자를 사용하면 가리키는 배열이 된다.

이중 포인터		배열 포인터
int** p;		int(*pa)[4];

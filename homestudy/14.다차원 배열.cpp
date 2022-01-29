@다차월 배열의 이해와 활용
int arrOneDim[10]; 길이가 10인 1차원 int형 배열
int arrTwoDim[3][5]; 세로가 3 가로가 5인 2차원 배열
int arrThreeDim[4][1][3]; 높이가 4, 세로가 1, 가로가 3인 3차원 배열

arr[N - 1][M - 1] = 20; 세로 N, 가로 N의 위치에 정수 20을 저장
printf("%d", arr[N - 1][m - 1]); 세로 N, 가로M의 위치에 저장된 값 출력

@2차원 배열
int arr1[3][4];   세로가 3, 가로가 4인 int형 2차원 배열

type arr[세로길이][가로길이]
위가 표준이다.

@2차원 배열의 메모리상 할당의 형태
우리가 사용하는 메모리의 주소 값은 1차원적 구조이다.
2차원 배열도 마찬가지 이다.

@2차원 배열 선언과 동시에 초기화
int arr1[3][4] = {        
	{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12}
};
ex) int arr[0][1] = 1 ? -> 2가  1로 바뀐다.
ex) int arr[2][1] = 2 ? -> 10이 2로 바뀐다.

int arr[3][2];
int i, j;
for(i = 0; i < 3; i++)
{
	for (j = 0; j < 2; j++)
		printf("%d \n" arr[i[j]);
}
주소 값은 int형 변수의 크기인 4바이트만큼 증가한다.

@배열의 크기를 알려주지 않고 초기화
int arr[][] = { 1,2,3,4,5,6,7,8 };   이건 컴파일러가 해결하지 못한다.
int arr1[][4] = { 1,2,3,4,5,6,7,8 }; "배열의 세로길이만 생략 가능"하다.

== == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == =
@3차원 배열
흔히 사용되진 않는다.
int arr1[2][3][4]  높이 2. 세로3, 가로 4인 int형 3차원 배열
ex)
for (i = 0; i < 3; i++)
	for (j = 0; j < 2; j++)
		mean += record[0][i][j];
printf("something");
mean = 0;
for (i = 0; i < 3; i++)
	for (j = 0; j < 2; j++)
		mean += record[1][i][j];
printf("something");
mean = 0;
for (i = 0; i < 3; i++)
	for (j = 0; j < 2; j++)
		mean += record[2][i][j];
printf("something");
3차원 배열은 여러 개의 2차원 배열이 모여있는 형태로 이해하는 것이 합리적이다.

71.2차 배열은 행렬의 구조와 같다.
int score[3][4] = { { 1,2,3,4, },{ 5,6,7,8 },{ 9,10,11,12 } };
세로 가로

- 세로(행)는 생략 가능
- 2차원 배열은 1차원 배열의 요소로 되어있다.
72.2차원 char 배열
char animal[5][20];
초기화
char animal[5][10] = { "dog", "tiger", "rabbit","horse", "duck" };
3차원 배열 int score[2][3][4]
높이 세로 가로
- 2차원 배열은 주로 2중 for문을 사용한다.

73. 포인터 배열
int *pary[3];
for (int i = 0; i < 5; i++) {
	printf("%s\n", pary[i]);
}
초기화
char* pary[5] = { "dog", "elephant", "horse", "tiger", "lion" };
2차원 char 배열의 초기화
char animal[5][20] = { "dog", "elephant", "horse", "tiger", "lion" };

74.2차원 배열처럼 활용하는 포인터 배열
int arr1[4] = { 1,2,3,4 };
int arr2[4] = { 5,6,7,8 };
int arr3[4] = { 9,10,11,12 };
int* parr[3] = { arr1, arr2, arr3 };
int i, j;
for (i = 0; i < 3; i++) {
	for (j = 0; j < 4; j++)
	{
		printf("%5d", parr[i][j]);
	}
	prinf("\n");
}

pary[2][2] == *(pary[2] + 2);
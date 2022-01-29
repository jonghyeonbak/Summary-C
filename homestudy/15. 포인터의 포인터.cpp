@이중 포인터
int** dptr;
**num->이중 포인터 변수
*num->싱글 포인터 변수

double num = 3.14;
double* ptr = &num;
double** dptr = &ptr;

*dptr = ...;	    -> *dptr은 포인터 변수 prt을 의미
*(*dptr) = .....;   -> *(*dptr)은 변수 num을 의미

SwapIntPtr(int** dp1, int** dp2)
int* temp = *dp1;
*dp1 = *dp2;
*dp2 = temp;

int num1 = 10, num2 = 20;
int* ptr1 = &num1;
int* ptr2 = &num2;
cout << *ptr1 << *ptr2 << endl;
SwapIntPtr(&ptr1, &ptr2)
cout << *ptr1 << *ptr2 << endl;
return 0;

-> 10, 20
20, 10

@이중 포인터 배열
int num1 = 10, num2 = 20, num3 = 30;
int* ptr1 = &num1;
int* ptr2 = &num2;
int* ptr3 = &num3;

int* ptrArr[] = { ptr1, ptr2, ptr3 };
int** dptr = ptrArr;

cout << *(ptrArr[0]) << *(ptrArr[1]) << *(ptrArr[2]) << endl;
cout << *(dptr(0)) << *(dptr(1)) << *(dptr(2)) << endl;

@삼중 포인터
삼중 포인터는 이중 포인터를 가르키는 변수이다.

@포인터의 필요성은 어디서 찾아야 하나 ?
자료구조를 공부하면 포인터의 필요성을 보다 확실하게 느끼고 알 수 있다.

자료구조는 데이터의 효율적인 표현 및 저장방법을 공부하는 학문이다.

int a = 10;
int* pi;
int** ppi;
첫 번째 별은 가르키는 변수의 자료형, 두 번째 별은 자신의 자료형을 의미
pi = &a;
ppi = &pi;

double a = 3.5;
double* pi = &a;
double** ppi;
pi -> (double*)형 변수
&pi -> (double*)형의 주소

포인터 == 변수이므로 주소 연산자 사용해서 주소를 구할 수 있음
주소 == 상수이므로 주소 연산자 x
int a; int* pi = &a;
&pi; ->oo, &(&a)->xx
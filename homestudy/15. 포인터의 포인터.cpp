@���� ������
int** dptr;
**num->���� ������ ����
*num->�̱� ������ ����

double num = 3.14;
double* ptr = &num;
double** dptr = &ptr;

*dptr = ...;	    -> *dptr�� ������ ���� prt�� �ǹ�
*(*dptr) = .....;   -> *(*dptr)�� ���� num�� �ǹ�

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

@���� ������ �迭
int num1 = 10, num2 = 20, num3 = 30;
int* ptr1 = &num1;
int* ptr2 = &num2;
int* ptr3 = &num3;

int* ptrArr[] = { ptr1, ptr2, ptr3 };
int** dptr = ptrArr;

cout << *(ptrArr[0]) << *(ptrArr[1]) << *(ptrArr[2]) << endl;
cout << *(dptr(0)) << *(dptr(1)) << *(dptr(2)) << endl;

@���� ������
���� �����ʹ� ���� �����͸� ����Ű�� �����̴�.

@�������� �ʿ伺�� ��� ã�ƾ� �ϳ� ?
�ڷᱸ���� �����ϸ� �������� �ʿ伺�� ���� Ȯ���ϰ� ������ �� �� �ִ�.

�ڷᱸ���� �������� ȿ������ ǥ�� �� �������� �����ϴ� �й��̴�.

int a = 10;
int* pi;
int** ppi;
ù ��° ���� ����Ű�� ������ �ڷ���, �� ��° ���� �ڽ��� �ڷ����� �ǹ�
pi = &a;
ppi = &pi;

double a = 3.5;
double* pi = &a;
double** ppi;
pi -> (double*)�� ����
&pi -> (double*)���� �ּ�

������ == �����̹Ƿ� �ּ� ������ ����ؼ� �ּҸ� ���� �� ����
�ּ� == ����̹Ƿ� �ּ� ������ x
int a; int* pi = &a;
&pi; ->oo, &(&a)->xx
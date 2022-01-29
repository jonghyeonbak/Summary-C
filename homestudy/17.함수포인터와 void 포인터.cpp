@�Լ� �������� ����
���α׷� ������ �帧�� �����ϴ� �Լ��鵵 ���̳ʸ� ���·� �޸� ������ ����Ǿ ȣ�� �� ����ȴ�.
�̷��� �޸𸮻� ����� �Լ��� �ּ� ���� �����ϴ� ������ ������ �ٷ� '�Լ� ������ ����'�̴�.

�迭�� �̸��� �迭�� �����ּ� ���� �ǹ��ϵ�,
�Լ��� �̸��� �Լ��� ����� �޸� ������ �ּ� ���� �ǹ��Ѵ�.

int SimpleFunc (int num){....}  -> �⺻ ����
��ȯ��		  int
�Ű����� ���� int num
�� ��Ȳ���� �Լ��� �̸� SimpleFunc�� 
SimpleFunc �Լ��� �ּ� ���� �ǹ��ϴ� ��������� �Լ� �������̴�.

�Լ��̸��� ������ ���� ��ȯ���� �Ű������� ������ ���ؼ� ���������� ��ӵǾ� �ִ�.
����, ��ȯ���� int�̰� �Ű������� int�� ���� �ϳ��� ����� ������ ��(type)�̴�.

@������ �Լ� ������ ������ ����
int (*fptr) (int) 
��ȯ���� int�̰�, �Ű����� ������ int �ϳ��� fptr�̸��� �Լ� ������

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

@��(type)�� �������� �ʴ� void ������
void* ptr;
void �����ʹ� �����̵� ���� �� �ִ� �ٱ��Ͽ� ������ �� �ִ�.
��� ������ �ּ� ��, �Լ��� �ּ� ���� ���� �� �ִ�.

void SoSimpleFunc(void)
{
	printf("I'm so simple");
}

int main()
{
	int num = 20;
	void* ptr;

	ptr = &num;
	prinrf("%p \n", ptr);   -> ���� num�� �ּ� �� ����

	ptr = SoSimpleFunc;
	printf("%p \n", ptr);   -> �Լ� SoSimpleFunc�� �ּ� �� ����
	return 0;
}

���Ը� ���� ���� ������,
void�� ������ ������ ��� ������ ���굵 ���� ���Ѵ�.
���� �����̳� �������� �Ұ����ϴ�. 

void�� ������ �������� ����Ű�� ��� ���� ��� ��(type)������ ������� �ʱ� �����̴�.
int main()
{
	int num = 20;
	void* ptr = &num;
	*ptr = 20;   -> ������ ����
	ptr++;		 ->������ ����
}
������ ���� �ϴ� �ּ� ������ �ǹ̸� �ΰ�, �������� ���� ���߿� �����Ѵ�.

@main �Լ����� ���� ����
int main(void){...} -> int main(int argc, char* argv[]){...} -> �̰͵� ����

@main�Լ��� ���� ������ ����
{
	int i = 0;
	printf("���޵� ���ڿ��� ��: %d \n", argc);

	for (i = 0; i < argc; i++)
		printf("%d��° ���ڿ�: %s \n", i + 1, argv[i]);
	return 0;
}
���α׷� ����������� �Է��� ������ ���α׷� ������ ���޵Ǿ ����� �̷�����.

@char* argv[]
void SimpleFunc(TYPE* arr) { .... }
void SimpleFunc(TYPE arr[]) { .... }

void SimpleFunc(char** arr) { .... }
void SimpleFunc(char* arr[]) { .... }

main�Լ��� �Ű����� argv�� char�� ���� ������ �����̰�,
�̴� char�� ������ ������ �̷��� 1���� �迭�� �̸��� ���޹��� �� �ִ� �Ű������̴�.

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
argv�� char�� ���� ������ �����̴�.
���� argv���� char** �� ������(�ּ� ��)�� ���޵� �� �ִ�.

�迭�̸� str�� ����Ű�� ù ��° ��Ұ� char* �� �������̹Ƿ�,
�迭�̸� str�� ���� char** �̴�.�׷��� �� �Լ��� �� ��° ���ڷ� ������ �����ϴ�.

@������ ��������
c : \ > ArgcArgv I like you
���ڿ�1 "ArgcArgv"
���ڿ�2 "I"
���ڿ�3 "like"
���ڿ�4 "you"
������ ���ڿ��� ������ �����̴�.
�� 4���� ���ڿ��� �ϳ��� �迭�� ������ main�Լ��� �� ��° ���ڷ� ������ �Ǹ�,
ù ��° ���ڷδ� ���ڿ��� ���� ���޵ȴ�.

strArr[0]	  ->"ArgcArgv\0"
strArr[1]	  ->"I\0"
strArr[2]     ->"like\0"
strArr[3]     ->"you\0"
strArr[4] null

char* strArr[5]; -> ������ ����
main(4, strArr) 
main�Լ��� �̷� ���·� ȣ��ȴ�.
	
int ary[3][4] = { { 1,2,3,4, },{ 5,6,7,8 },{ 9,10,11,12 } };
int(*pa)[4];
int i, j;
pa = ary;

�Լ����� �Լ� ���ǰ� �ִ� �޸��� ���� ��ġ��.
int(*fp)(int, int);
int res;

fp = sum;
res = fp(10, 20);
printf("result: %d\n", res);

int sum(int a, int b) {
	return a + b;
}
�Լ��� ���¸� ������ ��� �Լ��� ��� ����
78.void ������
����Ű�� �ڷ����� �������� ���� ������
void* vp;
� �ּҵ� ���� ���������� �����Ϳ��� �Ұ�

- �Լ� �����Ϳ� �Լ����� �����ϸ� �Լ�ó�� ȣ�� ����
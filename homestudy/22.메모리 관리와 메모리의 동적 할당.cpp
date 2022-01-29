@C����� �޸� ����
���α׷��� �����ϸ� �ش� ���α׷��� ������ ���� �޸� ������ �ü���� ���ؼ� �̸� ���õȴ�.
�׸��� �� �޸� ���� ������ ������ ����ǰ�, ���ڿ��� ����Ǵ� ���̴�.

@�޸��� ����
code  ����
data  ����
heap  ����
stack ����

@�޸� �������� ����Ǵ� ������ ����
#code area
������ ���α׷��� �ڵ尡 ����Ǵ� �޸� ����

#data area
���������� static������ �Ҵ�ȴ�.
���α׷� ������ �� �޸� ������ �Ҵ�, ����ñ��� �����ִ´�.

#stack area
���������� �Ű������� �Ҵ�ȴ�.
�Լ��� ���۵� �� �޸� ������ �Ҵ�, �Լ��� ���������� �Ҹ�

#heap area
����ڰ� ���� �� �Ҵ�, �Ҹ�

@���α׷��� ���࿡ ���� �޸��� ���� ��ȭ
���� ������ ��� ���� ���ø� �׾� �ø��� ����,
���������� ���ø� �ϳ��� ���� ���´ٰ� �����غ���.

���� �Ʒ��� ��ġ�� ���ð� �������� ������ ���̴�.

@�޸��� ���� �Ҵ�
#malloc �� free �Լ�
heap ������ �޸� ���� �Ҵ�� ����
#include <stdlib.h>
void* malloc(size_t size);->haep �������� �޸� ���� �Ҵ�
void free(void* ptr);->heap ������ �Ҵ�� �޸� ���� ����

ex)
void* ptr1 = malloc(4);  -> 4����Ʈ�� heap ������ �Ҵ�
void* ptr2 = malloc(12);  -> 4����Ʈ�� heap ������ �Ҵ�

free(ptr1); ptr1�� ����Ű�� 4����Ʈ �޸� ���� ����
free(ptr2); ptr2�� ����Ű�� 12����Ʈ �޸� ���� ����

@malloc �Լ��� ��ȯ���� void�� �������� ������ heap ���������� ����
malloc�Լ��� ��ȯ���� void�� �������̴�.
void* ptr = malloc(sizeof(int)); int�� ���� ũ���� �޸� ���� �Ҵ�
*ptr = 20->����

int* ptr1 = (int*)malloc(sizeof(int));
double* ptr2 = (double*)malloc(sizeof(double));
int* ptr3 = (int*)malloc(sizeof(int) * 7);
double* ptr4 = (double*)malloc(sizeof(double) * 9);

malloc �Լ��� �޸� ������ �Ҵ翡 ������ ��� null�� ��ȯ�Ѵ�.
�޸� �Ҵ��� �������θ� Ȯ���Ϸ��� ?
int* ptr = (int*)malloc(sizeof(int));
if (ptr == null)
{
	�޸� �Ҵ� ���п� ���� ���� ó��
}

malloc �Լ��� ȣ���� ���� �޸� ������ ������ '���� �Ҵ�(dynamic allocation)'�̶� �Ѵ�.
�Ҵ�Ǵ� �޸��� ũ�⸦ �����Ϸ��� �������� �ʰ�, ���α׷��� ���� �߰��� ȣ��Ǵ� malloc �Լ���
�����ϱ� �����̴�.

@free �Լ��� ȣ������ ������ ���α׷��� ���� �Ŀ��� �޸𸮰� ������?
���α׷��� ����Ǹ� �ü���� ���� �޸� ������ ���� �����ȴ�.
������ �޸� ���� ������� �����ϰ� malloc �Լ��� ȣ�� Ƚ����ŭ free�Լ��� ȣ�� �ϴ� �� �߿�!

@���ڿ��� ��ȯ�ϴ� �Լ��� �����ϴ� ������ �ذ�
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

@malloc �Լ��� ���� �� calloc �Լ�
#include <stdlib.h>
coid* calloc(size_t elt_count, size_t elt_size)
malloc �Լ����� ������ �������� �޸� ������ �Ҵ��� ���� ������ ���޹�Ŀ� �ִ�.

malloc �Լ��� ȣ����
"�� 120����Ʈ�� heap ������ �Ҵ� ���ּ���"

calloc �Լ��� ȣ����
"4 ����Ʈ ũ���� ���(elt_size)30����(elt_count) heap ������ �Ҵ����ּ���."

malloc�� calloc�� ������ ������ 2����
1.�����ڸ� �����ϴ� ���
2.malloc�� �ʱ�ȭ ���� ������->������ ��, calloc�� �ʱ�ȭ ���� ������ -> 0���� �ڵ� �ʱ�ȭ

@heap�� �Ҵ�� �޸� ���� Ȯ�� �� ȣ���ϴ� realloc �Լ�
#include <stdlib.h>
void* realloc(void* ptr, size_t size);

"ptr�� ����Ű�� �޸��� ũ�⸦ size ũ��� ��������(�÷���)"

int* arr = (int*)malloc(sizeof(int) * 3);   ->���̰� 3�� int�� �迭 �Ҵ�
arr = (int*)realloc(arr, sizeof(int) * 5);  ->���̰� 5�� int�� �迭�� Ȯ��

malloc �Լ��� ��ȯ�� �ּ� ���� realloc �Լ��� ��ȯ�� �ּ� ���� ���� ���
������ �Ҵ�� �޸� ������ �ڸ� �̾�, Ȯ���� ������ �˳��� ��쿡 �߻��Ѵ�.

malloc �Լ��� ��ȯ�� �ּ� ���� realloc �Լ��� ��ȯ�� �ּ� ���� ���� ���� ���
���� �ٸ� ��ġ��, 
������ �䱸�ϴ� ũ���� �޸� ������ ������ �Ҵ��ؼ� ���� �迭�� ����� ���� �����ϱ⵵ �Ѵ�.


##�޸� �����Ҵ�
79.malloc, free �Լ�
#include <stdlib.h>
void* malloc(unsigned int size);
void free(void* p);

�޸� ������ ���ϸ� �޸� ������ �߻� �� �� ����.

���� �Ҵ� �迭ó�� ����
pi = (int*)mallco(5 * sizeof(int));

calloc �Լ�
0���� �ʱ�ȭ ����
double* pd;
pd = (double*)calloc(5, sizeof(double));

recalloc �Լ�
�Լ��� ũ�⸦ ������
pi = (int*)recalloc(pi, 10 * sizeof(int));

80.�޸� ����
code area - ���� ������ ���� ����(�Լ�)
stack area - ���� ����
data area - ���� ������ ���� ����
heap - ���� �Ҵ�, ����� �� nullptr�� �ʱ�ȭ ���������

81.���� �Ҵ��� ����� ���ڿ� ó��
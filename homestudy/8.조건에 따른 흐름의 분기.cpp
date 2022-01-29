#8
조건에 따른 흐름의 분기
@흐름의 분기가 필요한 이유
프로그램의 흐름을 분기시킬 줄 알아야 선택적 실행이 가능해진다.

@if문을 이용한 조건적 실행
분기의 가장 기본은, 두 개의 키워드 if와 else로 구성이 되는 if~else문이다.
if는 독리적으로 사용되어 '조건적 실행'을 가능하게 한다.

if (num1>num2)   // num1이 num2보다 크다면 아래의 중괄호를 실행한다.
{
	printf("num1이 num2보다 큽니다. \n");
	printf("%d > %d \n", num1, num2);
}

어렵진 않지만, if문만 여러 개 나열하면 if문 모두가 실행되는 문제점이 있다.

@if~else문을 이용한 흐름의 분기
if (num1>num2)   // num1>num2이 '참'이면 아래의 중괄호를 실행한다.
{
	printf("num1이 num2보다 큽니다. \n");
	printf("%d > %d \n", num1, num2);
}

else (num1>num2)   // num1>num2이 '거짓'이면 아래의 중괄호를 실행한다.
{
	printf("num1이 num2보다 크지 않습니다. \n");
	printf("%d <= %d \n", num1, num2);
}

@if… else if... else의 구성
if (조건1)
{
	//조건 1 만족 시 실행
}
else if (조건2)
{
	//조건 2 만족 시 실행
}
else if (조건3)
{
	//조건 3 만족 시 실행
}
else
{
	//모두 불 만족 시 실행
}

+조건이 만족되어 해당 블록을 실행하고 나면, 마지막에 있는 else까지도 건너뛴다.
+ 조건의 만족여부는 검사의 위에서 아래로 진행된다.

@if…else if… else의 진실
if…else if…else는 if~else문을 중첩시키되 else 블록을 대상으로 중첩시킨 결과이다.
그래서 if문에 명시된 하나의 조건이 '참'이 되면, 나머지 전부를 건너뛰었던 것이다.

@조건 연산자 : 피 연산자가 세 개인 '삼 항 연산자'
(num1>num2) ? (num1) : (num2)

소괄호는 생략 가능하고, 조건 연산자는 기호 ? 와 기호 : 으로 이뤄진다.
피 연산자는 3개까지 둘 수 있다.

(조건) ? data1 : data2

위 문장에서 조건이 '참'이면 data1이 반환, '거짓'이면 data2 반환

@반복문의 생략과 탈출 : continue & break
@break;
반복문을 탈출할 때 사용하는 키워드이다.
break문을 가장 가까이서 감싸고 있는 반복문 하나를 빠져 나오게 된다.

+ break문이 if문과 함께 쓰였다고 해서 if문을 빠져 나오는 것으로 오해하면 안된다.

@continue;
나머지를 생략하고 반복조건을 확인하러 간다.

실행중인 위치에 상관없이 반복문의 조건검사 위치로 이동한다.
그리고 검사결과 반복조건이 여전히 '참'이라면 반복영역을 다시 실행하게 된다.

Q) break와 continue의 차이는 ?
break는 가장 가까운 조건문을 탈출!
continue는 반복문의 조건 검사로 이동!

@switch문에 의한 선택적 실행과 goto문
if~else문과 비슷하지만 그보다 제약적이다.

int num;
scanf("%d", &num);

switch (num)
{
case 1:
	printf("1은 one \n");
	break;
case 2:
	printf("2은 two \n");
	break;
case 3:
	printf("3은 three \n");
	break;
default:
	printf("I don't know! \n");
}

switch 안에 들어가는 n은 정수형 변수(char도 포함)여야 한다.
대표적으로는 int형 변수가 위치하는데, 이 n에 저장된 값에 따라서 실행할 영역이 결정된다.

ex)
n의 저장된 값 = 1, case1의 영역 실행

+ case문은 위치를 표시하는 데 사용되므로 '레이블(label)'이라 한다.
+ break가 없으면 다음 case로 넘어간다.
+ case 옆에는 ' : '를 붙여줘야 한다.

@break문을 생략한 형태의 switch문 구성
break문이 삽입되어서 유용한 경우도 있지만, 삽입되지 않아서 유용한 경우도 있다.

ex)
case 1:
case 2:
case 3:
	printf("메롱\n");
	break;
case 4:
	printf("안녕\n");
	break;
default:
	printf("잘못 눌렀다잉");

	@switch vs.if…else if…else
		분기의 경우 수가 많아지면 가급적 switch문을 구현한다.
		간결해 보이기 때문이다.

		@goto (가급적 사용x)
		프로그램의 흐름을 원하는 위치로 이동시킬 때 사용하는 키워드다.

		int main(void)
	{
		qwrjrwk
			one :                  // 위치지정에 사용된 one이라는 이름의 레이블
		qwrqrwqwr
			goto one;    // 레이블 one의 위치로 이동!


}
#include <iostream>
using namespace std;
enum Season {
	Spring,
	Summer,
	Fall,
	Winter
};

struct Person {
	int age = 10;
};

int age = 10;
int &func() {
	return age;
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	/*int age = 10;
	int &rAge = age;
	rAge = 30;
	cout << age << endl;*/

	// ö��
	/*Season season;
	Season &rSeason = season;
	rSeason = Fall;
	cout << season << endl;*/

	// �ṹ��
	//Person person;
	//Person &rPerson = person;
	//rPerson.age = 100;
	//cout << person.age << endl;

	// ָ��
	//int a = 10;
	//int b = 20;

	//int *p = &a;
	//int *&rP = p;
	////rP = &b;
	//cout << b << endl;
	//*p = 30;
	//cout << a << endl;
	//cout << b << endl;

	// ����
	/*int array[] = {10,20,30};
	int(&rArray)[3] = array;
	rArray[1] = 100;

	cout << rArray[1] << endl;*/

	// int *a[4];   ָ������
	// int (*b)[4]; ָ�������ָ�� 

	// ��������������Ƕ�������ָ��ı���������
	/*int a = 10;
	int &rA = a;
	rA += 20;
	cout << rA << endl;*/

	// �ڶ����ʱ������ʼ����һ��ָ���˾Ͳ��ܸ���
	//int a = 10;
	//int b = 20;
	//int &rA = a;
	//rA = b;      // a = b = 20
	//rA = 30;	 // a = 30

	//cout << a << endl; 
	//cout << b << endl;

	// ����������ȥ��ʼ����һ�����ã��൱��һ�������Ķ������
	/*int a = 10;
	int &rA = a;
	int &rB = rA;
	int &rC = rB;

	cout << rA << endl;
	cout << rB << endl;
	cout << rC << endl;
*/

// ���������
// ���õ�����
//int a = 10;
// int &&a = a;
// ָ�����õ�ָ��
//int &rA = a;
//int &*b = &rA;
// ��������
// int &array[];   // ������
//int &rA = a;
//int array[2] = {rA,a}; // ��������

// �����ķ���ֵ���Ա���ֵ
/*func() = 30;
cout << age << endl;*/

// ����
/*int a = 11;
int b = 22;
swap(a,b);
cout << "a is " << a << endl;
cout << "b is " << b << endl;*/

// ��������
// ���õı��ʾ���ָ��
	int age = 10;
	// ����ͨ��ָ���޸���ָ�������
	const int *rAeg = &age;

	getchar();

	return 0;
}
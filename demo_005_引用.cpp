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
//========== 1、引用相当于是变量的别名 ==========//
	// 1.1 基本数据类型
	/*int age = 10;
	int &rAge = age;
	rAge = 30;
	cout << age << endl;*/

	// 1.2 枚举
	/*Season season;
	Season &rSeason = season;
	rSeason = Fall;
	cout << season << endl;*/

	// 1.3 结构体
	/*Person person;
	Person &rPerson = person;
	rPerson.age = 100;
	cout << person.age << endl;*/

	// 1.4 指针
	/*int a = 10;
	int b = 20;

	int *p = &a;
	int *&rP = p;
	rP = &b;
	*p = 30;
	cout << a << endl;
	cout << b << endl;*/

	// 1.5 数组
	/*int array[] = {10,20,30};
	int(&rArray)[3] = array;
	rArray[1] = 100;
	cout << rArray[1] << endl;*/

	// int *a[4];   指针数组
	// int (*b)[4]; 指向数组的指针 

//========== 2、对引用做计算就是对引用所指向的变量做计算 ==========//
	/*int a = 10;
	int &rA = a;
	rA += 20;
	cout << rA << endl;*/

//========== 3、在定义的时候必须初始化，一旦指向了就不能更改 ==========//
	/*int a = 10;
	int b = 20;
	int &rA = a;
	rA = b;       // a = b = 20
	rA = 30;	  // a = 30

	cout << a << endl; 
	cout << b << endl;*/

//========== 4、可以用引用去初始化另一个引用，相当于一个变量的多个别名 ==========//
	/*int a = 10;
	int &rA = a;
	int &rB = rA;
	int &rC = rB;

	cout << rA << endl;
	cout << rB << endl;
	cout << rC << endl;
*/

//========== 5、不存在情况 ==========//
	// 5.1 引用的引用
	/*int a = 10;
	int &&a = a;*/

	// 5.2指向引用的指针
	/*int &rA = a;
	int &*b = &rA;*/

	// 5.3引用数组
	/*int &array[];   // 不允许

	int &rA = a;
	int array[2] = {rA,a}; // 这样可以 */

//========== 6、函数的返回值可以被赋值 ==========//
	func() = 30;
	cout << age << endl;

//========== 7、交换方法 ==========//
	/*int a = 11;
	int b = 22;
	swap(a,b);
	cout << "a is " << a << endl;
	cout << "b is " << b << endl;*/

	getchar();

	return 0;
}

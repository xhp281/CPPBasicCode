# C++基础语法

### 一、函数重载（Overload）
#### 规则
* 函数名相同
* 参数个数不同、参数类型不同、参数顺序不同 
#### 本质
> 采用了name mangling或者叫name decoration技术

* C++编译器默认会对符号名（变量名、函数名等）进行改编、修饰，有些地方翻译为“命名倾轧”
* 重载时会生成多个不同的函数名，不同编译器（MSVC、g++）有不同的生成规则
* 通过IDA打开【VS_Release_禁止优化】可以看到
#### _注意_
> * 函数返回值类型与函数重载无关
* 函数调用时，实参的隐式类型转换可能会产生二义性

### 二、extern "C"
> C\C++混合开发的是使用，被extern "C"修饰的代码会按照C语言的方式去编译

#### 规则
1.如果函数同时有声明和实现，要让函数声明被extern "C"修饰，函数实现可以不修饰
```cpp
extern "C" void func();
void func(){
	cout << "func" << endl;
}
```
2.C语言文件被C++引用的常用写法
```cpp
#ifndef __TEST_H
#define __TEST_H

#ifdef __cplusplus
extern "C" {
#endif
// code
#ifdef __cplusplus
}
#endif

#endif
```
### 三、默认参数
> C++允许函数设置默认参数，在调用时可以根据情况省略实参

#### 规则
1. 默认参数只能按照右到左的顺序
1. 如果函数同时有声明、实现，默认参数只能放在函数声明中
1. 默认参数的值可以是常量、全局符号（全局变量、函数名）
```cpp
int age = 10;

void test(){
  cout << "test()" << endl;
}

void display(int a, int b = 2, int c = age, void(*func)() = test){
  cout << "a is " << a << endl;
  cout << "b is " << b << endl;
  cout << "c is " << c << endl;
	func();
}

int main(){
	display();
  return 0;
}
```
#### _注意_
> 函数重载，默认参数可能会产生冲突，二义性（建议优先选择使用默认参数）

```cpp
void display(int a,int b = 20){
	cout << "a is " << a << endl;
}

void display(int a){
	cout << "a is " << a << endl;
}

int main(){
	display(10); 	// 此处会报错
	return 0;	
}
```
### 四、内联函数(inline function)
#### 特点 
1.  编译器将函数调用直接展开为函数体代码
1.  可以减少函数调用开支
1.  会增大代码体积
#### _注意_
> * 尽量不要内联超过10行代码的函数
* 有些函数即使声明为inline，也不一定会便被编译内联，比如递归函数
* 内联函数与宏（推荐使用内联函数）
* 都可以减少函数调用的开支
* 对比宏，内联函数多了语法检测和函数特性
### 五、pragma once 和 ifndef
#### 联系
1.使用 #ifndef、 #define、 #endif 来防止头文件内容被重复包含
```cpp
#ifndef __TEST_H
#define __TEST_H

// code

#endif
```
2.#pragma once 可以防止整个文件的内容被重复包含
```cpp
 #pragma once
```
#### 区别
* #ifndef、 #define、 #endif 受C\C++标准的支持，不受编译器的任何限制
* 有些编译器不支持 #pragma once ，兼容性不好
* #ifndef、 #define、 #endif 可以针对文件中的部分代码，#pragma once只能针对整个文件
### 六、引用(Reference）
> 在C语言中，使用指针（Pointer）可以间接获取、修改某个变量的值
> 在C++中，使用引用（Reference）可以起到跟指针类似的功能

```cpp
int age = 10;
int &rAge = age; 
```
#### _注意_
* 引用相当于是变量的别名(基本数据类型、枚举、结构体、类、指针、数组等，都可以有引用)[参考代码](https://github.com/xhp281/cPlusPlusBasicCode/blob/master/demo_005_%E5%BC%95%E7%94%A8.cpp)
* 对引用做计算，就是对引用所指向的变量做计算<br />
* 在定义的时候就必须初始化，一旦指向了某个变量，就不可以再改变，“从一而终”<br />
* 可以利用引用初始化另一个引用，相当于某个变量的多个别名<br />
* 不存在：【引用的引用、指向引用的指针、引用数组】
* 引用存在的价值之一：比指针更安全、函数返回值可以被赋值


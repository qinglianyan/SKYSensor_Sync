### 不愧是国外公认讲的最好的【C++教程】技术大佬带你从零基础入门到精通

> https://www.bilibili.com/video/BV1Lb411Q7yq?p=9&share_source=copy_web

**p6**

预处理语句，编译器会把文件内容全部拷贝粘贴到代码文件中。

解决方案配置：解决方案平台，默认的是debug和x86或win32，后两个是一个意思

编译(alt+F7)：cpp->obj，链接obj->exe

**p9 变量**

```
int 32位，一个符号位，-20亿--20亿( -2b -- 2b)
unsigned in32位，全是正

char 1字节，short 2字节，int 4字节， long 4字节(取决于编译器)，long long 8字节
float 4字节，double 8字节， bool 1字节
sizeof(int)=4,sizeof(bool)=1.
```

```
这些数据类型间唯一区别是创建变量时分配多少内存
char a="A"||short a="A";
分别用std::cout<< a << std::endl;输出是什么
```

```
float浮点数定义的时候需要在后面添加一个f或F，float a = 5.5f;否则会被识别为double
bool实际只需要一个bit，但是存储时为了能够访问需要使用一个字节。
```

**p10 函数** 跟C语言一样

**p11 头文件**

```
头文件本质上还是复制粘贴
include的尖括号只用于编译器包含路径，引号可以引用任何地方的文件
```

```
有两种保证在一个编译单元中只使用一次头文件的方法：
1、     #pragma once
2、	   #ifndef _LOG_H
​		#define _LOG_H
​		…………
​		#endif
```

```
c++中#include <iostream>
c中#include <stdlib.h>
主要是为了区分c与c++标准库，带h的是c标准库
```

**p12 调试**

```
step into 进入这行代码中的函数

step over 跳过这行，到下一行

step next 跳出当前函数，返回调用这个函数的位置
```

**p17 指针**

```
一个指针一个地址，是一个保存内存地址的整数。无所谓类型

void ptr=0；

void* ptr = Null；这个是因为#define NULL 0

void ptr=nullptr；nullptr是C++11关键字
```

```
char* buffer = new char[8];

memset(buffer, 0, 8);

……

delete[] buffer;
```

**p18 引用**

> 引用通常只是指针的伪装，让他更容易阅读，更容易理解。
>
> **引用与变量绑定之后就不能改变了。**

```
int a = 5;

int& ref = a;引用其实就是一个a变量的别名，编译器不会生成两个变量。

ref = 2;
```

```c++
如何实现函数中修改原值？
//指针								//引用
void AddOne(int* value){			void AddOne(int& value){
    (*value)++；							value++;
}									}
void main(){						void main(){
	int a = 1;							int a=1;
    add(&a);							add(a);
    printf("a = %d\n", a);				printf("a = %d\n", a);
}									}

```

**p19 C++类**

```
类只是一些变量的集合，同时类中也可以包含操作变量的方法
类默认为private是只有类内可见的，但是可以用public：来公开
```

**p20 C++类与结构体**

```
类默认是private的，struct默认是public的
技术上并没有区别
如果只是想用结构体表示一些数据用结构体，如果是要求有大量功能的类以及类的继承等，就用类。
```

**p22 C++中的静态static**

```
static关键字
1、在类或结构体外部使用static关键字
	只能对定义它的翻译单元可见
2、在类或结构体内部使用static关键字
	该变量将与类的所有实例共享内存，静态变量只有一个实例。
在同一个文件夹下面有Static.cpp和Main.cpp两个文件。
在static和main中都在全局变量中定义int a = 10；会报错说重定义，因为彼此都可以看到。
在static.cpp中定义static int a = 10；则这个定义只在static.cpp中有效，也只能在static.cpp看到，不影响main.cpp再定义一个int a = 10；
在static.cpp中定义int a = 10；在main中想要用static中的a可以在全局变量定义那里定义extern int a；这个是说明可以在外部翻译单元中寻找这个变量。
```

**p23 C++类和结构体中的静态static**

```
不同的实例中的静态变量只有一个。
同时因为只有一个实例，所以并不在乎是哪一个实例访问的，可以直接用类名。
struct Entity{
	static int x, y;
	void Print(){
		std::cout << x << " , " << y << std::endl;
	}
}
int Entity::x;	//如果结构体中添加static关键字，需要在结构体外部这样定义。
int Entity::y;
int main(){
	Entity e;
	e.x = 1, e.y = 2;
}

静态方法不能访问非静态变量
非静态方法：
	在外部会有一个类实例的参数，比如print()会先传递进来要print哪一个类实例。
	但是在类内部的非静态方法总是会获得一个当前类的实例作为(隐藏)参数，这也是幕后的实际工作方法。
静态方法不会得到那个隐藏参数，静态方法与类外部编写方法相同
```

**p24 C++中的局部静态local static**

> ​		我们可以在局部作用域中使用static来声明一个变量。声明一个变量我们需要考虑两种情况，一个是变量的生存期，另一个是变量的作用域。生存期指的是变量实际存在的时间(在内存中存多久)，而变量的作用域是指我们可以访问变量的范围。
>   **静态局部(Local static)变量允许我们声明一个变量，它的生存周期基本相当于整个程序的生存期，但是作用范围被限制在作用域内。**

```
#include<iostream>

void Func()
{
    static int i = 0;
	i++;
	std::cout << i << std::endl;
}

int main()
{
	Func();
	Func();
	Func();
	Func();
	Func();
	std::cin.get();
}
第一次调用Func()函数的时候生成了一个i变量，之后每次调用都用的是同一个i变量。
其实用一个全局变量也可以达到这个效果，但是全局变量也可以在函数之外引用。
```

```
使用局部静态创建单例类
class Singleton{
public:
	static Singleton Get(){
		static Singleton CreatOne;
		return CreatOne;
	}
	void Hello(){
		std::cout << "Hello !" << std::endl;
	}
}
int main(){
	Singleton::Get().Hello();
}
```

**P25 C++枚举**

```
枚举就是一个整数。
定义：
enum Example	//可以指定类型，默认是int  (enum Example : unsigned char)
{
	A, B, C		//可以指定是多少，默认0递增
};
使用：
Example value = B;
```

**P26 C++构造函数**

```
每次构造一个对象都会调用
举例子：
class Entity
{
public:
	float X, Y;
	Entity(){
		X = 0.0F;
		Y = 0.0F;
	}
	Entity(float x, float y){	//方法重载
		X = x;
		Y = y;
	}
}
隐藏构造函数。
如果只想让用户使用类提供的静态方法但是不想用户能够创建实例：
class Log
{
___________1、将构造函数设置为private___________
private:
	Log(){}
	
___________2、使用特定的写法___________
	Log() = delete;

public:
	static void LogHello(){
	}
}
这样之后使用只能Log::LogHello();而不能使用Log One；这样来创建实例了。
```

**P27 C++析构函数**

```
析构函数在销毁对象时运行
~Entity(){
}
```

**P28 C++继承**

```
class Player : public Entity
{
	
}
```

**P29 C++虚函数**

```
由于编写代码的时候并不能确定被调用的是基类的函数还是哪个派生类的函数，所以被成为“虚”函数。
虚函数主要通过V-Table虚函数表来实现，该表主要包含一个类的虚函数的地址表，可解决继承、覆盖的问题。
在父类中用virtual修饰，在子类中用override修饰并重新定义成员函数。
class Entity{
public :
··	virtual std::string GetName(){ return "Entity" };
}
class Player : public Entity{
private:
	std::string m_Name;
public:
	Player(const std::string& name)
		:m_Name(name){}					//构造函数后面的这个:表示的是赋值，这
··	std::string GetName() override{		//是c++的特性,成员函数后面也可以加：
		return m_Name;
	}
}
```

**P30 C++接口（纯虚函数）**

```
纯虚函数允许我们在基类中定义一个没有实现的函数，然后强制子类去实现该函数。
就是接口
class Printable{
public:
	virtual std::string GetClassName() = 0;	//直接=0，就能定义是一个接口了
}
class A:public Printable{					//子类直接继承这个接口
public:
	std::string GetClassName() override{	//需要实现虚函数
		return "A";
	}
}
void Print(Printable* obj){					//直接可以Print(new A());
	std::cout << obj->GetClassName() <<std::endl;
}
```

**P31 C++可见性**

```
private < protected < public
private		只有Entity类和他的友元才能访问，子类也不能访问
protected	只有Entity类和他的子类能够访问
public		所有人都可以访问 
```

**P32 C++数组**

```c++
1、
int example[5];
int* ptr = example;
以下三个是等价的
example[2] = 5;
*(ptr + 2) = 5;
*(int*)((char*)ptr + 8) = 5;

2、
int* another = new int[5];	//这种创建数组的方法与上一种不同的点在于：
………………						//上面的是在栈上创建，而new是在堆上创建
delete[] another;			//最大区别在于生存周期上:
//栈中存储的数据的生命周期随着函数的执行完成而结束。
//在堆上创建数组，生存周期是主动销毁之前都是活动状态。程序在访问这给数组时会先访问指针地址，再跳转到数值，这种方式是间接寻址，影响性能。可能的话应该尽量在栈上面创建数组来避免性能影响。
另外对于上面两种定义方法来获取数组中元素个数有区别
int count = sizeof(example) / sizeof(int);
如果数组在栈中，可以返回个数，但是如果是在堆中，example是一个int*指针，结果是1.

3、
c++11 有标准数组std::array,自带有边界检查，可以用another.size()直接获取元素个数。
std::array<int, 5> another;
```

**P33 C++字符串**

```
char* name = "Cherno";
char name2[7] = { 'C', 'h', 'e', 'r', 'n', 'o', 0 };
//char name2[7] = { 'C', 'h', 'e', 'r', 'n', 'o', '\0'};
std::string name = "Cherno";

//两个字符串相加
std::string name = std::string("Cherno") + " hello!";
	//std::string name = "Cherno";	name += " hello!";
//在c++14中有个std::string_literals提供了一些简单的方法
using namespace std::string_literals;
std::string name0 = "Cherno"s + " hello!";//添加了个s，实际上是变成了一个函数

//后来者补充
//1、注意string不能与null相比较，可以与""比较。
//2、注意比如Log(const char * message),但是使用的时候是传递的std::string类型，可以使用c_str,这个是返回一个临时指针，指向string的头部
//比如 Log( a.GetName().c_str() )，注意需要括号，一般总是忘记写括号
```

**P34 C++字符串字面量**

```
字符串字面量永远保存在内存的只读区域内
如果我们是用char name[]="Cherno";然后name[2]='a';来修改的话，实际上是将只读区域的字面量有复制了一份放在了一个新建的变量中去
```

**P35 C++中的CONST**

```c++
承诺不改变值
1、
const int MAX_AGE = 90;
2、
const int* a = new int;		//也可以 int const * a = new int;
//这样写不可以改变 *a 这个实际地址的值，但是可以读取
//但是可以a = (int*)&MAX_AGE这样改变指针本身
int* const a = new int;
//与上面正好相反。可以改变 *a = 2 这个实际地址的值，也能读取
//但是不可以改变指针本身。
const int* const a = new int;
//两个都不能改
3、
在类中以及方法中使用
承诺不会修改任何实际的类，因此不能修改类成员变量
class Entity{
private:
    int m_X;
public:
    int GetX() const
    {
        return m_X;
    }
}
一个应用场景：(尽量标记方法为const，当方法实际没有修改类或者是不应该修改类的时候)
void PrintEntity(const Entity& e){			//按照上面那个，我可以给改变e，如e=nullptr。
    std::cout << e.GetX() << std::endl;		//但是不能改变e指向内容的值，但是GetX函数是
}											//有可能修改指向的值的，因此可以写一个不带const，
											//一个带const的，提前说明不会修改类成员变量
在C++中，mutable也是为了突破const的限制而设置的。被mutable修饰的变量，将永远处于可变的状态，即使在一个const函数中。
	int m_X;
	mutable int var;
```

```
补充
连续定义指针的时候需要每一个变量前面都加一个星号*	eg:	   int *a, *b, *c;
如果是只有一个，那么后面的变量其实就是定义成int	 eg:	int* a, b, c;
```

**P36 C++的mutable关键字**

```c++
class Entity
{
private:
	std::string m_Name;
    mutable int m_DebugCount = 0;		//用来看一共调用了几次GetName()
public:
    const std::string& GetName() const	//想想这里为什么有&
    {									//网上：一般情况下参数用const std::string&，返回值用std::string。
		m_DebugCount++;					//虽然在const修饰的方法中，但是还是能够修改
        return m_Name;
    }
}
```

**P37 C++的成员初始化列表**

```c++
class Entity
{
private:
	std::string m_Name；
	int m_Score;
public:									//等同于
	Entity()//初始化按照顺序				Entity()
		:m_Name("Unknown"), m_Score(0)	{
	{										m_Name="Unknown", m_Score=0;
	}									}
}
//一方面是比较好看，另一方面是避免性能的浪费
像是例子中的m_Name，实际上是定义的时候生成了一个string，在赋值语句中又生成了一个string，然后赋值
m_Name="Unknown"实际上是m_Name=std::string("Unknown");
视频中是把另一个类作为属性来举例子的
```

**P38 C++的三元操作符**

```
std::string rank = s_Level > 10 ? "Master" : "Beginner";
也可以嵌套，但是别过混~
```

**P39 创建并初始化C++对象**

```
Entity 	entity("Cherno");				//在栈中创建  栈通常比较小，如果要定义的类特别多特别大 尽量在堆中创建。但是能用栈的时候还是尽量使用栈，一方面是效率比较高，另一方面内存申请与释放由编译器完成，避免内存泄漏
Entity* entity = new Entity("Cherno");	//在堆中创建  之后需要delete entity;
//在堆中创建分配要比栈上花费更多时间，而且需要手动释放分配的内存。
//如果只new(或malloc)而不delete，就会造成内存泄漏，最终内存耗尽而OOM。
//如果程序终止了，其中new申请的内存会由操作系统回收的，这个不用管。


//在Java与c#中 通常是Entity entity = new Entity();他们通常不能自定义创建在栈或是堆中
//c#中的struct，即使是用new也是在栈上分配的；c#中，所有的类都是在站上分配的
//Java中所有东西都在堆上。
```

**P40 C++ new关键字**

```
int* a = new int;
int* b = new int[50];

Entity* e = new Entity();
//与Entity* e = (Entity*)malloc(sizeof(Entity));区别在于，new同时调用了构造函数，为类分配的时候不用new而用malloc很麻烦，尽量不要用malloc

placement new 在一个特定的内存地址初始化Entity，使用new()
Entity* e = new(b) Entity();

记得delete和delete[];
```

**P41 C++隐式转换与explicit关键字**

```c++
class Entity
{
private:
	std::string m_Name;
	int m_Age;
public:
	Entity(const std::string& name)
		:m_Name(name), m_Age(-1){ }
	Entity(int age)
		:m_Name("Unknown"), m_Age(age){ }
};
int main(){
    Entity a = 22;			//隐式转换，因为Entity有参数为int的构造函数，
    						//因此隐式调用把22变成了Entity。注意必须有参数为int的构造函数才可以
    Entity b = "Cherno";	//这个会报错，因为"Cherno"实际是const char *,需要进行两次转换
    						//分别是const char * -> string ->Entity
    						//但是隐式转换之会发生一次！！！！
//很明显吧，因为string不是基础数据类型，而且C++11之前字符串常量默认类型是char *,C++11后改为const char *
}

explicit关键词
/ɪkˈsplɪsɪt/adj.	明确的; 详述的; 直言的, 坦率的; 一目了然的;
explicit会禁止隐式转换，explicit关键词放在构造函数前面
    explicit Entity(int age)
    	:m_Name("Unknown"), m_Age(age){ }
```

**P42 C++运算符及其重载**

```c++
运算符就是函数
struct Vector2
{
	float x, y;
	Vector2(float x, float y)
		:x(x), y(y) { }
	Vector2 Add(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}
	Vector2 Multiply(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}
	Vector2 oprator+(const Vector2& other) const
	{
		return Add(other);
	}
};
```

```
//补充一个
	Vector2& operator++() {			//前置++
		this->num += 1;
		return *this;
	}
									//后置++两种写法
	const Vector2 operator++(int) {		Vector2& operator++(int) {
		Entity old = *this;				static Entity old = *this;
		++* this;						old = *this;	++* this;
		return old;						return old;
	}								}
1、返回值。 前置++返回一个引用，后置++返回一个对象。因为后置++返回的是一个在函数中新建的一个临时对象，所以调用完之后就被释放掉了，引用就无效了。(c++标准的规定：非常亮的引用更不能指向临时对象)
2、第二种后置++写法。如果非得要后置++也返回一个引用，需要用static定义成静态。由于static只执行一次，还需要再写一遍old = *this;
3、为什么后置++有一个int形式参数。前置++与后置++的操作符重载函数，函数原型必须不同。否则就违反了“重载函数必须拥有不同的函数原型”的语法规定。虽然前置++与后置++的返回类型不同，但是返回类型不属于函数原型。为了绕过语法限制，只好给后置++增加了一个int形参。
4、对于基础类型，前后++效率基本相同；对于类类型对象，前置效率要高于后置++.
5、为什么后置++需要有const。a、对于内置类型(如int) (a++)++不能通过编译，要与其保持一致。b、对于(a++)++这种，如果不是const就能通过编译，但是第二次自增作用在了一个临时对象上，结果上只增加了一次，与我们直觉不同。
6、尽量使用前置++
```

**P43 C++的this关键字**

```
是个指针，有时候会用const修饰
```

**P44 C++的对象生存期（栈作用域生存期）**

**P45 C++的智能指针**

> 自动化new和delete 本质上是原始指针的包装
>
> 要访问智能指针，需要包括memory头文件	#include <memory>

```c++
1、unique_ptr
作用域指针，当作用域完成就结束了，调用delete.
不能复制unique_ptr,因为如果复制的话就是两个指针指向同一个内存块
当一个释放后就变成了一个指向被释放内存的指针
使用方式：
	std::unique_ptr<Entity> entity(new Entity);
	//std::unique_ptr<Entity> entity = new Entity()
	//不可以上面注释的写法，因为unique_ptr有explicit修饰不能隐式转换
	//出于异常安全原因，一般写下面这个，如果发生了异常更安全一些
	std::unique_ptr<Entity> entity = std::make_unique<Entity>();
不能复制unique_ptr，如std::unique_ptr<Entity> e0 = entity;因为unique_ptr的=和拷贝操作都被删除了.

2、shared_ptr
    工作方式是引用计数；引用计数跟踪指针有几个引用，一旦到0就delete了;
	std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
	//上一个不用new是因为异常安全，shared不用new是因为shared还有一个控制块需要来存储引用计数，如果用new就有两次内存分配，一次new，一次控制内存块分配。
使用方式：
{
    std::shared_ptr<Entity> e0;
    {
        std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>)();
        e0 = sharedEntity;
    }
}

3、weak_ptr
可以与shared_ptr结合使用
将shared_ptr赋值给另一个shared_ptr会增加引用次数，但是将shared_ptr赋值给weak_ptr不会增加引用次数.
```

**P46 C++的复制与拷贝构造函数**

```c++
class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size+1];//+1为终止字符
	    memcpy(m_Buffer, string, m_Size+1);
	}

	~String()
	{
		delete[] m_Buffer;
	}
}
//上面是要用的例子,主要有一个m_Buffer和一个记录带线啊哦的m_Size
复制主要是需要考虑 浅拷贝 和 深拷贝
1、浅拷贝只是拷贝了指针
    String string = "Cherno";
	String second = string;
这样在结束的时候因为两个m_Buffer相同，delete的时候就delete了两次，因此会报错。
2、深拷贝需要拷贝指针对象的内容
    拷贝构造函数是一个构造函数，当复制第二个字符串时他会别调用。
    c++默认提供一个拷贝构造函数，拷贝构造函数的函数签名对同样的类对象的常引用const &，它的作用是内存复制，将other对象的内存浅层拷贝进这些成员变量。
    String(const String& other)//拷贝构造函数
		:m_Buffer(other.m_Buffer), m_Size(other.m_Size) {}
	//这样不行，因为不仅仅想复制指针还想复制指针所指向的内存
	String(const String& other)
		:m_Size(other.m_Size)
	{
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size+1);
	}//right
3、remember：通过const引用来传递对象,主要是防止到处复制.
```

**P47 C++的箭头操作符**

**P48 C++的动态数组**

```c++
include <vector>
struct Vertex{	float x, y, z;	};
1、定义。<>中可以是基本数据类型也可以是定义的类和结构体
std::vector<Vertex> vertices;
vector<int> sdt;//无参构造
vector<int> s1(4,100);//构造并初始化4个100
vector<int> s2(s1.begin(), s1.end());//使用迭代器进行初始化构造
vector<int> s3(s1);//拷贝构造

2、向数组中添加元素，push_back就相当于是其他语言中的add
vertices.push_back({1, 2, 3});
//在vector的末尾插入新元素
vec.push_back(1);
//在迭代器的前面插入新元素
vector<int>::iterator it;
it=vec.begin();
vec.insert(it,5);//在第一个元素前面插入5
//在vector中加入3个1元素，同时清除掉以前的元素
vec.assign(3,1);//现在vector中只有3个1

3、for循环中可以这么写，也可以不写&但是会每次循环复制一个副本
for(Vertex& v : vertices) ……
//利用迭代器进行访问
vector<int>::iterator it;
for(it=a.begin();it!=a.end();it++){
   cout<<*it;
}
4、删除元素
//删除最后一个元素
vec.pop_back(); 
//删除指定位置的元素
vec.erase(vec.begin());//删除第一个位置的元素值
//清除所有元素
vec,clear();
//判断该数组是否为空
vec.empty();

//补充
//利用vector数组
//n行m列，即a[n][m]
cin>>n>>m;
vector<vector <int> >a(n);
for(int i=0;i<n;i++){
	a[i].resize(m);
}
```

**P49 C++的stdvector使用优化**

```c++
std::vector<Vertex> vertices;
vertices.push_back(Vertex(1,2,3));
vertices.push_back(Vertex(4,5,6));
vertices.push_back(Vertex(7,8,9));
上面每一次push需要进行：
(由于vector大小变大)复制一份并添加一个元素，在内存中生成vertex，将vertex复制到vertices所在地址中
那么三次pushback就有六次拷贝(可以写一个拷贝构造函数来看)，第一二三次pushback分别有一二三次拷贝。
优化：
std::vector<Vertex> vertices;
vertices.reserve(3);
vertices.emplace_back(1,2,3);
vertices.push_back(Vertex(4,5,6));
vertices.push_back(Vertex(7,8,9));
	reserve是容器预留空间，但在空间里不真正创建对象。也就是capacity
    resize是改变容器大小，且创建元素。也就是size。
 	emplace_back是以后面给的参数直接在vector地址中创建对象
```

**P50 C++中使用库（静态链接）**



**P51C++中使用动态库**



**P52C++中创建与使用库**



**P53C++中如何处理多返回值**



**P54C++的模板**



**P55C++的堆与栈内存的比较**



**P56C++的宏**



**P57C++的auto关键字**



**P58C++的静态数组**



**P59C++的函数指针**



**P60C++的lambda**

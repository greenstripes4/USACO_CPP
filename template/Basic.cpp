#include <bits/stdc++.h>
using namespace std;

//产生指定范围内的随机数
int randomInt(int low, int high)
{
	srand(time(0));
	return rand() % (high - low + 1) + low;
}

//输出m个字符的随机字符串
string randomStr(int m)
{
	srand(time(0));
	string str = "";
	for (int j = 1; j <= m; j++)
	{
		int temp = rand() % 2;					   //随机决定输出大写字母或小写字母
		if (temp)								   //相当于temp==1
			str += (char)(rand() % (26) + 1 + 64); //随机生成大写字母加到str末尾
		else
			str += (char)(rand() % (26) + 1 + 96); //随机生成小写字母加到str末尾
	}
	return str;
}

struct student //声明一个名为student的结构体类型
{
	int ID;		   //学号
	char name[20]; //姓名
	char sex;	   //性别
	float score;   //成绩
};				   //声明结束，注意此处不可省略分号

int Cmp(student a, student b)
{
	if (a.score != b.score)
		return a.score < b.score; //如果a.score不等于b.score，就按x从小到大排序
	return a.ID < b.ID;			  //如果score相等则按ID从小到大排序
}

void ioSample()
{
	//输出整数,即输出a=123
	printf("a=%d\n", 123);
	//输出整数宽度为5,默认右对齐,即输出a=  123
	printf("a=%5d\n", 123);
	//输出整数宽度为5,负号表示左对齐,即输出1    ,2
	printf("%-5d,%d\n", 1, 2);
	long long x = 1234567890000;
	//输出超长整数,即输出1234567890000
	printf("%lld\n", x);
	float y = 123.456;
	//输出单精度浮点数,即输出y=123.456001。注意此处有误差
	printf("y=%f\n", y);
	//输出数据宽度为12,默认右对齐,即输出y=  123.456001
	printf("y=%12f\n", y);
	//输出数据宽度为12,负号表示左对齐,即输出y=123.456001  ,OK
	printf("y=%-12f,OK\n", y);
	//输出数据总宽度为10,小数部分取2位,即输出y=    123.46。注意此处有误差
	printf("y=%10.2f\n", y);
	//输出数据总宽度为1(过小无效),小数部分取2位,即输出123.46。注意此处有误差
	printf("%1.2f\n", y);
	double z = 45.67;
	//输出双精度浮点数,即输出45.670000
	printf("%lf\n", z);
	//输出数据宽度为12,默认右对齐,即输出z=   45.670000
	printf("z=%12lf\n", z);
	//输出数据宽度为12,负号表示左对齐,即输出z=45.670000   ,OK
	printf("z=%-12lf,OK\n", z);
	//输出数据宽度为10,小数部分取2位,即输出z=     45.67
	printf("z=%10.2lf\n", z);
	//输出数据宽度为0(过小无效),小数部分取2位,即输出z=45.67
	printf("z=%0.2lf\n", z);
	char c = 'x';
	//输出单个字符
	printf("%c\n", c);
	//输出字符串,即输出s=abc
	printf("s=%s\n", "abc");
	//输出字符串宽度为8,右对齐,即输出s=     abc
	printf("s=%8s\n", "abc");
	//输出字符串宽度为8,左对齐,即输出a      ,b
	printf("%-8s,%s\n", "a", "b");
	//输出字符串长度大于2,宽度限制无效,即输出s=abc
	printf("s=%2s\n", "abc");
	//宽度为10,取左端4个字符,默认右对齐,即输出      abcd
	printf("%10.4s\n", "abcdef");
	//宽度为8,取左端3个字符,负号表示左对齐,即输出abc     ,OK
	printf("%-8.3s,OK\n", "abcde");

	int a1, x1, y1;
	float b1;
	long long c1;
	scanf("%d %f %lld", &a1, &b1, &c1); //输入整数、单精度浮点数、超长整数
	scanf("%o %x", &x1, &y1);			//以八进制数、十六进制数形式输入x、y
	char ch1;
	getchar();		   //用getchar()函数消去之前输入的换行符
	scanf("%c", &ch1); //否则字符变量ch就会接收到换行符

	//取消cin与stdin的同步，使cin与cout拥有与scanf()函数和printf()函数相近的执行效率。
	//注意使用该语句后，cin和cout不可与scanf()函数和printf()函数等混合使用！
	ios::sync_with_stdio(false);
	//解除cin与cout的绑定，进一步加快执行效率。
	cin.tie(0);
	int n = 314;
	cout << "十进制:" << dec << n << endl; // n本身为十进制数，所以可省略dec
	cout << "八进制:" << oct << n << endl; //用endl会降速，应替换为'\n'
	cout << "十六进制:" << hex << n << endl;
	cin >> oct >> n;  //输入八进制形式的n值
	cout << dec << n; //转换为十进制形式的n值输出
}

void stringSample()
{
	string s = "Hi,..morn";		//定义了名为s的string类并初始化
	s = s + "ing";				//尾部添加字符串"ing"
	cout << s << endl;			//输出"Hi,..morning"
	s.erase(3, 2);				//删除第3个字符后的2个字符
	cout << s << endl;			//输出"Hi,morning"
	int f = s.find("Hi,");		//查找"Hi,"在s中的位置，-1为无法找到
	s.insert(f + 3, 2, 'G');	//在第3个字符后插入单个字符'G'2次
	cout << s << endl;			//输出"Hi,GGmorning"
	s.insert(5, ",MM,");		//在第5个字符后插入字符串",MM,"
	cout << s << endl;			//输出”Hi,GG,MM,morning”
	string v = s.substr(4, 3);	//取s中第4个字符后的3个字符给v
	cout << v << endl;			//输出"G,M"
	cout << v.length() << endl; //输出3,即v的长

	// cin读取一行字符串时，遇到空格就会停止。如果读取一行包含空格符的字符串，可以使用getline()函数。
	string sa, sb;
	getline(cin, sa); //读取一行包含空格符的字符串赋值给str
	getline(cin, sb);
	cout << sa << endl;
	cout << sb.length() << endl; // strlen(字符串)的功能是返回字符串的长度，不包括字符串结束标记'\0'。
	sa.find(sb);				 //查找sa中第一次出现sb的位置，如果找不到就返回 - 1。
	sa.find(sb, 5);				 //从sa的第p个位置开始查找第一次出现sb的位置，找不到就返回-1
								 // string support +, =, +=, ==, !=, <, <=, >, >=, []
}

void arraySample()
{
	int aa[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int f1[101];			   //没赋初始值的情况下，数组f[]内的各元素值未知
	memset(f1, 0, sizeof(f1)); //将数组f[]内的数组元素全部赋值为0
	int a[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int b[][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; //第一维的下标值可省略，第二维的下标值不可省略
	int c[][4] = {{0, 0, 3}, {}, {0, 10}};				  //未赋值的数组元素均自动初始化为0

	char c1[] = {"I am ok"}; //定义字符数组时全部元素均赋值，数组大小定义可省略
	char c2[] = "I am ok";
	char c3[] = {'I', ' ', 'a', 'm', ' ', 'o', 'k', '\0'}; //'\0'为字符串结束标记
	char str1[] = "Hello!";
	char str2[] = "hello!";
	cout << strlen(str1);
	cout << strcmp(str1, str2);
	strcpy(str1, "abcde");
	char a1[] = "12345", b1[] = "67890";
	strcat(a1, b1);
	cout << a1;			//输出1234567890
	strstr(str1, str2); //用于判断字符串str2是不是字符串str1的子串。如果是则该函数返回str2在str1中首次出现的地址，否则返回0（空指针NULL）
}

void pointerSample()
{
	int ai = 3, bi = 4;
	int *p1, *p2;								//定义两个指针变量*p1、*p2F
	p1 = &ai;									//把变量a的地址值赋给p1
	p2 = &bi;									//把变量b的地址值赋给p2
	printf("%d %d  %d %d\n", ai, bi, *p1, *p2); //显示结果为3 4  3 4

	int aa[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int *p = aa;				 //可以在定义指针变量的同时赋初始值
	for (int i = 0; i < 10; i++) //以下标方式输出
		printf("%d", p[i]);
	for (; p < (aa + 10); p++) //以指针方式输出，p++表示指向下一个元素
		printf("%d", *p);

	struct student stu[3];						  //定义了结构体数组stu[3]
	struct student as = {10001, "Cody", 'M', 95}; //定义结构体变量并赋值
	printf("%d %s %c %f\n", as.ID, as.name, as.sex, as.score);
	struct student *ps;										//*p必须和stu一样，均为struct student类型
	ps = &as;												//结构体指针p指向结构体stu
	cout << (*ps).name << (*ps).sex << (*ps).score << endl; //输出方式1
	cout << ps->name << ps->sex << ps->score << endl;		//输出方式2
}

void sortSearchSample()
{
	int sa[] = {-1, 9, -34, 100, 45, 2, 98, 32}; //无序整型数组元素
	int lensa = sizeof(sa) / sizeof(int);
	sort(sa, sa + lensa);				  //由小到大排序
	sort(sa, sa + lensa, greater<int>()); //由大到小排序
	// stable_sort 和 sort的区别在于前者排序后可以使原来的“相同”的值在序列中的相对位置不变。

	// lower_bound(起始地址first,结束地址last,要查找的数值val)：
	// 在first和last中的前闭后开区间进行二分查找，返回大于或等于val的第一个元素地址。
	// 如果区间内所有元素都小于val，则返回last的地址，且last的地址是越界的。
	// upper_bound(起始地址first,结束地址last,要查找的数值val)：
	// 在first和last中的前闭后开区间进行二分查找，返回大于val的第一个元素地址。
	// 如果val大于区间内所有元素，则返回last的地址，且last的地址是越界的。
	int a[] = {1, 1, 2, 2, 3, 3, 3, 4, 4, 4};
	cout << lower_bound(a, a + 10, 0) - a << endl; //输出下标 0
	cout << lower_bound(a, a + 10, 1) - a << endl; //输出下标 0
	cout << lower_bound(a, a + 10, 3) - a << endl; //输出下标 4
	cout << lower_bound(a, a + 10, 4) - a << endl; //输出下标 7
	cout << lower_bound(a, a + 10, 5) - a << endl; //输出下标 10
	cout << upper_bound(a, a + 10, 0) - a << endl; //输出下标 0
	cout << upper_bound(a, a + 10, 1) - a << endl; //输出下标 2
	cout << upper_bound(a, a + 10, 3) - a << endl; //输出下标 7
	cout << upper_bound(a, a + 10, 4) - a << endl; //输出下标 10
	cout << upper_bound(a, a + 10, 5) - a << endl; //输出下标 10

	// 降序数组直接使用lower_bound/upper_bound二分查找的结果是错误的
	// 这是因为lower_bound/upper_bound默认二分查找的区间是升序序列。
	// 在降序序列lower_bound的正确写法为lower_bound(first, last, val, greater<int>())
	// upper_bound的正确写法为upper_bound(first, last, val, greater<int>())
	int a1[] = {4, 4, 3, 3, 2, 2, 1, 1};
	cout << lower_bound(a1, a1 + 8, 0, greater<int>()) - a1 << endl; //输出 8
	cout << lower_bound(a1, a1 + 8, 4, greater<int>()) - a1 << endl; //输出 0
	cout << lower_bound(a1, a1 + 8, 1, greater<int>()) - a1 << endl; //输出 6
	cout << lower_bound(a1, a1 + 8, 3, greater<int>()) - a1 << endl; //输出 2
	cout << lower_bound(a1, a1 + 8, 5, greater<int>()) - a1 << endl; //输出 0
	cout << upper_bound(a1, a1 + 8, 0, greater<int>()) - a1 << endl; //输出 8
	cout << upper_bound(a1, a1 + 8, 4, greater<int>()) - a1 << endl; //输出 2
	cout << upper_bound(a1, a1 + 8, 1, greater<int>()) - a1 << endl; //输出 8
	cout << upper_bound(a1, a1 + 8, 3, greater<int>()) - a1 << endl; //输出 4
	cout << upper_bound(a1, a1 + 8, 5, greater<int>()) - a1 << endl; //输出 0
}

//中间插入的时间为O(n)
void vectorSample()
{
	vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
	vector<int> a1(100);						  //元素个数100，所有数初始为0
	vector<int> a2(10, 666);					  //元素个数10，所有数初始为666
	vector<int> b1(a1);							  // b1是a1的复制
	vector<int> b2(a2.begin() + 3, a2.end() - 3); // b2是a2的部分复制
	vector<int> a[5];							  // 5个vector
	vector<int> v;								  //定义了一个存放整数的vector容器
	v.reserve(30);								  //调整数据空间大小
	v.push_back(20);							  //尾端插入新元素
	v.push_back(26);
	v.push_back(12);
	v.push_back(52);
	v.insert(v.begin(), 2);			   // begin()为指针，指向v的头部,在此处插入2
	v.insert(v.end(), 43);			   // end()为指针，指向v最后的元素的后面，插入43
	v.insert(v.begin() + 2, 15);	   //在第3个元素前插入15
	v.erase(v.begin() + 1);			   //删除第2个元素
	v.erase(v.begin(), v.begin() + 2); //删除前3个元素
	v.pop_back();					   //删除末尾的一个元素
	for (int i = 0; i < v.size(); ++i) // size()为v中元素的个数
		cout << v[i] << ' ';
	cout << "\n 首元素为:" << v.front() << '\n'; //首元素引用
	cout << "末元素为:" << v.back() << '\n';	 //末元素引用
	reverse(v.begin(), v.end());				 //反转整个vector元素
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
	v.clear();									  //清空全部元素
	cout << "\n v是否为空:" << v.empty() << '\n'; //判断是否为空

	a1.insert(a1.begin() + 1, 5, 10);					   //插入5个10
	a1.insert(a1.begin() + 1, a2.begin(), a2.begin() + 3); //插入vector a2的某个区间
	a1.resize(5);										   //设置大小为5，如果当前有8个元素，舍弃后3个
	if (find(a1.begin(), a1.end(), a2[0]) != a1.end())
	{
		//在a1中可以查到a2[0]
	}
}

typedef pair<string, double> Record; // typedef简化pair的声明为Record
void pairSample()
{
	pair<int, double> p1;						 //定义p1为pair类型，包含一个整数和一个浮点数
	pair<int, double> p[10];					 //定义pair类型的数组p[]
	pair<string, string> author("James", "Joy"); //定义author是pair类型且初始化
	p1.first = 10;
	p1.second = 12.5;
	cout << p1.first << ' ' << p1.second << endl;
	Record p2 = make_pair("zxh", 100);
	cout << p2.first << ' ' << p2.second << endl;
	// pair的比较是按照字典序比较的，比较时先按first的大小比较，如果相等，再按second的大小比较
	pair<int, char> A(10, 'z');
	pair<int, char> B(90, 'a');
	if (A == B)
		cout << "相等\n";
	if (A != B)
		cout << "不相等\n";
	if (A < B)
		cout << "A<B\n";
	if (A > B)
		cout << "A>B\n";
	if (A <= B)
		cout << "A<=B\n";
	if (A >= B)
		cout << "A>=B\n";
}

struct Comp
{
	bool operator()(const int &a, const int &b) const //重载操作符"（）"
	{
		return a > b; //由大到小排序
					  // return a<b;                        //由小到大排序
	}
}; //需在结构体内定义比较函数

struct Time
{
	int H, M, S;						//时，分，秒
	Time operator+(const Time &b) const //重载运算符"+"
	{
		return Time{H + b.H, M + b.M, S + b.S}; //仅为演示，不考虑进位
	}
} T1 = {3, 2, 4}, T2 = {5, 20, 30}, T3;

void operatorOverloadSample()
{
	T3 = T1 + T2;
	cout << T3.H << ":" << T3.M << ":" << T3.S << endl;
}

struct Info
{
	string name;
	double score;
	bool operator<(const Info &a) const //必须重载操作符"<"
	{
		return a.score < score; //从大到小排序（若改为"＞"则为从小到大排序）
	}
} info;

// set/multiset的iterator的++/--复杂度O(logN), default为升序
void setSample()
{
	set<int> s;
	for (int i = 10; i > 0; --i) //此处由大到小赋值
		s.insert(i);			 //插入元素
	set<int> s2(s);				 //复制s生成s2
	s.erase(s.begin());			 //删除操作
	s.erase(6);
	s.insert(5);							  //不会重复插入
	set<int>::iterator ii;					  // ii为正向迭代器
	for (ii = s.begin(); ii != s.end(); ii++) // ii从首地址到末元素地址遍历
		cout << *ii << ' ';					  // ii为地址，所以取地址上的值前面要加*
	cout << "\n元素个数为" << s.size();		  //统计set中元素个数，时间复杂度为O(1)
	ii = s.find(10);						  //查找元素值，并返回指向该元素的迭代器
	if (ii != s.end())						  //如果容器中不存在该元素，返回值等于s.end()
		cout << "\n查找=" << *ii;
	if (s.count(5)) // count返回s中值为5的元素个数，时间复杂度为O(logn)
		cout << "\n存在元素5";
	s.clear(); //清空所有元素
	cout << "\n元素是否为空:" << s.empty();

	set<int, greater<int>> sd; //降序
	set<int, Comp> s1;		   // set调用的比较函数为Comp（）
	// set<int,greater<int> >s;             //其实这样写最简单
	for (int i = 1; i <= 10; ++i) //此处由小到大赋值
		s1.insert(i);
	for (ii = s1.begin(); ii != s1.end(); ii++) //遍历
		cout << *ii << ' ';						//输出是由大到小排序

	// 当元素是结构体时，必须要重载运算符“<”
	set<Info> ss;
	info = {"A", 90.0};
	ss.insert(info);
	info = {"B", 92.0};
	ss.insert(info);
	info = {"C", 96.0};
	ss.insert(info);
	set<Info>::iterator iii;
	for (iii = ss.begin(); iii != ss.end(); iii++) //遍历
		cout << (*iii).name << ' ' << (*iii).score << endl;

	// rbegin is the last element of your container. end is one past the end of the container.
}

void multisetSample()
{
	multiset<int> m;
	m.insert(11); //插入数据
	m.insert(21);
	m.insert(10);
	m.insert(12);
	m.insert(12);
	m.insert(11);
	m.insert(11);
	m.insert(11);
	m.insert(9);
	cout << "11的个数有" << m.count(11) << endl; // count返回m中11的个数
	cout << "第一个大于等于10的元素为：" << *m.lower_bound(10) << endl;
	cout << "第一个大于11的元素为:" << *m.upper_bound(11) << endl;
	multiset<int>::iterator it;
	for (it = m.begin(); it != m.end(); it++)
		cout << *it << endl;							//从小到大输出
	cout << "删除12,有" << m.erase(12) << "个" << endl; //删除等于12的元素
	cout << "查找9\n";
	multiset<int>::iterator i = m.find(9); //查找v，返回该元素的迭代器位置
	if (i != m.end())					   //找到则输出，否则i为end()迭代器位置
		cout << *i << endl;
	int v = 11; //查找所有相同元素
	pair<multiset<int>::iterator, multiset<int>::iterator> p;
	// equal_range:有序容器中表示一个值第一次出现与最后一次出现的后一位
	p = m.equal_range(v);
	cout << "大于等于" << v << "的第一个元素为" << *p.first << endl;
	cout << "大于" << v << "的第一个元素为" << *p.second << endl;
	cout << "键值为" << v << "的全部元素为";
	for (it = p.first; it != p.second; it++) //打印重复键值元素11
		cout << *it << " ";
	m.clear(); //清空所有元素
}

void dequeSample()
{
	deque<string> d;  //定义一个包含string的deque
	d.push_back("A"); //尾部插入元素
	d.push_back("B");
	d.push_front("X"); //头部插入元素
	d.push_front("Y");
	// d.pop_front();                  //删除首元素
	// d.pop_back();                   //删除尾元素
	// d.erase(d.begin()+1);           //删除指定位置的元素
	// d.clear();                      //删除所有元素
	d.insert(d.end() - 2, "O");		   //指定位置插入
	reverse(d.begin(), d.end());	   //反转元素顺序
	for (int i = 0; i < d.size(); i++) //数组方式访问
		cout << d[i] << " ";
	cout << endl;
	swap(d[1], d[2]);					   //两个元素交换
	deque<string>::iterator i;			   //迭代器访问
	for (i = d.begin(); i != d.end(); i++) //正向遍历
		cout << *i << " ";
	cout << endl;
	cout << "\ndeque是否为空 " << d.empty();
	cout << "\ndeque元素个数为 " << d.size();
	cout << "\ndeque的首元素为 " << d.front();
	cout << "\ndeque的末元素为 " << d.back();
}

//双向链表，性能差
void listSample()
{
	list<int> l;
	l.push_back(2); //尾部插入新元素，链表自动扩张
	l.push_back(2);
	l.push_back(9);
	l.push_back(12);
	l.push_back(12);
	l.push_back(4);
	l.push_front(9); //头部插入新元素，链表自动扩张
	list<int>::iterator it;
	it = l.begin();
	it++;			  //链表迭代器只能++或--操作，不能+n操作，因为list节点非连续内存
	l.insert(it, 20); //当前位置插入新元素
	it++;
	l.erase(it);							  //删除迭代器位置上的元素
	for (it = l.begin(); it != l.end(); it++) //正向遍历
		cout << *it << " ";
	cout << endl;
	l.remove(12);					  //删除所有值为12的元素
	l.pop_front();					  //删除链表首元素
	l.pop_back();					  //删除链表尾元素
	it = find(l.begin(), l.end(), 4); //查找值为4的元素
	if (it != l.end())
		cout << "find " << *it << endl;
	l.sort();								  //升序排列
	l.unique();								  //删除连续重复元素(只保留一个)，不排序的话不连续的重复元素无法被去除
	for (it = l.begin(); it != l.end(); it++) //正向遍历
		cout << *it << " ";
	// l.clear();                          //清空链表
}

void mapSample()
{
	map<string, int> a1;				  //升序
	map<string, int, greater<string>> a2; //降序
	map<char *, float> m;
	m["apple"] = 3.4;
	m["orange"] = 1.2;
	m["pear"] = 3.5;
	cout << m["apple"] << endl;
	cout << m["orange"] << endl;
	cout << m["pear"] << endl;
	m.clear();

	map<int, string> ms;
	ms[1] = "student_one";
	ms[1] = "student_two"; // id相同，则覆盖
	ms[2] = "student_three";
	map<int, string>::iterator iter;
	ms.insert(make_pair(3, "student_four")); //插入新元素，用make_pair
	for (iter = ms.begin(); iter != ms.end(); iter++)
		cout << iter->first << " " << iter->second << endl;
	cout << endl;
	iter = ms.lower_bound(1); //首个大于等于1的元素
	cout << iter->second << endl;
	iter = ms.upper_bound(1); //首个大于1的元素
	cout << iter->second << endl;
	iter = ms.find(1); //查找键值为1的元素的位置
	ms.erase(iter);	   //删除键值为1的元素
	for (iter = ms.begin(); iter != ms.end(); iter++)
		cout << iter->first << " " << iter->second << endl;
	ms.erase(ms.begin(), ms.end()); //删除全部元素
	cout << ms.size() << endl;
	cout << ms.empty() << endl; // empty()判断map是否为空

	multimap<string, double> mp;					//定义multimap对象，当前无任何元素
	mp.insert(pair<string, double>("Jack", 300.5)); //插入元素
	mp.insert(pair<string, double>("Jack", 306));	//重复插入键值"Jack"
	cout << mp.count("Jack") << endl;				// 2
}

const int STACK_SIZE = 10;
void stackSample()
{
	stack<string> s;
	s.push("aaa"); //入栈
	s.push("bbb");
	if (s.size() < STACK_SIZE) //可限制大小
		s.push("68");
	cout << s.size() << endl; //输出栈内元素个数
	while (!s.empty())		  //当堆栈不为空时
	{
		cout << s.top() << endl; //输出栈顶元素
		s.pop();				 //栈顶元素出栈
	}
}

void queueSample()
{
	queue<int> q;
	q.push(3); //入队
	q.push(5);
	cout << "元素个数为：" << q.size() << endl;
	cout << q.back();  //取队尾元素
	while (!q.empty()) //当队列不为空时
	{
		cout << q.front() << endl; //输出队首元素
		q.pop();				   //出队
	}
}

struct thing
{
	int a;
	char b;
	bool operator<(const thing &rhs) const
	{
		return a < rhs.a;
	}
};

void priorityQueueSample()
{
	//从小到大排列，让小的元素优先出队的基本写法如下。
	priority_queue<int, vector<int>, greater<int>> minq;
	// Default：从大到小排列，让大的元素优先出队的基本写法如下。
	priority_queue<int, vector<int>, less<int>> maxq;
	priority_queue<thing> Q;

	priority_queue<int> q;
	q.push(93); //入队，插入新元素
	q.push(5);
	q.push(12);
	cout << "元素个数为：" << q.size() << endl;
	while (!q.empty()) //当队列不为空时
	{
		cout << q.top() << endl; //取队首元素
		q.pop();				 //出队要先判断是否为空
	}
}

void permSample()
{
	// next_permutation()按照字典序产生排列，并且是从数组中当前的字典序开始依次增大直至到最大字典序；
	// prev_permutation()按照字典序产生排列，并且是从数组中当前的字典序开始依次减小直至到最小字典序。
	int a[] = {3, 5, 6, 7, 9};		   //随机赋值，如果要全排列，值必须由小到大
	while (next_permutation(a, a + 5)) //产生下一排列
		;
	int b[] = {5, 4, 3, 2, 1};		   //随机赋值
	while (prev_permutation(b, b + 5)) //产生上一排列
		;
}

void bitsetSample()
{
	bitset<32> bitvec;				  // 32 bits, all zero
	bool is_set = bitvec.any();		  // false, all bits are zero
	bool is_not_set = bitvec.none();  // true, all bits are zero
	size_t bits_set = bitvec.count(); // returns number of bits that are on
	size_t sz = bitvec.size();		  // returns 32
	// assign 1 to even numbered bits
	for (int index = 0; index != 32; index += 2)
		bitvec[index] = 1;
	// equivalent loop using set operation
	for (int index = 0; index != 32; index += 2)
		bitvec.set(index);
	int i=6;
	if (bitvec.test(i))
		// bitvec[i] is on
		// equivalent test using subscript
		if (bitvec[i])
			;		// bitvec[i] is on
	bitvec.reset(); // set all the bits to 0.
	bitvec.set();	// set all the bits to 1

	// bitvec1 is smaller than the initializer
	bitset<16> bitvec1(0xffff); // bits 0 ... 15 are set to 1
	// bitvec2 same size as initializer
	bitset<32> bitvec2(0xffff);				// bits 0 ... 15 are set to 1; 16 ... 31 are 0
	cout << "bitvec2: " << bitvec2 << endl; // bitvec2: 00000000000000001111111111111111
	// on a 32-bit machine, bits 0 to 31 initialized from 0xffff
	bitset<128> bitvec3(0xffff); // bits 32 through 127 initialized to zero
	unsigned long ulong = bitvec3.to_ulong();
	cout << "ulong = " << ulong << endl;

	string strval("1100");
	bitset<32> bitvec4(strval);
	string str("1111111000000011001101");
	bitset<32> bitvec5(str, 5, 4);			 // 4 bits starting at str[5], 1100
	bitset<32> bitvec6(str, str.size() - 4); // use last 4 characters
}

void stlSample()
{
	int a[10]{7, 4, 5, 23, 2, 73, 41, 52, 28, 60};
	// min(x ,y )：求两个元素的最小值。
	// max(x ,y )：求两个元素的最大值。
	// swap(x ,y )：交换两个元素。
	// find(begin,end,x )：返回指向区间[begin,end)第1个值为x的元素指针。如果没找到，则返回end。
	// count(begin,end,x )：返回指向区间[begin,end)值为x 的元素数量，返回值为整数。
	// reverse(begin,end)：翻转一个序列。
	// random_shuffle(begin,end)：随机打乱一个序列。
	// unique(begin,end)：将连续的相同元素压缩为一个元素，返回去重后的尾指针。不连续的相同元素不会被压缩，因此一般先排序后去重。

	// fill(begin,end,val)：将区间[begin,end)的每个元素都设置为val。与#include<cstring>中的memset不同，memset是按字节填充的。

	// sort(begin,end,compare)：对一个序列排序，参数begin和end表示一个范围，分别为待排序数组的首地址和尾地址；compare表示排序的比较函数，可省略，默认为升序。stable_sort(begin, end, compare) 为稳定排序，即保持相等元素的相对顺序。
	sort(a, a + 10);				 //缺省升序， sort(a,a+10,less<int>());
	sort(a, a + 10, greater<int>()); //降序
									 // equal_to<Type>：等于。
									 // not_equal_to<Type>：不等于。
									 // greater_equal<Type>：大于或等于。
									 // less_equal<Type>：小于或等于。

	// nth_element(begin,begin+k,end,compare)：当省略最后一个参数时，使区间[begin,end)第k小的元素处在第k个位置上，左边元素都小于或等于它，右边元素都大于或等于它，但并不保证其他元素有序。
	// 当最后一个参数为greater<int>()时，该函数使区间[begin,end)第k 大的元素处在第k 个位置上。
	nth_element(a, a + 2, a + 10); // 第2小的数在第2个位置上

	// lower_bound(begin,end,x )/upper_bound(begin,end,x)：两个函数都是利用二分查找的方法，在有序数组[begin,end)中查找第1个满足条件的元素，返回指向该元素的指针。不存在则返回end。
	sort(a, a + 10);						  //缺省升序， sort(a,a+10,less<int>());
	int pos1 = lower_bound(a, a + 10, 7) - a; //返回数组中第一个大于等于7的元素下标
	int pos2 = upper_bound(a, a + 10, 7) - a; //返回数组中第一个大于7的元素下标
	sort(a, a + 10, greater<int>());		  //降序
	int pos3 = lower_bound(a, a + 10, 7) - a; //返回数组中第一个小于等于7的元素下标
	int pos4 = upper_bound(a, a + 10, 7) - a; //返回数组中第一个小于7的元素下标
	// equal_range是C++ STL中的一种二分查找的算法，试图在已排序的[first,last)中寻找value，它返回一对迭代器i和j，
	// 其中i是在不破坏次序的前提下，value可插入的第一个位置（亦即lower_bound），j则是在不破坏次序的前提下，value可插入的最后一个位置（亦即upper_bound），
	// 因此，[i,j)内的每个元素都等同于value，而且[i,j)是[first,last)之中符合此一性质的最大子区间
	
	// next_permutation(begin,end)/pre_permutation(begin,end)：next_permutation()是求按字典序的下一个排列的函数，可以得到全排列。pre_permutation()是求按字典序的上一个排列的函数。
	do
	{
		cout << a[0] << a[1] << a[2] << endl;
	} while (next_permutation(a, a + 3));
}

//链式前向星

int main()
{
	freopen("mid.in", "r", stdin);	 //从文件mid.in里读取数据
	freopen("mid.out", "w", stdout); //程序运行会创建文件mid.out并将结果写入其中
	for (int i = 1; i <= 5; i++)	 // 5组测试数据，所以循环5次
	{
		string F = "sum";
		F += char(i + 48);					   //整数i转为字符i,"0"的ASCII值为48
											   //复制命令，例如i=1时,为"copy sum1.in sum.in"
		string s = "copy " + F + ".in sum.in"; //注意"copy"后有一个空格
		system(s.c_str());					   //执行复制命令
		int time1 = clock();				   //获取程序当前运行的时钟数
		system("sum.exe");					   //运行由源代码事先编译好的sum.exe文件
		int time2 = clock();				   //获取程序运行结束后的时钟数
											   //比较文件命令,例如i=1时,为"fc sum.out sum1.ans";
		string Cmd = "fc sum.out " + F + ".ans";
		if (!system(Cmd.c_str())) //执行比较文件命令
			cout << " 测试点" << i << "通过，用时" << time2 - time1 << "毫秒\n\n";
	}

	srand(time(0));		 // srand()取当前时间作为随机数种子
	int t = rand() % 10; // rand()产生0～32767的随机数，随后对10取余

	char c;
	c = getchar(); //输入字符赋值给c
	putchar(c);	   //输出字符变量c
	char c1, c2;
	c1 = 65;									//此处用数字而不是字符赋值,'A'
	c2 = 66;									//此处用数字而不是字符赋值,'B'
	cout << c1 << "  " << c2 << endl;			//因为c1、c2为字符类型，所以默认输出字符
	cout << int(c1) << "  " << int(c2) << '\n'; // int()表示强制转换为整

	return 0;
}
#include "stdio.h"

typedef struct  _Person1
{
	char *name;//指针就是地址，系统采用的是64位系统，所以占用8字节
	int age;//32位，4字节
	double height;	//64位，8字节	。最终整个结构体所占的总的字节数，要是最大属性所占字节数的倍数，所以总共占用字节24，而不是20.	
}P1;//这是一种组合的写法，typedef是给已有数据类型，定义一个别名。
//上面的代码分开写的话是，struct _Person1{}; typedef struct _Person1 P1;

struct  _Person2
{
	int age;
	double height;		
};
typedef struct _Person2 P2;
int main(int argc, char const *argv[])
{
	P1 p1={0};
	P2 p2={0};
	printf("p1的长度是%d,p2的长度是%d\n",sizeof(P1),sizeof(P2) );
	//p1的长度是24,p2的长度是16,这就是输出结果
	//memset(p,0,long);给一段内存赋值，p是指针，代表内存首地址。0代表要初始化的内容，long代表要初始化的字节数。
	//结构体数组初始化是都可以={0}，这样内存中的内容就都是0了。
	//结构体指针取成员的值，要使用->。
	return 0;
}
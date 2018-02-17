#include "stdio.h"
#include "string.h"
#include "gtk/gtk.h"

int shownumber(int num,int*ge,int*shi,int*bai);
char* mystrlen(char*ptr,int *length);
int ClickOnNumbutton(GtkWidget*widget,int*ptr);
int ClickOnStringbutton(GtkWidget*widget,int data);
int ClickOnComparebutton(GtkWidget*widget,int data);
GtkEntry*numentry;
GtkEntry*entry[3];
GtkEntry*outentry;
GtkEntry*firstentry;
GtkEntry*secondentry;

//指针的应用，函数的址传递，自定义求字符串长度的函数，判断一个字符串是否以另一个字符串为结尾
int main(int argc, char const *argv[])
{
	gtk_init(NULL,NULL);
	GtkWidget*window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window,"destroy",gtk_main_quit,NULL);
	gtk_window_set_title(window,"指针学习");


	GtkGrid*grid=gtk_grid_new();//创建一个网格

	//实现函数的址传递
	GtkLabel*numlabel=gtk_label_new("请输入一个大小在0～999之间的整数:");
	gtk_widget_show(numlabel);
	gtk_grid_attach(grid,numlabel,0,0,2,1);

	numentry=gtk_entry_new();
	gtk_widget_show(numentry);
	gtk_grid_attach(grid,numentry,0,1,1,1);

	GtkButton*numbutton=gtk_button_new_with_label("显示各位数字");
	gtk_widget_show(numbutton);
	gtk_grid_attach(grid,numbutton,1,1,1,1);

	g_signal_connect(numbutton,"clicked",ClickOnNumbutton,0);
	//监听事件，第一个参数，是被监听的控件，第二个参数，是监听的事件，第三个参数，是事件发生后，调用的函数，第四个参数，是给被调用的函数传的指针参数

	GtkLabel*label[3];
	char *value[]={"个位是：","十位是：","百位是："};//定义一个指针数组，即数组里面的内容是指针
	int i;
	for (i = 0; i < 3; ++i)
	{
		label[i]=gtk_label_new(value[i]);
		entry[i]=gtk_entry_new();
		gtk_widget_show(label[i]);
		gtk_widget_show(entry[i]);
		gtk_grid_attach(grid,label[i],0,i+2,1,1);
		gtk_grid_attach(grid,entry[i],1,i+2,1,1);
	}

	//实现自定义求字符串长度
	GtkLabel*stringlabel=gtk_label_new("请输入一个字符串，显示字符串长度");
	gtk_widget_show(stringlabel);
	gtk_grid_attach(grid,stringlabel,0,5,2,1);

	GtkEntry*stringentry=gtk_entry_new();
	gtk_widget_show(stringentry);
	gtk_grid_attach(grid,stringentry,0,6,2,1);

	GtkButton*stringbutton=gtk_button_new_with_label("字符长度为");
	gtk_widget_show(stringbutton);
	gtk_grid_attach(grid,stringbutton,0,7,1,1);

	g_signal_connect(stringbutton,"clicked",ClickOnStringbutton,stringentry);
	//这里最后一个参数是一个int型的，我把指针传给了他，因为指针就是地址，就是一个int型的数字

	outentry=gtk_entry_new();
	gtk_widget_show(outentry);
	gtk_grid_attach(grid,outentry,1,7,1,1);

	//判断一个字符串是否以另一个字符串为结尾
	GtkLabel*doublestringlabel=gtk_label_new("输入两个字符串，判断第二个是否为第一个子串");
	gtk_widget_show(doublestringlabel);
	gtk_grid_attach(grid,doublestringlabel,0,8,2,1);

	GtkLabel*firstlabel=gtk_label_new("第一个字符串");
	gtk_widget_show(firstlabel);
	gtk_grid_attach(grid,firstlabel,0,9,1,1);

	firstentry=gtk_entry_new();
	gtk_widget_show(firstentry);
	gtk_grid_attach(grid,firstentry,1,9,1,1);

	GtkLabel*secondlabel=gtk_label_new("第二个字符串");
	gtk_widget_show(secondlabel);
	gtk_grid_attach(grid,secondlabel,0,10,1,1);

	secondentry=gtk_entry_new();
	gtk_widget_show(secondentry);
	gtk_grid_attach(grid,secondentry,1,10,1,1);

	GtkButton*comparebutton=gtk_button_new_with_label("是否为子串");
	gtk_widget_show(comparebutton);
	gtk_grid_attach(grid,comparebutton,0,11,1,1);

	GtkEntry*compareentry=gtk_entry_new();
	gtk_widget_show(compareentry);
	gtk_grid_attach(grid,compareentry,1,11,1,1);

	g_signal_connect(comparebutton,"clicked",ClickOnComparebutton,compareentry);

	gtk_container_add(window,grid);
	gtk_widget_show(grid);
	gtk_widget_show(window);
	gtk_main();

	return 0;
}

//求一个三位数的个位，十位，百位数字
int shownumber(int num,int*ge,int*shi,int*bai)
{
	*ge=num%10;
	*shi=(num/10)%10;
	*bai=num/100;
	return 0;
}

int ClickOnNumbutton(GtkWidget*widget,int*ptr)//这个widget控件默认是调用这个函数的控件，不需要显示传值
{
	int num,i;//,ge,shi,bai;
	int figure[3];
	char str[3]={};//声明并初始化一个char数组，这样数组中的内容被初始化为0
	num=atoi(gtk_entry_get_text(numentry));
	if (num>999||num<0)
	{
		gtk_entry_set_text(numentry,"请按要求输入数字");
	}
	else
	{
		shownumber(num,figure,&(figure[1]),&(figure[2]));
		for (i = 0; i < 3; ++i)
		{
			sprintf(&(str[i]),"%d",figure[i]);//C语言中的类型转换函数，把int类型转换成字符串类型。sprintf()第一个参数是一个字符串首地址，或者字符串指针（指针即地址）
			gtk_entry_set_text(entry[i],&(str[i]));//gtk_entry_set_text()函数第一个参数，代表要操作的控件，第二个参数，代表一个字符串的地址，或者直接是一个字符串
		}
	}
	return 0;
}

//求字符串的长度，单独封装成一个函数，方便后面的重复调用
char* mystrlen(char*ptr,int *length)
{
	while(*ptr!='\0')
	{
		ptr++;
		(*length)++;
	}
	return ptr;
}

int ClickOnStringbutton(GtkWidget*widget,int data)
{
	char *ptr=gtk_entry_get_text(data);//data是一个entry型的指针，但其本质上就是一个int型的数字
	//C语言中并没有字符串，实质上就是一个以'\0'结尾的字符数组，求字符串的长度，就是求字符数组的长度
	//数组名就是数组的首地址，而指针就是地址，所以指向数组首地址的指针，和数组名是等价的
	int length=0;
	mystrlen(ptr,&length);
	char numstr[]={};
	sprintf(numstr,"%d",length);
	gtk_entry_set_text(outentry,numstr);
	return 0;
}

int ClickOnComparebutton(GtkWidget*widget,int data)
{
	char *firstptr=gtk_entry_get_text(firstentry);
	char *secondptr=gtk_entry_get_text(secondentry);
	int firstlength=0;
	int secondlength=0;
	char*firstaddptr=mystrlen(firstptr,&firstlength);
	char*secondaddptr=mystrlen(secondptr,&secondlength);
	if (secondlength>firstlength)
	{
		gtk_entry_set_text(data,"不是");
	}
	else
	{
		int i;
		for (i = 0; i <=secondlength; ++i)//少了一个等号，导致字符串长度为1的时候，无法判断。因为字符串归根结底是以\0结尾的字符数组，所以第一层循环，两个字符是相等的，因为都是\0
		{
			char a=*firstaddptr;
			char b=*secondaddptr;
			if (a!=b)
			{
				gtk_entry_set_text(data,"不是");
				return 0;//之前一直显示"是",是因为C语言程序是顺序执行的，没有这个return就一定会执行下面的"是"
			}
			firstaddptr--;
			secondaddptr--;
		}
		gtk_entry_set_text(data,"是");
	}
	return 0;
}
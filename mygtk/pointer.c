#include "stdio.h"
#include "string.h"
#include "gtk/gtk.h"

char* mystrlen(char*ptr,int *length);
int ClickOnComparebutton(GtkWidget*widget,int data);
GtkEntry*firstentry;
GtkEntry*secondentry;

//指针的应用，判断一个字符串是否以另一个字符串为结尾
int main(int argc, char const *argv[])
{
	gtk_init(NULL,NULL);
	GtkWidget*window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window,"destroy",gtk_main_quit,NULL);
	gtk_window_set_title(window,"指针学习");

	GtkGrid*grid=gtk_grid_new();//创建一个网格

	//判断一个字符串是否以另一个字符串为结尾
	GtkLabel*doublestringlabel=gtk_label_new("输入两个字符串，判断第二个是否为第一个子串");
	gtk_widget_show(doublestringlabel);
	gtk_grid_attach(grid,doublestringlabel,0,0,2,1);

	GtkLabel*firstlabel=gtk_label_new("第一个字符串");
	gtk_widget_show(firstlabel);
	gtk_grid_attach(grid,firstlabel,0,1,1,1);

	firstentry=gtk_entry_new();
	gtk_widget_show(firstentry);
	gtk_grid_attach(grid,firstentry,1,1,1,1);

	GtkLabel*secondlabel=gtk_label_new("第二个字符串");
	gtk_widget_show(secondlabel);
	gtk_grid_attach(grid,secondlabel,0,2,1,1);

	secondentry=gtk_entry_new();
	gtk_widget_show(secondentry);
	gtk_grid_attach(grid,secondentry,1,2,1,1);

	GtkButton*comparebutton=gtk_button_new_with_label("是否为子串");
	gtk_widget_show(comparebutton);
	gtk_grid_attach(grid,comparebutton,0,3,1,1);

	GtkEntry*compareentry=gtk_entry_new();
	gtk_widget_show(compareentry);
	gtk_grid_attach(grid,compareentry,1,3,1,1);

	g_signal_connect(comparebutton,"clicked",ClickOnComparebutton,compareentry);

	gtk_container_add(window,grid);
	gtk_widget_show(grid);
	gtk_widget_show(window);
	gtk_main();

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
		for (i = 0; i <=secondlength; ++i)
		{
			char a=*firstaddptr;
			char b=*secondaddptr;
			firstaddptr--;
			secondaddptr--;
			printf("%c\n",a);//printf("%s",a);因为a是字符，应该用%c，%s使用来输出字符串的，索引会造成core dump错误，内存访问越界错误
			printf("%c\n",b);
			if (a!=b)
			{
				gtk_entry_set_text(data,"不是");
				return 0;
			}
			printf("%d\n",firstaddptr);
			printf("%d\n",secondaddptr);
		}
		gtk_entry_set_text(data,"是");
	}
	return 0;
}
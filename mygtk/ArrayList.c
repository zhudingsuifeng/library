#include "stdio.h"
#include "gtk/gtk.h"
#include "string.h"
//数组和指针
//新建一个长度为5的数组，输出数组中每个数字的地址，使用网格布局

int inputnum;//用来传输当前输入的数字
static int order;//静态变量具有记忆性，在下次访问的时候，变量的值仍保持上一次的值。用来表示当前是输入的第几个数字
//static int flag;现在就还显示的时候有问题
int array[5];
GtkGrid*grid;
GtkEntry*inputentry;
GtkButton*outputbutton;
GtkLabel*addresslabel[5];//创建一个label数组
GtkEntry*addressentry[5];//创建一个entry数组
int inputbuttonOnclick(GtkWidget*widget,int data);
int outputbuttonOnclick(GtkWidget*widget,int data);

int main(int argc, char const *argv[])
{
	gtk_init(NULL,NULL);
	GtkWidget*window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window,"destroy",gtk_main_quit,0);
	gtk_window_set_title(window,"数组和指针");

	//GtkGrid*grid=gtk_grid_new();//新建一个网格
	grid=gtk_grid_new();

	GtkLabel*instruction=gtk_label_new("请依次输入五个数字，并且每输入一个数字，点击一次输入按钮");
	gtk_grid_attach(grid,instruction,0,0,3,1);
	gtk_widget_show(instruction);

	//GtkEntry*inputentry=gtk_entry_new();
	inputentry=gtk_entry_new();
	gtk_grid_attach(grid,inputentry,0,1,1,1);
	//void gtk_grid_attach (GtkGrid *grid,GtkWidget *child,int left,int top,int width,int height);
	//left到窗体左边的距离,top到窗体顶部的距离,width控件的宽度，height控件的高度
	gtk_widget_show(inputentry);
	order=0;//int *order;这样是不对的，不能声明一个未知的指针，指针一旦声明，必须初始化

	GtkButton*inputbutton=gtk_button_new_with_label("输入第1个数");
	gtk_grid_attach(grid,inputbutton,1,1,1,1);
	gtk_widget_show(inputbutton);
	g_signal_connect(inputbutton,"clicked",inputbuttonOnclick,order);

	outputbutton=gtk_button_new_with_label("依次输出数组元素地址");
	gtk_grid_attach(grid,outputbutton,2,1,1,1);
	gtk_widget_show(outputbutton);
	g_signal_connect(outputbutton,"clicked",outputbuttonOnclick,0);

	int i;
	for (i = 0; i < 5; ++i)
	{
		char address[37];

		sprintf(address,"数组第%d个元素的值和地址是",i+1);
		addresslabel[i]=gtk_label_new(address);
		gtk_grid_attach(grid,addresslabel[i],0,i+2,1,1);

		addressentry[i]=gtk_entry_new();
		gtk_grid_attach(grid,addressentry[i],1,i+2,2,1);
	}

	gtk_widget_set_sensitive(outputbutton,FALSE);//在没有给数组赋值之前，要求按钮不能点击，不能输出数组元素的内存地址
	gtk_widget_show(grid);
	gtk_container_add(window,grid);
	gtk_widget_show(window);
	gtk_main();
	return 0;
}

//自定义用来接受输入数据的按钮点击函数,我们主要是为了输出数组中每个元素在内存中的地址
int inputbuttonOnclick(GtkWidget*widget,int data)
{
	int temp=atoi(gtk_entry_get_text(inputentry)); 	
	if (temp>2147483647||temp<0)
	{
		gtk_entry_set_text(inputentry,"请重新输入正确的数字");
		order=0;
	}
	else
	{
		array[order]=temp;
		order++;
		gtk_entry_set_text(inputentry,"");
	}
	char str[16];
	sprintf(str,"输入第%d个数",order+1);//和printf函数相似，用来合并字符串
	gtk_button_set_label(widget,str);
	if (order>4)
	{
		gtk_entry_set_text(inputentry,"输入已经结束");
		gtk_widget_set_sensitive(widget,FALSE);
	}
	gtk_widget_set_sensitive(outputbutton,TRUE);
}

//点击按钮，输出数组元素在内存中的地址
//之前存在多次点击按钮，字体变黑的情况，其实是因为每点击一次，就重新new控件，在显示出来，多个同样的控件叠加在一起，才显得字体加黑了。
//把生成控件的函数放在主函数中，这个问题就解决了。
int outputbuttonOnclick(GtkWidget*widget,int data)
{
	int i;
	for (i = 0; i < order; ++i)
	{
		char location[23];
		gtk_widget_show(addresslabel[i]);//new一个控件要通过show才能显示出来，在main中new控件，在事件中显示控件，避免了多次生成控件。

		sprintf(location,"%d---%d",array[i],&(array[i]));
		gtk_entry_set_text(addressentry[i],location);
		gtk_widget_show(addressentry[i]);
	}
	gtk_widget_set_sensitive(outputbutton,FALSE);
}
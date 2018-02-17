#include "stdio.h"
#include "gtk/gtk.h"
#include "string.h"

GtkWindow *window;
int btn3onclicked(GtkWidget*widget,int data);

int main(int argc, char const *argv[])
{
	/* code */
	char str[]="数组第1个元素的地址是";
	printf("%d\n",strlen(str) );//输出的结果是16，每一个汉字占三个字节
	printf("%d\n",sizeof(str) );

	gtk_init(NULL,NULL);
	//GtkWindow *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(window,"hello,world");
	g_signal_connect(window,"destroy",gtk_main_quit,NULL);
	GtkGrid *grid1=gtk_grid_new();//创建一个网格
	GtkButton *btn1=gtk_button_new();//创建一个按钮
	gtk_button_set_label(btn1,"btn1");//给按钮显示一个名字
	gtk_grid_attach(grid1,btn1,0,0,1,1);//把按钮添加到网格中
	gtk_widget_show(btn1);//显示按钮

	GtkButton *btn2=gtk_button_new();
	gtk_button_set_label(btn2,"btn2");
	gtk_grid_attach(grid1,btn2,1,0,1,1);
	gtk_widget_show(btn2);

	GtkButton *btn3=gtk_button_new();
	gtk_button_set_label(btn3,"改变标题");
	gtk_grid_attach(grid1,btn3,0,1,2,2);
	gtk_widget_show(btn3);

	g_signal_connect(btn3,"clicked",btn3onclicked,NULL);

	gtk_widget_show(grid1);//显示网格
	gtk_container_add(window,grid1);//把网格添加到窗口中
	gtk_window_set_position(window,GTK_WIN_POS_CENTER_ALWAYS);//现实在屏幕正中间
	gtk_widget_show(window);//显示窗口
	gtk_main();
	return 0;
}

/*
g_signal_connect(btn3,"clicked",btn3onclicked,NULL);其中事件"clicked"对应int btn3onclicked(GtkWidget*widget,int data){}这种函数处理
g_signal_connect(btn3,"clicked-event",btn3onclicked,NULL);其中事件"clicked-event"对应int onEventCallBack(GtkWidget*widget,Gtkevent*event,int data){}这样的函数来处理
*/
int btn3onclicked(GtkWidget*widget,int data)
{
	gtk_window_set_title(window,"注定随风");

}
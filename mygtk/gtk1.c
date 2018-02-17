#include "stdio.h"
#include "gtk/gtk.h"
int main(int argc, char const *argv[])
{
	/* code */
	gtk_init(NULL,NULL);//初始化
	GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	//新建一个窗口
	gtk_window_set_title(window,"hello,world!");//设置窗口标题
	gtk_window_set_position(window,GTK_WIN_POS_CENTER_ALWAYS);
	//设置窗口显示位置，始终居中
	g_signal_connect(window,"destroy",gtk_main_quit,NULL);
	//信号，监听窗口
	//GtkLavel *lavel1=gtk_new_lavel("注定随风");//新建一个标签
	GtkEntry *entry1=gtk_entry_new();//新建一个文本框
	gtk_container_add(window,entry1);//把一个控件添加到容器中
	gtk_widget_show(entry1);//显示文本框
	gtk_widget_show(window);//显示一个控件
	gtk_main();//有进程阻塞的作用，用来处理事件（等待事件的发生），这里没做任何处理
	return 0;
}
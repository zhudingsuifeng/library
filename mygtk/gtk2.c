#include "stdio.h"
#include "gtk/gtk.h"

int main(int argc, char const *argv[])
{
	/* code */
	gtk_init(NULL,NULL);//初始化
	GtkWindow*window=gtk_window_new(GTK_WINDOW_TOPLEVEL);//新建一个窗口
	g_signal_connect(window,"destroy",gtk_main_quit,NULL);//信号，监听控件的事件
	
	GtkBox*box1=gtk_box_new(GTK_ORIENTATION_VERTICAL,0);//新建一个容器

	GtkButton*btn1=gtk_button_new();//新建一个按钮
	gtk_button_set_label(btn1,"点我");//设置按钮上的文字内容
	gtk_box_pack_start(box1,btn1,FALSE,FALSE,0);

	GtkButton*btn2=gtk_button_new();//新建一个按钮
	gtk_button_set_label(btn2,"点我呀");//设置按钮标签
	gtk_box_pack_start(box1,btn2,FALSE,FALSE,0);//把按钮添加到box中

	GtkEntry *entry1=gtk_entry_new();//新建一个文本框
	gtk_entry_set_text(entry1,"注定随风");//给文本框设置一个默认的值
	gtk_box_pack_start(box1,entry1,FALSE,FALSE,0);//把文本框添加到box中

	gtk_widget_show(entry1);
	gtk_widget_show(btn1);//显示按钮1
	gtk_widget_show(btn2);//显示按钮2
	gtk_widget_show(box1);//显示容器1
	gtk_container_add(window,box1);//把容器加入到窗口中
	gtk_widget_show(window);//显示窗口
	gtk_main();
	return 0;
}
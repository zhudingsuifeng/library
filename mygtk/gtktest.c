#include "stdio.h"
#include "gtk/gtk.h"

int main(int argc, char const *argv[])
{
	/* code */
	gtk_init(NULL,NULL);//
	GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(window,"hello,world!");
	g_signal_connect(window,"destroy",gtk_main_quit,NULL);
	gtk_window_set_position(window,GTK_WIN_POS_CENTER_ALWAYS);//现实在屏幕正中间
	gtk_widget_show(window);//显示一个控件
	//GtkEntry *entry1=gtk_entry_new();
	//gtk_widget_show(entry1);//window要show才能显示。其他控件要放到Container（也要show）中才能显示
	//gtk_container_add(window,entry1);//不能忘了添加到容器中
	GtkButton *btn1=gtk_button_new();
	gtk_button_set_label(btn1,"点击我");
	gtk_container_add(window,btn1);
	gtk_widget_show(btn1);
	gtk_main();
	return 0;
}
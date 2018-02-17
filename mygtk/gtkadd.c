#include "stdio.h"
#include "string.h"
#include "gtk/gtk.h"

GtkEntry *entrynumfirst;
GtkEntry *entrynumsecond;
GtkEntry *entryaddresult;

int main(int argc, char const *argv[])
{
	/* 写一个带窗体的加法程序 */
	gtk_init(NULL,NULL);//初始化gtk
	//int addprintf(GtkEntry *entryaddresult,int numfirst,int numsecond);//函数声明
	int ButtonaddresultonClicked(GtkWidget *widget,int data);
	GtkWindow*window=gtk_window_new(GTK_WINDOW_TOPLEVEL);//新建一个顶级窗口
	gtk_window_set_title(window,"加法器");
	g_signal_connect(window,"destroy",gtk_main_quit,NULL);//对窗口监听事件

	GtkBox *boxadd=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);//新建一个横向排列box容器

	//GtkEntry *entrynumfirst=gtk_entry_new();//新建一个文本框
	entrynumfirst=gtk_entry_new();
	gtk_entry_set_text(entrynumfirst,"请输入一个数字");//给文本框设置一个默认内容
	gtk_box_pack_start(boxadd,entrynumfirst,FALSE,FALSE,0);//把文本框添加到box容器中

	GtkWidget *labeladd=gtk_label_new("+");//新建一个label标签
	gtk_box_pack_start(boxadd,labeladd,FALSE,FALSE,0);//把标签添加到box容器中

	//GtkEntry *entrynumsecond=gtk_entry_new();
	entrynumsecond=gtk_entry_new();
	gtk_entry_set_text(entrynumsecond,"请输入另一个数字");
	gtk_box_pack_start(boxadd,entrynumsecond,FALSE,FALSE,0);

	GtkButton *buttonaddresult=gtk_button_new_with_label("=");
	gtk_box_pack_start(boxadd,buttonaddresult,FALSE,FALSE,0);

	//GtkEntry *entryaddresult=gtk_entry_new();
	entryaddresult=gtk_entry_new();
	gtk_entry_set_text(entryaddresult,"得出结果");
	gtk_box_pack_start(boxadd,entryaddresult,FALSE,FALSE,0);

	//设置按钮点击事件
	g_signal_connect(buttonaddresult,"clicked",ButtonaddresultonClicked,NULL);
	
	//窗体中的任何控件都需要show显示才能看得见
	gtk_widget_show(entrynumfirst);//显示文本框
	gtk_widget_show(labeladd);//显示标签
	gtk_widget_show(entrynumsecond);
	gtk_widget_show(buttonaddresult);//显示按钮
	gtk_widget_show(entryaddresult);
	gtk_widget_show(boxadd);//显示box容器
	gtk_container_add(window,boxadd);//在窗体中添加box容器
	gtk_widget_show(window);//显示窗体
	gtk_main();
	return 0;
}

//定义事件处理函数
int ButtonaddresultonClicked(GtkWidget *widget,int data)
{
	//在进行计算之前，应该对输入的合法性进行判断
	int numfirst,numsecond;
	numfirst=atoi(gtk_entry_get_text(entrynumfirst));
	numsecond=atoi(gtk_entry_get_text(entrynumsecond));
	if (numfirst>2147483647||numfirst<0)
	{
		gtk_entry_set_text(entrynumfirst,"请正确的输入数字");
	}
	if (numsecond>2147483647||numsecond<0)
	{
		gtk_entry_set_text(entrynumsecond,"请正确的输入数字");
	}
	else
	{
		if ((numfirst+numsecond)>2147483647||(numfirst+numsecond)<0)
		{
			gtk_entry_set_text(entryaddresult,"超出范围");
		}
		else
		{
			int addresult=numfirst+numsecond;
			char str[10];
			sprintf(str,"%d",addresult);//把int型数据转换为字符型数据
			gtk_entry_set_text(entryaddresult,str);
		}		
	}
	//int addresult=numfirst+numsecond;
	//printf("%d\n", atoi(gtk_entry_get_text(entrynumfirst)));
	//atoi();把字符型数据转换为int类型数据
	return 0;
}

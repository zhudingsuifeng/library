## shell
#### 一些shell使用的技巧。
#### Using mailx to send email.
- mail -s "test" 1002557401@qq.com #-s is the title of email,press enter to input context,and Ctrl+d input complete. 
- echo "email test"|mail -s "test" 1002557401@qq.com  #using pipe to send email, "email test" is the context.
- mail -s "test" 1002557401@qq.com <test.sh    #import context from file.
- echo "email test"|mail -s "test" -a test.sh 1002557401@qq.com #add the annex.
- echo "email test"|mail -s "test" 1002557401@qq.com,m18817273906@163.com #send email to multiple mailboxes.
#### Some error to qq mailbox.
- Error:550 mail content denied will be return when you send email to qq mailbox but 163 mailbox will not.
- Error reason:the mail has been identified as spam.
- Solution:在qq邮箱"设置"-->"反垃圾"-->"设置邮件地址白名单".
- echo "email test"|mail -s "test" 1002557401@qq.com #success.
#### if[ 符号 ] 意义
- -eq #等于
- -ne #不等于
- -gt #大于
- -lt #小于
- ge  #大于等于
- le  #小于等于
#### shell中常用变量的含义
- $$  shell本身的PID
- $!  shell最后运行的后台process的PID
- $?  最后运行的命令的结束代码(返回值),想要获取命令的$?值，必须紧跟程序，中间如果还有其他代码，就获取的是中间代码的$?值了。
- $-  使用set命令设定的Flag一览
- $\*  所有参数列表 
- $@  所有参数列表
- $#  添加到shell的参数个数
- $0  shell本身的文件名
- $1~n添加到shell的各参数值。
#### Linux shell 脚本中调用另一个shell(exec,source,fork)
- 在运行shell脚本的时候，有三种方式来调用外部的脚本，exec(exec script.sh),source(source script.sh),fork(./script.sh)
1. exec(exec script.sh):
- 使用exec来调用脚本，被执行的脚本会继续当前shell的环境变量。但事实上exec产生了新的进程，他会把主shell的进程资源占用并替换脚本内容，继承了原主shell的PID号，即原主shell剩下的内容不会执行。
2. source(source script.sh):
- 使用source或者"."来调用外部脚本，不会产生新的进程，继承当前shell环境变量，而且被调用的脚本运行结束后，它拥有的环境变量和声明变量会被当前shell保留，类似将调用脚本的内容复制过来直接执行。执行完毕后，原主shell继续运行。
3. fork
- 直接运行脚本，会以当前shell为父进程，产生新的进程，并且继承主脚本的环境变量和声明变量。执行完毕后，主脚本不会保留其环境变量和声明变量。 

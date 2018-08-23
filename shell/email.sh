#!/usr/bin/env bash

#execute and send email
#`ps -ef|grep "$1"|grep -v "grep"`
./$1 2>../temp/error
if [ $? -eq 0 ]
then
    email="Program is executed successfully."
#$()get process result as a parameter,2>&1 redirect error output same as the standard output.
else
    email=`cat /home/fly/mygit/shell/temp/error`
fi
#echo "$email"
echo "$email"|mail -s "Program results" 1002557401@qq.com,m18817273906@163.com
echo "success"

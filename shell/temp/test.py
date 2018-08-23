#!/usr/bin/env python
#encoding=utf-8

import time

for i in range(10):
    time.sleep(1)
    print(i)
    if i == 6:
	#raise ValueError
	break

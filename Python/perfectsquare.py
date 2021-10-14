# -*- coding: utf-8 -*-
"""
Created on Tue Dec 17 12:33:32 2019

@author: subho
"""

import math
def isPerfectSquare(x):
	num=math.sqrt(x)
	return((num - math.floor(num))==0)


x=float(input("Enter Number to check:"))
if (isPerfectSquare(x)):
	print("Yes")
else:
	print("No")
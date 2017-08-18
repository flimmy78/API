/*************************************************************************
	> File Name: test.c
	> Author: llb
	> Mail: llb1008x@126.com 
	> Created Time: 2017年08月16日 星期三 16时30分00秒
	
	
题目：1
卡拉兹(Callatz)猜想：

对任何一个自然数n，如果它是偶数，那么把它砍掉一半；如果它是奇数，那么把(3n+1)砍掉一半。这样一直反复砍下去，最后一定在某一步得到n=1。卡拉兹在1950年的世界数学家大会上公布了这个猜想，传说当时耶鲁大学师生齐动员，拼命想证明这个貌似很傻很天真的命题，结果闹得学生们无心学业，一心只证(3n+1)，以至于有人说这是一个阴谋，卡拉兹是在蓄意延缓美国数学界教学与科研的进展……

我们今天的题目不是证明卡拉兹猜想，而是对给定的任一不超过1000的正整数n，简单地数一下，需要多少步（砍几下）才能得到n=1？

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。

输出格式：输出从n计算到1需要的步数。
输入样例：

3

输出样例：

5

	
 ************************************************************************/

#include <stdio.h>

int main()
{
	int num,i,cout=0;
	
	//printf("请输入数据：");
	scanf("%d",&num);
	
	if(num>1000){
	
		printf("error\n");
		return -1;
	}
	
	while(num!=1){
		
		//偶数
		if(num%2==0){
			num=num/2;
		}//奇数
		else {
			num= (3*num+1)/2;
		}
	
		cout++;
	}
	printf("%d\n",cout);

	return 0;
}


#include <stdio.h>



int cowNum(int year){

	    int n =0;

		    int sumCow = 1;  //奶牛总数

			for(n = 1; n <= year; n++){

				        if(n >= 4){  //4年以后奶牛数量开始增多
						
						            if((year - n) > 3){  //第2个4年开始后产的奶牛开始生新奶牛
									
									                sumCow += cowNum(year - n);
									
									} else {

										                sumCow++;

														            
									}
						
						        }

						    
			}

			    return sumCow;    //返回奶牛总数


}

int main(int argc, const char * argv[]) {

	    int year =0;
while(1)
{
		    printf("Please input require years:\n");

			    scanf ("%d", &year);  //输入年数

				    printf("%d年后,会有%d头奶牛.\n", year, cowNum(year));  //输出结果


}
					    return 0;


}

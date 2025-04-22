#include "Timer.h"
#include <windows.h>
#include <stdio.h>
#include <time.h>


	int main()
	{
		clock_t start = clock(); 

		for (; ;)
		{
			clock_t end = clock();  
			double time = (double)(end - start) / CLOCKS_PER_SEC; 
			printf("경과 시간 : %.3f\n", time); 

			system("clear");
		}
		
	}
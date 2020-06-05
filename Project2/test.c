#include<stdio.h>
#include<time.h>
	
	int main(void) {
		struct tm*ptr;
		time_t lt;
		lt = time(NULL);
		ptr = localtime(<);
	       printf("First Name: Grant\nLast Name: Turner\nTime+Date: %s\n", asctime(ptr));
		return 0;
}

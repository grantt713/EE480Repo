#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const int IOs[] = {25, 12, 16, 20, 21};
#define GPIO25_PATH "/sys/class/gpio/gpio25/"
#define GPIO12_PATH "/sys/class/gpio/gpio12/"
#define GPIO16_PATH "/sys/class/gpio/gpio16/"
#define GPIO20_PATH "/sys/class/gpio/gpio20/"
#define GPIO21_PATH "/sys/class/gpio/gpio21/"
#define GPIO_SYSFS "/sys/class/gpio/"

// IOs being used from left bit to right bit 25, 12, 16, 20, 21

void writeGPIO(char filename[], char value[]){
   FILE* fp;                           // create a file pointer fp
   fp = fopen(filename, "w+");         // open file for writing
   fprintf(fp, "%s", value);           // send the value to the file
   fclose(fp);                         // close the file using fp
}

//void setup(

int main(){
	//run calculation functions here to store binaries
	int num=1, rem, decnum;
	int binStorage[32][5];
	int row=0, column=0;
	for(row=0; row<=31; row++){
		for(column=0; column<=4; column++){
			binStorage[row][column]=0;
		}
	}
	row=1;
	column=4;
	for(row=1; row <= 31; row++){
		num=row;
		while(num!=0){
			rem=num%2;
			num=num/2;
			binStorage[row][column]=rem;
			column=column-1;
		}
		column=4;		
	}
/*	
	for(row=0; row<=31; row++){
		for(column=0; column<=4; column++){
			printf("%d", binStorage[row][column]);
		}
		printf("\n");
	}
*/
	
	 // writeGPIO(GPIO_SYSFS "export", GPIO_Number);
     // usleep(100000);                  // sleep for 100ms
     // writeGPIO(Path "direction", "out");
	
	
	printf("Please select a run command from:\n");
	printf("SeqCount, SweepLeft, SweepRight, ContSweep, Translate\n");
	char *mode;
	scanf("%s", mode);
	
	printf("%s", mode);
	//if(strcmp(mode,"SeqCount")==0){
	//	printf("Success");
	//}
	
	
	
	
	
}

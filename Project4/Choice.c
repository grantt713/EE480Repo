#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// IO vals in an array I can better keep track of my bit to LED order
const int IOs[] = {25, 12, 16, 20, 21};	
#define GPIO25_PATH "/sys/class/gpio/gpio25/" 
#define GPIO12_PATH "/sys/class/gpio/gpio12/"
#define GPIO16_PATH "/sys/class/gpio/gpio16/"
#define GPIO20_PATH "/sys/class/gpio/gpio20/"
#define GPIO21_PATH "/sys/class/gpio/gpio21/"
#define GPIO_SYSFS "/sys/class/gpio/"


// function to write to GPIO when giving "value" a string
void writeGPIO(char filename[], char value[]){
   FILE* fp;                           // create a file pointer fp
   fp = fopen(filename, "w+");         // open file for writing
   fprintf(fp, "%s", value);           // send the value to the file
   fclose(fp);                         // close the file using fp
}

// function to write to GPIO when giving "value" an int
void writeGPIOi(char filename[], int value){
   FILE* fp;                           // create a file pointer fp
   fp = fopen(filename, "w+");         // open file for writing
   fprintf(fp, "%d", value);           // send the value to the file
   fclose(fp);                         // close the file using fp
}

// function to set up all GPIO pins
void Setup(){
	writeGPIOi(GPIO_SYSFS "export", IOs[0]);
	writeGPIOi(GPIO_SYSFS "export", IOs[1]);
	writeGPIOi(GPIO_SYSFS "export", IOs[2]);
	writeGPIOi(GPIO_SYSFS "export", IOs[3]);
	writeGPIOi(GPIO_SYSFS "export", IOs[4]);
    usleep(100000);                  // sleep for 100ms
	writeGPIO(GPIO25_PATH "direction", "out");
	writeGPIO(GPIO12_PATH "direction", "out");
	writeGPIO(GPIO16_PATH "direction", "out");
	writeGPIO(GPIO20_PATH "direction", "out");
	writeGPIO(GPIO21_PATH "direction", "out");
}

// function to properly close down all GPIO pins
void Close(){
	writeGPIOi(GPIO_SYSFS "unexport", IOs[0]);
	writeGPIOi(GPIO_SYSFS "unexport", IOs[1]);
	writeGPIOi(GPIO_SYSFS "unexport", IOs[2]);
	writeGPIOi(GPIO_SYSFS "unexport", IOs[3]);
	writeGPIOi(GPIO_SYSFS "unexport", IOs[4]);
}


//**************** Start Main Function *************************
int main(){
	
	int num=1, rem;
	int binStorage[32][5]; // 0-31 binaries will be stored in 2D array
	
	// first fill in all potential gaps by filling whole array with 0's
	int row=0, column=0;
	for(row=0; row<=31; row++){
		for(column=0; column<=4; column++){
			binStorage[row][column]=0;
		}
	}
	
	row=1;
	column=4;
// main FOR loop traverses each row representing a new dec to bin number
	for(row=1; row <= 31; row++){	
		num=row;
// WHILE loop calculates one bit at a time and stores right to left to keep leading 0;s
		while(num!=0){ 	
			rem=num%2;
			num=num/2;
			binStorage[row][column]=rem;
			column=column-1;
		}
		column=4;		
	}

	Setup();	// setup all needed GPIOs before receiving commands

		// ask and receive input
	printf("Please select a run command from:\n");
	printf("SeqCount, SweepLeft, SweepRight, ContSweep, Translate\n");
	char mode[20];
	scanf("%s", mode);
	
	if(strcmp(mode,"SeqCount")==0){	// conditional to check for string
		printf("Counting 0-31 in binary.\n");
// FOR loop traverses each binary number, each bit alway represented by same LED
		for(row=0; row<=31; row++){
			writeGPIOi(GPIO25_PATH "value", binStorage[row][0]);
			writeGPIOi(GPIO12_PATH "value", binStorage[row][1]);
			writeGPIOi(GPIO16_PATH "value", binStorage[row][2]);
			writeGPIOi(GPIO20_PATH "value", binStorage[row][3]);
			writeGPIOi(GPIO21_PATH "value", binStorage[row][4]);
			usleep(1000*1000);
		}
	}
		
	else if(strcmp(mode,"off")==0){	// conditional to check for string
		writeGPIOi(GPIO25_PATH "value", 0);
		writeGPIOi(GPIO12_PATH "value", 0);
		writeGPIOi(GPIO16_PATH "value", 0);
		writeGPIOi(GPIO20_PATH "value", 0);
		writeGPIOi(GPIO21_PATH "value", 0);
	}
	
	else if(strcmp(mode,"on")==0){	// conditional to check for string
		writeGPIOi(GPIO25_PATH "value", 1);
		writeGPIOi(GPIO12_PATH "value", 1);
		writeGPIOi(GPIO16_PATH "value", 1);
		writeGPIOi(GPIO20_PATH "value", 1);
		writeGPIOi(GPIO21_PATH "value", 1);
		usleep(3000*1000);
	}
	
	else if(strcmp(mode,"ContSweep")==0){	// conditional to check for string
		printf("The LEDs will now sweep left to right then right to left 3x.\n");
		for(num=0;num<=3;num++){
			writeGPIOi(GPIO25_PATH "value", 1);
			usleep(500*1000);
			writeGPIOi(GPIO25_PATH "value", 0);
			writeGPIOi(GPIO12_PATH "value", 1);
			usleep(500*1000);
			writeGPIOi(GPIO12_PATH "value", 0);
			writeGPIOi(GPIO16_PATH "value", 1);
			usleep(500*1000);
			writeGPIOi(GPIO16_PATH "value", 0);
			writeGPIOi(GPIO20_PATH "value", 1);
			usleep(500*1000);
			writeGPIOi(GPIO20_PATH "value", 0);
			writeGPIOi(GPIO21_PATH "value", 1);
			usleep(500*1000);
			writeGPIOi(GPIO21_PATH "value", 1);
			usleep(500*1000);
			writeGPIOi(GPIO20_PATH "value", 1);
			writeGPIOi(GPIO21_PATH "value", 0);
			usleep(500*1000);
			writeGPIOi(GPIO16_PATH "value", 1);
			writeGPIOi(GPIO20_PATH "value", 0);
			usleep(500*1000);
			writeGPIOi(GPIO12_PATH "value", 1);
			writeGPIOi(GPIO16_PATH "value", 0);
			usleep(500*1000);
			writeGPIOi(GPIO25_PATH "value", 1);
			writeGPIOi(GPIO12_PATH "value", 0);
			usleep(500*1000);
		}
	}
	
	else if(strcmp(mode,"SweepLeft")==0){	// conditional to check for string
		printf("The LEDs will now sweep right to left 3x.\n");
		for(num=0;num<=3;num++){
			writeGPIOi(GPIO21_PATH "value", 1);
			usleep(500*1000);
			writeGPIOi(GPIO20_PATH "value", 1);
			writeGPIOi(GPIO21_PATH "value", 0);
			usleep(500*1000);
			writeGPIOi(GPIO16_PATH "value", 1);
			writeGPIOi(GPIO20_PATH "value", 0);
			usleep(500*1000);
			writeGPIOi(GPIO12_PATH "value", 1);
			writeGPIOi(GPIO16_PATH "value", 0);
			usleep(500*1000);
			writeGPIOi(GPIO25_PATH "value", 1);
			writeGPIOi(GPIO12_PATH "value", 0);
			usleep(500*1000);
			writeGPIOi(GPIO25_PATH "value", 0);
		}
	}
	
	else if(strcmp(mode,"SweepRight")==0){	// conditional to check for string
		printf("The LEDs will now sweep left to right 3x.\n");
		for(num=0; num<=3; num++){
			writeGPIOi(GPIO25_PATH "value", 1);
			usleep(500*1000);
			writeGPIOi(GPIO25_PATH "value", 0);
			writeGPIOi(GPIO12_PATH "value", 1);
			usleep(500*1000);
			writeGPIOi(GPIO12_PATH "value", 0);
			writeGPIOi(GPIO16_PATH "value", 1);
			usleep(500*1000);
			writeGPIOi(GPIO16_PATH "value", 0);
			writeGPIOi(GPIO20_PATH "value", 1);
			usleep(500*1000);
			writeGPIOi(GPIO20_PATH "value", 0);
			writeGPIOi(GPIO21_PATH "value", 1);
			usleep(500*1000);
			writeGPIOi(GPIO21_PATH "value", 0);
			usleep(500*1000);
			
		}
	}

	else if(strcmp(mode,"Translate")==0){	// conditional to check for string
		num=32;	// makes sure variable meets WHILE condition just for assurance
		printf("Please enter a decimal number 0-31.\n");
		scanf("%d", &num);
		while((num>31)||(num<0)){	// makes sure number is valid for my stored binaries
			// FOR loop blinks LEDs 5 times for an incorrect value
			for(int i=0; i<=4; i++){
					writeGPIOi(GPIO25_PATH "value", 1);
					writeGPIOi(GPIO12_PATH "value", 1);
					writeGPIOi(GPIO16_PATH "value", 1);
					writeGPIOi(GPIO20_PATH "value", 1);
					writeGPIOi(GPIO21_PATH "value", 1);
					usleep(500*1000);
					writeGPIOi(GPIO25_PATH "value", 0);
					writeGPIOi(GPIO12_PATH "value", 0);
					writeGPIOi(GPIO16_PATH "value", 0);
					writeGPIOi(GPIO20_PATH "value", 0);
					writeGPIOi(GPIO21_PATH "value", 0);
					usleep(500*1000);
			}
		printf("Maybe ask for help. This time try between 0 and 31.\n");
		scanf("%d", &num);
	}
	// IF searches my array to find the binary user inputted, displays that num on LEDs
		if((num<=31)&&(num>=0)){	
			writeGPIOi(GPIO25_PATH "value", binStorage[num][0]);
			writeGPIOi(GPIO12_PATH "value", binStorage[num][1]);
			writeGPIOi(GPIO16_PATH "value", binStorage[num][2]);
			writeGPIOi(GPIO20_PATH "value", binStorage[num][3]);
			writeGPIOi(GPIO21_PATH "value", binStorage[num][4]);
			usleep(5000*1000);
		}
	}
	
	else{	// conditional to check for string
		printf("Invalid command. Rerun program and try again.\n");
	}
	
	
	Close();
	
	
	
}

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

void writeGPIOi(char filename[], int value){
   FILE* fp;                           // create a file pointer fp
   fp = fopen(filename, "w+");         // open file for writing
   fprintf(fp, "%d", value);           // send the value to the file
   fclose(fp);                         // close the file using fp
}

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

void Close(){
	writeGPIOi(GPIO_SYSFS "unexport", IOs[0]);
	writeGPIOi(GPIO_SYSFS "unexport", IOs[1]);
	writeGPIOi(GPIO_SYSFS "unexport", IOs[2]);
	writeGPIOi(GPIO_SYSFS "unexport", IOs[3]);
	writeGPIOi(GPIO_SYSFS "unexport", IOs[4]);
}


int main(){
		writeGPIOi(GPIO_SYSFS "export", 21);
		writeGPIO(GPIO21_PATH "direction", "out");
		writeGPIOi(GPIO21_PATH "value", 1);
		usleep(3000*1000);
		writeGPIOi(GPIO_SYSFS "unexport", 21);
}

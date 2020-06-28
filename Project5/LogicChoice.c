#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const int MajIOs[] = {17, 27, 22};	
const int MinIOs[] = {13, 19, 26};	
const int CompIOs[] = {18, 23, 24, 25, 12, 16};	
#define GPIO17_PATH "/sys/class/gpio/gpio17/" 
#define GPIO27_PATH "/sys/class/gpio/gpio27/"
#define GPIO22_PATH "/sys/class/gpio/gpio22/"

#define GPIO13_PATH "/sys/class/gpio/gpio13/"
#define GPIO19_PATH "/sys/class/gpio/gpio19/"
#define GPIO26_PATH "/sys/class/gpio/gpio26/"

#define GPIO18_PATH "/sys/class/gpio/gpio18/" 
#define GPIO23_PATH "/sys/class/gpio/gpio23/"
#define GPIO24_PATH "/sys/class/gpio/gpio24/"
#define GPIO25_PATH "/sys/class/gpio/gpio25/"
#define GPIO12_PATH "/sys/class/gpio/gpio12/"
#define GPIO16_PATH "/sys/class/gpio/gpio16/"

#define GPIO_SYSFS "/sys/class/gpio/"

void writeGPIOi(char filename[], int value){
   FILE* fp;                           // create a file pointer fp
   fp = fopen(filename, "w+");         // open file for writing
   fprintf(fp, "%d", value);           // send the value to the file
   fclose(fp);                         // close the file using fp
}

void writeGPIO(char filename[], char value[]){
   FILE* fp;                           // create a file pointer fp
   fp = fopen(filename, "w+");         // open file for writing
   fprintf(fp, "%s", value);           // send the value to the file
   fclose(fp);                         // close the file using fp
}




int main(){
    if(strcmp(mode,"majority")==0){	// conditional to check for string to execute majority function
        writeGPIOi(GPIO_SYSFS "export", MajIOs[0]);     // export each of the GPIOs
        writeGPIOi(GPIO_SYSFS "export", MajIOs[1]);
        writeGPIOi(GPIO_SYSFS "export", MajIOs[2]);
        usleep(100000);                  // sleep for 100ms
        writeGPIO(GPIO17_PATH "direction", "out");      // turns each of these GPIOs into outputs
        writeGPIO(GPIO27_PATH "direction", "out");
        writeGPIO(GPIO22_PATH "direction", "out");
        
        int storage[3];                                 // gives place for user to store their values
        printf("Please enter 3 bit values of "1" or "0".\n);
        for(int i=0; i<=2; i++){                        // traverses array to accept user input
            scanf("%d", &storage[i]);
            while((storage[i]!=1) || (storage[i]!=0)){   // only accepts HIGH or LOW values
                printf("Try that bit again.\n");
                scanf("%d", &storage[i]);       // retake user input
            }
        }
        if(storage[0]==0){                          // IF and ELSE statements set GPIO to what user gave
            writeGPIOi(GPIO17_PATH "value", 0);
         }
        else writeGPIOi(GPIO17_PATH "value", 1);
        
        if(storage[1]==0){
            writeGPIOi(GPIO27_PATH "value", 0);
         }
        else writeGPIOi(GPIO27_PATH "value", 1);
        
        if(storage[2]==0){
            writeGPIOi(GPIO22_PATH "value", 0);
         }
        else writeGPIOi(GPIO22_PATH "value", 1);
        
        usleep(7000*1000);
        
        writeGPIOi(GPIO_SYSFS "unexport", MajIOs[0]);       // close out all of the used GPIOs
        writeGPIOi(GPIO_SYSFS "unexport", MajIOs[1]);
        writeGPIOi(GPIO_SYSFS "unexport", MajIOs[2]);
        
        
    }
        
    
    
    
    if(strcmp(mode,"minority")==0){	// conditional to check for string
        writeGPIOi(GPIO_SYSFS "export", MinIOs[0]);
        writeGPIOi(GPIO_SYSFS "export", MinIOs[1]);
        writeGPIOi(GPIO_SYSFS "export", MinIOs[2]);
        usleep(100000);                  // sleep for 100ms
        writeGPIO(GPIO13_PATH "direction", "out");
        writeGPIO(GPIO19_PATH "direction", "out");
        writeGPIO(GPIO26_PATH "direction", "out");
        
        int storage[3];                                 // gives place for user to store their values
        printf("Please enter 3 bit values of "1" or "0".\n);
        for(int i=0; i<=2; i++){                        // traverses array to accept user input
            scanf("%d", &storage[i]);
            while((storage[i]!=1) || (storage[i]!=0)){   // only accepts HIGH or LOW values
                printf("Try that bit again.\n");
                scanf("%d", &storage[i]);       // retake user input
            }
        }
        if(storage[0]==0){                          // IF and ELSE statements set GPIO to what user gave
            writeGPIOi(GPIO13_PATH "value", 0);
         }
        else writeGPIOi(GPIO13_PATH "value", 1);
        
        if(storage[1]==0){
            writeGPIOi(GPIO19_PATH "value", 0);
         }
        else writeGPIOi(GPIO19_PATH "value", 1);
        
        if(storage[2]==0){
            writeGPIOi(GPIO26_PATH "value", 0);
         }
        else writeGPIOi(GPIO26_PATH "value", 1);
        
        usleep(7000*1000);
        
        writeGPIOi(GPIO_SYSFS "unexport", MinIOs[0]);       // close out all of the used GPIOs
        writeGPIOi(GPIO_SYSFS "unexport", MinIOs[1]);
        writeGPIOi(GPIO_SYSFS "unexport", MinIOs[2]);
        
    }
    
    
    
    if(strcmp(mode,"comparator")==0){	// conditional to check for string
        writeGPIOi(GPIO_SYSFS "export", MinIOs[0]);
        writeGPIOi(GPIO_SYSFS "export", MinIOs[1]);
        writeGPIOi(GPIO_SYSFS "export", MinIOs[2]);
        writeGPIOi(GPIO_SYSFS "export", MinIOs[3]);
        writeGPIOi(GPIO_SYSFS "export", MinIOs[4]);
        writeGPIOi(GPIO_SYSFS "export", MinIOs[5]);
        usleep(100000);                  // sleep for 100ms
        writeGPIO(GPIO18_PATH "direction", "out");
        writeGPIO(GPIO23_PATH "direction", "out");
        writeGPIO(GPIO24_PATH "direction", "out");
        writeGPIO(GPIO25_PATH "direction", "out");
        writeGPIO(GPIO12_PATH "direction", "out");
        writeGPIO(GPIO16_PATH "direction", "out");
        
        
        int storage[3];                                 // gives place for user to store their values
        printf("Please enter 3 bit values of "1" or "0".\n);
        for(int i=0; i<=2; i++){                        // traverses array to accept user input
            scanf("%d", &storage[i]);
            while((storage[i]!=1) || (storage[i]!=0)){   // only accepts HIGH or LOW values
                printf("Try that bit again.\n");
                scanf("%d", &storage[i]);       // retake user input
            }
        }
        
        int storage2[3];                                 // gives place for user to store their values
        printf("Please enter 3 more bit values of "1" or "0".\n);
        for(int i=0; i<=2; i++){                        // traverses array to accept user input
            scanf("%d", &storage2[i]);
            while((storage2[i]!=1) || (storage2[i]!=0)){   // only accepts HIGH or LOW values
                printf("Try that bit again.\n");
                scanf("%d", &storage2[i]);       // retake user input
            }
        }
        
        if(storage[0]==0){                          // IF and ELSE statements set GPIO to what user gave in First Set
            writeGPIOi(GPIO18_PATH "value", 0);
         }
        else writeGPIOi(GPIO18_PATH "value", 1);
        
        if(storage[1]==0){
            writeGPIOi(GPIO23_PATH "value", 0);
         }
        else writeGPIOi(GPIO23_PATH "value", 1);
        
        if(storage[2]==0){
            writeGPIOi(GPIO24_PATH "value", 0);
         }
        else writeGPIOi(GPIO24_PATH "value", 1);
        
        if(storage2[0]==0){                          // IF and ELSE statements set GPIO to what user gave in Second Set
            writeGPIOi(GPIO25_PATH "value", 0);
         }
        else writeGPIOi(GPIO25_PATH "value", 1);
        
        if(storage2[1]==0){
            writeGPIOi(GPIO12_PATH "value", 0);
         }
        else writeGPIOi(GPIO12_PATH "value", 1);
        
        if(storage2[2]==0){
            writeGPIOi(GPIO16_PATH "value", 0);
         }
        else writeGPIOi(GPIO16_PATH "value", 1);
        
        usleep(7000*1000);
        
        writeGPIOi(GPIO_SYSFS "unexport", CompIOs[0]);      // close out all of the used GPIOs
        writeGPIOi(GPIO_SYSFS "unexport", CompIOs[1]);
        writeGPIOi(GPIO_SYSFS "unexport", CompIOs[2]);
        writeGPIOi(GPIO_SYSFS "unexport", CompIOs[3]);
        writeGPIOi(GPIO_SYSFS "unexport", CompIOs[4]);
        writeGPIOi(GPIO_SYSFS "unexport", CompIOs[5]);
        
        
    }
        
}
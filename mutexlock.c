#include<stdio.h>

#define MAX_RESOURCES 5
int available_resources = MAX_RESOURCES;
//When a process wishes to obtain a number of resources, it invokes the decrease count() function:
/*decrease available resources by count resources*/
/* return 0 if sufficient resources available, */
/* otherwise return -1*/
int decrease_count(int count) {
    mutex.lock();
    if (available_resources < count)
        return -1;
    else{
	mutex.lock();
        available_resources -= count;
	mutex.unlock();
        return 0;
    }
}

//When a process wants to return a number of resources, it calls the increase count() function:
/* increase available resources by count*/
int increase_count(int count){
    mutex.lock();
    if available_resources + count <= MAX_RESOURCES
    	available_resources += count;
    else
	throw an error
    mutex.unlock()
    return 0;
}

int main(){
        decrease_count(available_resources);
        if(available_resources == 0){
                increase_count(available_resources);
                printf("available_resources= %d \n", available_resources);
        }
}

//available resources = 5 pertama kali
//untuk program ini, sudah disertakan mutex lock, namun masih ada error beberapa pak... jadi nanti akan saya perbaiki lagi :)


//Nama Kelompok :
//Hendra NPM 203400013
//Yohanes Calvin NPM 203400008


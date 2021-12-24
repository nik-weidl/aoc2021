#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE * file;
    int number = 0;
    unsigned int data[2000]; // 2000 lines
    int size = 0;

    file = fopen("input.txt", "r");

    if (file) {
        while (fscanf(file, "%d", &number) == 1){
            data[size++] = number;
        }
        fclose(file);
    }
    // Part 1
    int curr, prev;
    int counter = 0;

    for (int i = 1; i < size; i++){
        curr = data[i];
        prev = data[i-1];
        if(curr > prev) counter++;
    }
    printf("Part 1 Solution: %d\n", counter);

    // Part 2
    counter = 0;

    for(int i = 1; i < size - 2; i++) {
        prev = data[i-1] + data[i] + data[i+1];
        curr = data[i] + data[i+1] + data[i+2];
        if(curr > prev) counter++;
    }
    printf("Part 2 Solution: %d\n", counter);
}

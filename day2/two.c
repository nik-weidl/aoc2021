#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    FILE * file;

    struct data {
        char dir[9]; // max length 9
        int val;
    };

    struct data orders[1000]; // 1000 lines

    int number = 0;
    char str[9] = "";
    int size = 0;

    file = fopen("input.txt", "r");

    if (file) {
        while (fscanf(file,"%s", str) == 1 && fscanf(file, "%d", &number) == 1){
            strcpy(orders[size].dir,str);
            orders[size++].val = number;
        }
        fclose(file);
    }

    // Part 1
    int hor, vert;
    hor = vert = 0;
    for (int i = 0; i < size; i++){
        if(strcmp(orders[i].dir, "forward") == 0) hor += orders[i].val;
        if(strcmp(orders[i].dir, "up") == 0) vert -= orders[i].val;
        if(strcmp(orders[i].dir, "down") == 0) vert += orders[i].val;
    }
    int result = hor * vert;
    printf("Part 1 Solution: %d\n", result);
    
    // Part 2
    int aim; 
    hor = vert = aim = 0;
    for (int i = 0; i < size; i++){
        if(strcmp(orders[i].dir, "forward") == 0){
            hor += orders[i].val;
            vert += orders[i].val * aim;
        } 
        if(strcmp(orders[i].dir, "up") == 0){ 
            aim -= orders[i].val;
        }
        if(strcmp(orders[i].dir, "down") == 0){
            aim += orders[i].val;
        }
    }
    result = hor * vert;
    printf("Part 2 Solution: %d\n", result);
}

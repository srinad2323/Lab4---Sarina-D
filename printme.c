#include <stdio.h>
#include <string.h>

extern int compute_nums(int *array_num, int length);
int main(){
    char filename[100];
    int currNum = 0;
    int counter = 0;
    int length = 0;
    FILE* fptr;

    printf("Enter a filename: ");
    scanf("%99s", filename);
    fptr = fopen(filename, "r");

    if (fptr == NULL){
        printf("Unable to open file");
        return 0;
    }

    fscanf(fptr, "%d", &length);

    int array_num[length];

    while (fscanf(fptr, "%d", &currNum) == 1){
        array_num[counter] = currNum;
        counter++;
    }

    fclose(fptr);

    for (int i = 0; i < length; i++){
        printf("%d ", array_num[i]);
    }

    printf("\n");

    int total = compute_nums(array_num, length);
    printf("Total number: %d\n", total);
    
    return 0;
}
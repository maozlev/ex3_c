#include <stdio.h>
#include<stdlib.h>
#define SIZE 50
#define LINE 256

shift_element(int* arr, int i){
    int j;
    for (j = i; j > 0 ; j--)
    {
        *(arr+j) = *(arr+j-1);
    }
}

insertion_sort(int* arr , int len){
    int i, tmp, j;
    for (i = 1; i < len; i++) { 
        tmp = *(arr+i); 
        j = i - 1; 

        while (j >= 0 && *(arr+j) > tmp) {
            shift_element( (arr+j),1); 
            j--; 
        } 
        *(arr+j+1) = tmp; 
    }
}

int main(){
    // part 1 - insertion sort.
    int arr1[SIZE] = {0};
    int i=0;
    int t=0;
    while(i<SIZE){
        printf("please enter a number: ");
        scanf("%d", &t);
        arr1[i]=t;
        i++;
    }
    printf("\n");
    printf("The array: \n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d,", arr1[i]);
    }
    int *p1 = arr1;
    insertion_sort(p1,SIZE);
    printf("\n");
    printf("The sorted array: \n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d,", arr1[i]);
    }
    printf("\n");

// part 2 - .
    

    char str[LINE];
    FILE *fp;
    fp = fopen("search_file.txt", "r");
    // if (fgets(str, LINE, fp) != NULL) {
    //     printf("number of labels: %d", getline(*str));
    // }
    // print_line(str);
    


    s[LINE];
    int counter = 0;
    FILE *fptr = fopen("search_file.txt", "r");


    while (1) {
        int c = fgetc(fptr);
        ++counter;
        if (c == '\n') break;
    }

    printf(counter);
    return 0;
}

print_line(char s[]){
    s[LINE];
    FILE *fptr;

    if ((fptr = fopen("search_file.txt", "r")) == NULL) {
        printf("Error! opening file failed");
        exit(1);
    }

    // reads text until newline is encountered
    fscanf(fptr, "%[^\n]", s);
    printf("Data from the file:\n%s", s);
    fclose(fptr);

    return sizeof(s);
}

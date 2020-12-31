#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define LINE 256

int question_b(){

    char str[LINE];
    char word[4];
    FILE *fp;
    fp = fopen("search_file.txt", "r");
    int c, arr_counter=0;
    bool flag1 = false,flag2 = false,flag3 = false, flag4=false;
    FILE *fptr = fopen("search_file.txt", "r");

    while(fgets(str, LINE, fp) != NULL) {
        flag1 = false;
        flag2 = false;
        flag3 = false;
        flag4 = false;
        while (1){
            c = fgetc(fptr);
             
            if(c!='c' && c!='a' && c!='t' && c!= ' ' && c!= '\t' && c != '\n' && c!= EOF && arr_counter==0){
                if (flag4 != true)  {
                    flag4 = true;
                    word[arr_counter++]=c;
                }
            }
            if(c!='c' && c!='a' && c!='t' && c!= ' ' && c!= '\t' && c != '\n' && c!= EOF && arr_counter==1){
                if (flag4 != true)  {
                    flag4 = true;
                    word[arr_counter++]=c;
                }
            }
            if(c!='c' && c!='a' && c!='t' && c!= ' ' && c!= '\t' && c != '\n' && c!= EOF && arr_counter==2){
                if (flag4 != true)  {
                    flag4 = true;
                    word[arr_counter++]=c;
                }
            }
            if(c!='c' && c!='a' && c!='t' && c!= ' ' && c!= '\t' && c != '\n' && c!= EOF && arr_counter==3){
                if (flag4 != true)  {
                    flag4 = true;
                    word[arr_counter++]=c;
                        for (int i = 0; i < 4; i++)
                        {
                            printf("%c",word[i]);
                        }
                        printf("\n");
                        for (int i = 0; i < 4; i++)
                        {
                            word[i] = '\0';
                        }
                        flag1=flag2=flag3=flag4=false;
                        arr_counter=0;
                }
            }

            if(c == 'c'){
                if(flag1!=true){
                    flag1=true;
                    word[arr_counter++] = c;
                }
                else{
                    flag1=flag2=flag3=false;
                    arr_counter=0;
                    for (int i = 0; i < 4; i++)
                    {
                        word[i] = '\0';
                    }  
                }
            }
            if(c == 'a'){
                if(flag2!=true && flag1==true){
                    flag2=true;
                    word[arr_counter++] = c;
                }
                else{
                    flag1=flag2=flag3=false;
                    arr_counter=0;
                    for (int i = 0; i < 4; i++)
                    {
                        word[i] = '\0';
                    }  
                }
            }

            if (c != ' ' && c != '\t' && c != EOF && c!= '\n' && c != 't' && arr_counter == 4) {
                for (int i = 0; i < 4; i++)
                {
                    word[i] = '\0';
                }
                flag1=flag2=flag3=flag4=false;
                arr_counter=0;
            }

            if(c == 't'){
                if(flag3!=true && flag1==true && flag2==true){
                    flag3=true;
                    word[arr_counter++] = c;
                }
                else{
                    flag1=flag2=flag3=false;
                    arr_counter=0;
                    for (int i = 0; i < 4; i++)
                    {
                        word[i] = '\0';
                    }  
                }
            }

            if(c==' ' || c == '\t' || c == EOF){
                if(arr_counter==4 && flag1==true && flag2==true && flag3==true){
                    for (int i = 0; i < 4; i++)
                    {
                        printf("%c",word[i]);
                    }
                    printf("\n");
                    for (int i = 0; i < 4; i++)
                    {
                        word[i]= '\0';
                    }
                    flag1=flag2=flag3=flag4=false;
                    arr_counter=0;                       
                }
                 if(arr_counter==3 && flag1==true && flag2==true && flag3==true){
                    word[arr_counter++]=c;
                        for (int i = 0; i < 4; i++)
                        {
                            printf("%c",word[i]);
                        }
                        printf("\n");
                        for (int i = 0; i < 4; i++)
                        {
                            word[i] = '\0';
                        }
                        flag1=flag2=flag3=flag4=false;
                        arr_counter=0;
                }
                else{
                    flag1=flag2=flag3=flag4=false;
                    arr_counter=0;
                    for (int i = 0; i < 4; i++)
                    {
                        word[i] = '\0';
                    }
                }
            }

            if (c == '\n') {
                flag1=flag2=flag3=false;
                arr_counter=0;
                for (int i = 0; i < 4; i++)
                {
                    word[i] = '\0';
                }
                break;
            }
        }
    }
    return 0;
}



int question_a () {
    char str[LINE];
    FILE *fp;
    fp = fopen("search_file.txt", "r");

    int counter=0,curr_counter = 0;
    int c;
    bool flag1 = false,flag2 = false,flag3 = false, flag4=false;
    FILE *fptr = fopen("search_file.txt", "r"); // We can't figure out why, but if we delete this, the program runs forever - so here it stays

    while(fgets(str, LINE, fp) != NULL) {
    // printf("Original line =  %s\n", str);
    flag1 = false;
    flag2 = false;
    flag3 = false;
    flag4 = false;
    curr_counter = 0, counter = 0;
    while (1){
        
        c = fgetc(fptr);
        if(c == 'c'){
            if(flag1!=true){
            curr_counter=counter;
            flag1=true;
            }
            else{
                flag1=false;
            }
            if(counter-2 > curr_counter){
                flag2=false;
                flag3=false;
            }
            }

        if(c == 'a'){
            if(flag1==true){
                if (counter-1==curr_counter || counter-2==curr_counter){
                    if(flag2!=true){ 
                    flag2=true;
                    curr_counter=counter;
                    } 
                    else {
                        flag1 = false;
                        flag2 = false;
                    }
                }
            }
            else {
                flag1 = false;
                flag2 = false;
            }
            if(counter-2 > curr_counter){
                flag1=false;
                flag2=false;
                flag3=false;
            }
        }
        if(c == 't'){
            if(flag2==true&&flag1==true){
                if (counter-1==curr_counter || counter-2==curr_counter){
                    if(flag3!=true){ 
                        flag3=true;
                        flag4 = true;
                        curr_counter=counter;
                        }
                        else {
                        flag1 = false;
                        flag2 = false;
                        flag3 = false;
                        flag4 = false;
                    }
                }
            }
            else {
                    flag1 = false;
                    flag2 = false;
                    flag3 = false;
                }
                if(counter-2 > curr_counter){
                flag1=false;
                flag2=false;
                flag3=false;
            }
        }


        if (c == '\n') {
            if (flag4 == true) {
            printf("Good line: %s\n", str);
            break;
        }  
            break;
        }
    
        counter++;
    }

    }
    return 0;
}

int main(){
    question_a();
    question_b();
   return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;
/*
 * a text line>
 * input
 * Pass by ref
 * The reason to do this is so that
 * the function will have the power to change the value.
 *
 *
 */
extern char **environ;


//
//  main.c
//  andreyshell
//
//  Created by Andrey on 10/17/19.
//  Copyright © 2019 Andrey. All rights reserved.
//
void execute(char **pString);

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printEnviron(char **environ){
    for (char **env = environ; *env != 0; env++)
    {
        char *temp = *env;
        printf("%s\n", temp);
    }
}

void clear(){
    printf("\033[H\033[J\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void pause(){

    printf("Shell is paused. Press enter to continue");
    while (cin.get()!='\n'){
        }
    printf("Shell unpaused");

}




void loop() {
//

//    clear();

//    clear();

//    char *line = NULL;
//    string **args = NULL;
//    int status;
    //user enters commands
    //parsing happens to separate out arguments from command
    //execute command
//    status=1;

//    while(status)
//        parse(line);
//        parse(line);
//       status = run(args);


//        status=0;

    }
void printusrprompt(char** argv){
    printf("<%s/SHELL>",argv[0]);
};

char ** parse(char *line){

    char* array[100];
    int i=0;
    char** parsedArray=NULL;
    char* token=NULL;
    token=strtok(line," ");
    array[i]=token;

    if(token!=NULL){
        while(token!=NULL){
            printf("%s \n", token);
            array[i]=token; i++;
            token=strtok(NULL," ");
        }
    }
    for (size_t i = 0; i < 99; i++) {
        printf("%s,",array[i]);
    }

    return parsedArray;

}

int main(int argc, char** argv, char** envp) {


    printusrprompt(argv);
    char* userInputString=NULL;
    size_t buff = 0;
    getline(&userInputString, &buff,stdin);
    execute(parse(userInputString));


    return 0;
}

void execute(char **pString) {
    for (size_t i = 0; i < 99; i++) {
        printf("%s,",pString[i]);
    }
}




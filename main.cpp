#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <zconf.h>
#include <errno.h>


using namespace std;
extern char **environ;


//
//  main.c
//  andreyshell
//
//  Created by Andrey on 10/17/19.
//  Copyright © 2019 Andrey. All rights reserved.
//

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

void paused(){

    printf("Shell is paused. Press enter to continue");
    while (cin.get()!='\n'){
        }
    printf("Shell unpaused\n");

}


void loop() {

    }

void printUsrPrompt(char** argv){
    printf("<%s/SHELL>",argv[0]);
};

int tokenize(char *line, char *array[]){

    int i=0;
    char* token=NULL;
    token=strtok(line," ");
    array[i]=token;
    int numArgs;

    if(token!=NULL){
        while(token!=NULL){
            array[i]=token; i++;
            token=strtok(NULL," ");
            numArgs++;
        }
    }

    printf("Tokenized: \n");
    for (int j = 0; j < numArgs; j++) {
        printf("%d - %s\n",j, array[j]);
    }
    printf("number of arguments: %d \n\n", numArgs);
    return numArgs;
}

void execute(char* pString[]) {

}

void echo(char *array[],int numArgs){
    printf("Got to echo\n");
    for (int j = 1; j < numArgs; j++) {
        printf("%s ",array[j]);
    }
}

void cd(char *array[],int numArgs){
    printf("Change directory\n");
    int error;
    if(numArgs==1){
        char cwd[PATH_MAX];
        printf("%s", getcwd(cwd, sizeof(cwd)));
    }
    if(numArgs==2){
        error = chdir(array[1]);
        printf("chdir error: %d. errorno = %d",error,errno);
    }
    if(numArgs>2){
    }

}

int parse(char *array[],int numArgs){
    printf("Parsing \n");

    if (strncmp(array[0], "echo", 4) == 0){
        echo(array,numArgs);
    }
    if (strncmp(array[0], "clear", 5) == 0){
        clear();
    }

    if (strncmp(array[0], "cd", 5) == 0){
        cd(array,numArgs);
    }

    if (strncmp(array[0], "pause", 5) == 0){
        paused();
    }

    if (strncmp(array[0], "quit", 4) == 0){
        printf("Quit function registered. Exiting program");
        return(1);
    }

    else return 0;


}
int main(int argc, char** argv, char** envp) {

    char* array[100];
    printUsrPrompt(argv);
    char* userInputString=NULL;
    size_t buff = 0;
    int numArgs;

    do{
        printUsrPrompt(argv);
        getline(&userInputString, &buff,stdin);
        size_t sizeOfArray = (sizeof(array) / sizeof(array[0]));
        numArgs = tokenize(userInputString, array);
    }
    while(parse(array,numArgs)!=1);

    return 0;
}






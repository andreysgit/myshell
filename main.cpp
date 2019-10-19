#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <zconf.h>
#include <errno.h>
#include <unistd.h>


using namespace std;

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


void printUsrPrompt(char** argv){
    printf("%s>",argv[0]);
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

    printf("Change directory\n array[1]=%s numArgs = %d \n",array[1],numArgs);
    int error;
    char buffer[PATH_MAX];
    char *path = getcwd(buffer, PATH_MAX);
    char *currentPath = path;
    char *newPath = array[1];
    printf("new path: %s\n",newPath);
    if(numArgs==1){
        printf("No cd arg, printing working directory.\n");
        printf("Current path: %s\n",currentPath);
    }
    if(numArgs==2){
        error = chdir(newPath);
        printf("chdir error: %d. errorno = %d\n",error,errno);
        if(error!=0){
            perror("cd");
        }
    }
    if(numArgs>2){
        printf("There should only be 1 argument to cd");
    }

}

int parse(char *array[],int numArgs,char** environ){
    printf("Parsing \n");

    if (strncmp(array[0], "echo", 5) == 0){
        echo(array,numArgs);
    }
    if (strncmp(array[0], "clear", 6) == 0){
        clear();
    }

    if (strncmp(array[0], "cd", 2) == 0){
        cd(array,numArgs);
    }

    if (strncmp(array[0], "pause", 5) == 0){
        paused();
    }

    if (strncmp(array[0], "env", 4) == 0){
        printEnviron(environ);
    }

    if (strncmp(array[0], "quit", 4) == 0){
        printf("Quit function registered. Exiting program");
        return(1);
    }

    else return 0;


}
int main(int argc, char** argv, char** envp) {

    char* array[100];
    char* userInputString=NULL;
    size_t buff = 0;
    int numArgs;

    do{
        printUsrPrompt(argv);
        getline(&userInputString, &buff,stdin);
        numArgs = tokenize(userInputString, array);
    }
    while(parse(array,numArgs,envp)!=1);

    return 0;
}






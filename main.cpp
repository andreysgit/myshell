#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>


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

void pause(){

    printf("Shell is paused. Press enter to continue");
    while (cin.get()!='\n'){
        }
    printf("Shell unpaused");

}


void loop() {

    }

void printUsrPrompt(char** argv){
    printf("<%s/SHELL>",argv[0]);
};

void tokenize(char *line, char *array[]){

    int i=0;
    char* token=NULL;
    token=strtok(line," ");
    array[i]=token;

    if(token!=NULL){
        while(token!=NULL){
            array[i]=token; i++;
            token=strtok(NULL," ");
        }
    }

    printf("Tokenized: \n");
    for (int k = 0; array[k]!=0 ; k++) {
        printf("%s,", array[k]);

    }

}

void execute(char* pString[]) {
    printf("gets to echo");
//    for (size_t i = 0; i < 99; i++) {
//        printf("%s,",pString[i]);
//    }
}

void echo(char *str[]){
    printf("Got to echo");
    for (int k = 1; str[k]!=0 ; k++) {
        printf("%s ", str[k]);
    }
}
void parse(char *array[]){
    printf("Got to parse \n");
    if (strncmp(array[0], "echo", 4) == 0){
        echo(array);
    }

}
int main(int argc, char** argv, char** envp) {

    char* array[100];
    printUsrPrompt(argv);
    char* userInputString=NULL;
    size_t buff = 0;
    getline(&userInputString, &buff,stdin);
    tokenize(userInputString, array);
    parse(array);



    return 0;
}






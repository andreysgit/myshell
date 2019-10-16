#include <iostream>
#include <vector>

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

void clear(){
    printf("\033[H\033[J");
}

void pause(){

    printf("Shell is paused. Press enter to continue");
    while (cin.get()!='\n'){
        }
    printf("Shell unpaused");

}


void parse(char *line){


//    for (int i = 0; i < 99; i++) {
//        while ((argArray[i] = strtok_r(line, " ", &line))){
//            printf("%s ", argArray[i]);
//        }
//    }


}

void read(void){

}

void run(char** args){

}

//main loop

void loop() {

    char *argArray[99];
    cout << "User>";
    clear();
//    cin.getline(myline,99);
//    parse(myline);
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


int main(int argc, char** argv) {

    //while
//    pause();

    loop();
    return 0;
}




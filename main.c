
#include "shell.h"

int main(void) {
  char inputString[MAXCOM];        // buffer to hold command entered
  char *parsedArgs[MAXLIST];       // command line
  char *parsedArgsPiped[MAXLIST];  // piped args
  int execFlag = 0;                // execute flag

  // init my shell
   init_shell();
  // // show my shell
  printf(ANSI_COLOR_GREEN
         "*************************************************" ANSI_COLOR_RESET
         "\n");
  printf(ANSI_COLOR_RESET "\t\t***EL_ABBAS_SHELL***" ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_GREEN
         "*************************************************" ANSI_COLOR_RESET
         "\n");

          printf(ANSI_COLOR_RED"please login enter your name :\t"ANSI_COLOR_RESET);
      scanf("\n");
    scanf("%[^\n]s",userlogin);
    clc();
  // dynamic code superloop
  while (True) {
    // print EX directory
    printEXDir();
    // take input
    if (takeInput(inputString)) continue;
    // process
    int size;
    execFlag = process_Line(inputString, parsedArgs, parsedArgsPiped, &size);
    // execflag returns zero if there is no command
    // or it is a builtin command,
    // 1 if it is a simple command
    // 2 if it is including a pipe.

    // execute
    if (execFlag == 1) exec_Args(parsedArgs, size);

    if (execFlag == 2) execArgsPiped(parsedArgs, parsedArgsPiped);
  }
  return 0;
}

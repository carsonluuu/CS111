//#NAME: Jiahui Lu
//#EMAIL: carsonluuu@gmail.com
//#UID: 204945099

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <getopt.h>

#define TRUE 1
#define FALSE 0

void handlerSegfault(); //SIGSEGV handle segfault

int main(int argc, char *argv[]) {

  static struct option long_options[] = {
    {"input",    required_argument, NULL, 'i'},
    {"output",   required_argument, NULL, 'o'},
    {"segfault", no_argument,       NULL, 's'},
    {"catch",    no_argument,       NULL, 'c'},
    {0, 0, 0, 0}
};

  int faultFlag = FALSE;

while (TRUE) {
  int cmd = getopt_long(argc, argv, "", long_options, NULL);
  if (cmd == -1) break;
  else if (cmd == 'i') {
    int fd0 = open(optarg,O_RDONLY);
    if (fd0 == -1) {
      fprintf(stderr, "Cannot Open File. Input file %s has this error: %s\n", optarg, strerror(errno));
      exit(2);
    }
    close(0);
    dup(fd0);
    close(fd0);
  } else if (cmd == 'o') {
    int fd1 = creat(optarg, 0666);
    if(fd1==-1) {
      fprintf(stderr, "Cannot Output File. Output file %s has this error: %s\n", optarg, strerror(errno));
      exit(3);
    }
    close(1);
    dup(fd1);
    close(fd1);
  } else if (cmd == 's') {
    // force a segmentation fault
    faultFlag = TRUE;

  } else if (cmd == 'c') {
    //register a SIGSEGV handler that catches the segmentation fault
    signal(SIGSEGV, handlerSegfault);
  } else {
    fprintf(stderr, "Argument is not supported! Accepted Usages are listed: --input=filename, --output=filename, --segfault, --catch");
    exit(1);
  }
}

  if (faultFlag) {
    // force a segmentation fault
    char *fault_ptr = NULL;
    *fault_ptr = 'A';
  }

  ssize_t n;
  char buf[1000];
  while ((n = read(STDIN_FILENO, buf, 1000))) {
    if (n != write(STDOUT_FILENO, buf, n)) {
      fprintf(stderr, "Write Error Occurs!\n");
    }
    if (n < 0) {
      fprintf(stderr, "Read Error Occurs!\n");
    }
  }
  exit(0);
}

void handlerSegfault() {
  fprintf(stderr, "Segmentation Fault Caught.\n");
  exit(4);
}

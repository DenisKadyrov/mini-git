#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>


void init_git(void) {
  fprintf(stderr, "Logs from your program will appear here!\n");

  if (mkdir(".git", 0755) == -1 || 
      mkdir(".git/objects", 0755) == -1 || 
      mkdir(".git/refs", 0755) == -1) {
      fprintf(stderr, "Failed to create directories: %s\n", strerror(errno));
  }

  FILE *headFile = fopen(".git/HEAD", "w");
  if (headFile == NULL) {
       fprintf(stderr, "Failed to create .git/HEAD file: %s\n", strerror(errno));
  }
  fprintf(headFile, "ref: refs/heads/main\n");
  fclose(headFile);

  printf("Initialized git directory\n");
}

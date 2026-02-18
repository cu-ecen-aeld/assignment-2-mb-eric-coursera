#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char **argv)
{
  if (argc != 3){
    syslog(LOG_ERR, "ERROR: Incorrect number of invocation arguments. Expexted 2, given %d", argc - 1);
    exit(1);
  }
    
  openlog(NULL, 0, LOG_USER);
  FILE * f = fopen(argv[1], "w");
  if (f == NULL){
    syslog(LOG_ERR, "Could not open file %s for writing", argv[1]);
    closelog();
    return 1;
  }

  /*
    Use the syslog capability to write a message “Writing <string> to <file>” where <string> is the text string written to file (second argument) and <file> is the file created by the script.  This should be written with LOG_DEBUG level.
   */

  syslog(LOG_DEBUG, "Writing '%s' to file %s", argv[2], argv[1]);
  
  int writeresult = fprintf(f, "%s", argv[2]);
  if (writeresult < 0){
    syslog(LOG_ERR, "Could not write the string '%s' to the file %s", argv[2], argv[1]);
    fclose(f);
    closelog();
    return 1;
  }
  
  fclose(f);
  closelog();
  
  return 0;
}

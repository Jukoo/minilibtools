#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h>  
#include <string.h>  

#include "subprocess.h"

int
main(int __ac , char **__av )  {  
  

  char full_path_binexec[255] ;  
  char *x[]  =  { "-l"  , "-a" }  ;
  
  Subp_t shell ; 
  new_subprocess(&shell, SILENT); 
  
  shell.popen("ls" , x , "output.cmd" ,  shell.shell_output_mode) ;  

  

  return EXIT_SUCCESS ; 
}

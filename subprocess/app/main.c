#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h>  
#include <string.h>  
#include <assert.h>  

#include "subprocess.h"

int
main(int __ac , char **__av )  {  
 
  /* 
  char *x[]  =  { "-l"  , "-a" }  ;
  
  Subp_t shell ; 
  new_subprocess(&shell, SILENT); 

  assert ( shell.find("ls") != _Nullable ) ; 
  
  shell.popen("ls" , x , "output.cmd" ,  shell.shell_output_mode) ;  

  */ 

  
  binpaths_collections(_Nullable)  ;   

  return EXIT_SUCCESS ; 
}

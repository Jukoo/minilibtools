#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h>  
#include <string.h>  
#include <assert.h>  
#include <err.h> 

#include "subprocess.h"

int
main(int __ac , char **__av )  {  


  Subp_t  subp_manager ;  
  if ( (subprocess_init(&subp_manager ,  _Nullable))  == _Nullable ) 
  {
    errx(~0 ,  "Subp_t manager fail init") ; 
  } 
    
  int  command_index = subp_manager.check("ls") ; 
  if ( command_index <=~0)  
  {
     warnx("not found !") ;
     exit(1);
  }
  
  fprintf(stdout , "position -> %i  : %s" , command_index , subp_manager.binpaths[command_index]) ;
  
  //subp_manager.Popen("ls" ,  {"-a"}  , _nullable | dev_nul  | shell)

  /* 
  char *x[]  =  { "-l"  , "-a" }  ;
  
  Subp_t shell ; 
  new_subprocess(&shell, SILENT); 

  assert ( shell.find("ls") != _Nullable ) ; 
  
  shell.popen("ls" , x , "output.cmd" ,  shell.shell_output_mode) ;  

  */ 

  
  //binpaths_collections(_Nullable)  ;   
  
  //_bool  is  = cmd_check("ls"); 

  //printf("%i \n" , is); 

  return EXIT_SUCCESS ; 
}

/** @file  exec.c   
 *  @brief subprocess  call 
 *
 *  @author  Umar Ba (Jukoo) @openwireStudio 
 *
 */ 

#include <stdlib.h> 
#include <unistd.h>
#include <stdio.h> 
#include <string.h> 
#include <err.h> 
#include <errno.h> 
#include <fcntl.h> 

#include "subprocess.h"


Subp_t * new_subprocess (Subp_t  *  supb , SHOUT   sh_behavior)  {
  supb->popen = subprocess  ; 
  supb->find  =  is_set; 
  supb->shell_output_mode =  sh_behavior ;
  return supb; 
}

static int  subprocess(const char *unix_command, char *const *flagoption ,  char *  shell_out ,   SHOUT sh_behavior){ 
  errno = 0 ; 
  
  char *flagoption_clone[MAXBUFF] ={ (char *)unix_command } ; 
 
  //! copy on  write  
  int  j =  1 ; 
  while (flagoption[j-1] &&  strlen(flagoption[j-1])  >1 )
  {
    flagoption_clone[j]  = flagoption[j-1] ;  
    j++ ; 
  }
  flagoption_clone[j++] = _Nullable ; 
 
  char fpath_cmd[MAXBUFF] ; 

  if ( is_available(unix_command , fpath_cmd)  ==  _Nullable ) 
  {
    errx(EXIT_FAILURE ,  "cammand not available") ;  
  }

  //! TODO : put this inside function  ! 
  int  fd_redirect = -1 ; 

  if (sh_behavior == NOISE  && shell_out  != _Nullable)  
  { 
     fd_redirect  = open(shell_out, O_WRONLY|O_CREAT ) ;  
     if ( 0 >  fd_redirect )
     {
      warn("Redirect Stream  fail")  ; 
      close(fd_redirect);  
     }
    
    dup2(STDOUT_FILENO ,  fd_redirect);  
    close (fd_redirect) ; 
  }
  
  //!  SHOUT sh_behavior is set to SILENT the output of the command will be redirected  to /dev/null 
  if (sh_behavior == SILENT)  
  {
      char * filestream =  shell_out== _Nullable ?  DEVNULL :  shell_out ;  
       
      fd_redirect  = open(filestream , O_CREAT  | O_WRONLY)  ; 

      if ( fd_redirect == -1  ) 
      {
        warn("Redirect  stream fail\n") ; 
        close(fd_redirect) ; 
      }else  
      { 
        dup2(fd_redirect ,   STDOUT_FILENO ) ; 
        close(fd_redirect) ; 
      }

  } 

  
  if ( execv(fpath_cmd , flagoption_clone)  == -1 )  
  { 
    return   -1 ; 
  }
   
  return  EXIT_SUCCESS ; 
}
 
static   void get_xpath(const char *envar, char **binpaths) { 

  char  ve_path[MAXBUFF]={0} ; 

  char **bp = binpaths ; 
  if( envar == _Nullable ) memcpy(ve_path , UNIX_ENV_PATH ,strlen(UNIX_ENV_PATH)) ; 
  else    memcpy(ve_path , envar  , strlen(envar) ) ; 
  
  char *ve_path_value  =  getenv(ve_path) ; 

  if ( ve_path_value == _Nullable )  
  {
    errx( EXIT_FAILURE , "Empty Path Variable") ;  
  }
  
  
  int i=0   ; 
  
  char *path_token = strtok(ve_path_value, PATH_DELIM)  ; 
  while (path_token) 
  {
    binpaths[i] = path_token ; 
    i++; 
    path_token= strtok(_Nullable, PATH_DELIM); 
  }
  binpaths[i++]=_Nullable ; 
  
  binpaths = bp ; 

}


static char * is_available (const char * unix_command , char * fpath_storage ) {
  
  char endpoint_xcmd[MAXBUFF >>3]  = {0};  

  sprintf ( endpoint_xcmd , "/%s" , unix_command ) ; /** -> example ls  -> /ls */ 

  char *binpaths[MAXBUFF]  = { _Nullable } ; 

  get_xpath(UNIX_ENV_PATH ,  binpaths) ; 
  char **binpaths_begin   =  binpaths ;   
   
  char  abs_binpathlocaltion[MAXBUFF] = {0};  /** absolut binary path location  */
   
  int next = 0 ;  
  while (  *binpaths  != _Nullable ) 
  {
    memcpy(fpath_storage, *binpaths , strlen(*binpaths) ) ; 
    strcat(fpath_storage, endpoint_xcmd) ;  

    printf("bp ->  %s  \n "  , *binpaths) ; 
    /**  Try to check if the command is  an executable */ 
    if (access(fpath_storage,  X_OK) != -1 ) 
    { 
      break ;  
    }
    else memset(fpath_storage ,  0 , MAXBUFF) ;

    *binpaths =  binpaths[next++] ; 
  }

  printf("fp -> %s \n"  ,fpath_storage ) ;
   
  return  strlen(fpath_storage) >1 ?  fpath_storage : _Nullable ; 
}


char *is_set (const char* unix_command) {
  char fpathcmd[MAXBUFF] ={ 0 } ;  
  char * cmd   = is_available(unix_command , fpathcmd ) ;  
  fprintf(stdout , " cmd  ->  %s \n "  , cmd ) ; 
  return  cmd ; 
}

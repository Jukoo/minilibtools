/** 
 * @file exec.h  
 * @brief  function  prototype for subprocess call 
 * 
 * execute  a child programme in new process 
 * @author Umar  Ba  (jukoo)  @OpenwireStudio  aka   GlItCh! 
 */ 

#if  !defined (__subexec_unix_cmd ) 
#define __subexec_unix_cmd

#define UNIX_ENV_PATH  "PATH"
#define PATH_DELIM ":"   
#define _Nullable (void *) 0 
#define MAXBUFF  0xEA 
#define DEVNULL  "/dev/null" 

typedef  enum  { 
   NOISE ,  
   SILENT   
} SHOUT; 

typedef  struct  { 
  int  (*popen) (const char  * , char *const * , char *  , SHOUT ) ; 
  char *(*find)  (const char  *  , char *) ;  
  SHOUT shell_output_mode ;  
}Subp_t  ; 


/** @brief initialize  Subp_t  struct  
 *  
 *  initialize struct  member  attribute 
 *   
 *  @param __subprocess_instance  Subp_t ptr 
 *  @param __shellBehavior  SHOUT mode  
 *  @return  Subp_t  * 
 */
Subp_t * new_subprocess ( Subp_t *__subprocess_instance  , SHOUT __shellBehavior) ; 

extern  char **environ ;

/** @brief  execute  unix command
 *
 * when  the passed  command is  available  on your  system, it'll be  
 * be executed in  childprocess  that should give you the same result. 
 * This function wraps execv ! 
 *
 * @param __unix_command The named unix command 
 * @param __flagoption   The flags options that the command allowed   
 * @param __output       Where the command print out the result if NULL  that print out in the current shell
 *                       otherwise in the given  value  if the file is not  created  it'll be automaticly created  
 * @param __shbehavior   ... 
 *
 * @return int           0  on success   != 0  on error  
 */ 
static int   subprocess  ( const  char * __unix_command  , char * const  *__flagoption,  char *__output , SHOUT   __shbehavior); 

/** @brief get all executable path from  unix  $PATH environment variable 
 *  
 *  Parse  PATH environ variable  and extracte all binary path inside 
 *  
 *  @param   __envar available environment variable  by default it's $PATH
 *           if you have another shell environ  variable redifine  UNIX_ENV_PATH
 *           at compile time 
 *  @param __binpath Use $PATH by default 
 *  @return **char 
 */ 
static  void  get_xpath(char  const * __envar,  char **__binpaths)  ;


/** @brief check the passed command is available 
 *  
 *  function verification that 's just check the passed  command 
 *  in your  binary path  
 *  
 *  @param __unix_command   unix  command   e.g ls cat or whatever available in your system 
 *  @param __abs_fullpathstorage  where the full path of the command is stored  
 *  @return  void *  : should be not null  
 */  

char  * is_available(const char * __unix_command ,char * __abs_fullpathstorage) ; 



#endif //!__subexec_unix_cmd 

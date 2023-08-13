/** 
 * @file subprocess.h   
 * @brief  function  prototype for subprocess call 
 * @copyright (c) 2023  
 * @author Umar  Ba  (jukoo)  LoopFocus, Software Craftsmanship  
 */ 

#if !defined(__SUBPROC_H) 
#define      __SUBPROC_H

#define  SUBP  

#if !defined(__linux__)
#error  "Reserved for Gnu/Linux OS"  
#endif 

#define  _nullable (void *)   ( 0 << 1 ) 
#define  _Nullable _nullable 

#define  DSEPSYMB  ":"
#define  _gnu_linux_envar_path_reference "PATH"
#define  _gnu_linux_envar_path_sep_symbol  DSEPSYMB 

#define  MAXBUFF 0xff 

extern const char **environ  ;

typedef enum {  
  false, 
  true 
}_bool ; 
/** Subprocess data structure */ 
typedef  struct  __subprocess_t  Subp_t  ; 
struct __subprocess_t  {

  /*check when unix comand is available  on the current system */  
  _bool (*check)(char * __restrict__ __gnu_linux_command); 
}; 



SUBP static void  binpaths_collections(const char  * __envar) ; 

#endif /**__SUBPROC_H*/

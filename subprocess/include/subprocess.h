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

#define  DEFSEP 0x3a  
 
#define  ENVAR_u1     0b1010000  
#define  ENVAR_u2     0b1000001   
#define  ENVAR_u3     0b1010100
#define  ENVAR_u4     0b1001000


#define  MAXBUFF 0xff 

#define  __elf_check(_binelf_) (access(_binelf_ ,  F_OK) != ~0  && access(_binelf_ , X_OK) != ~0)


typedef enum {  
  False, 
  True 
}_bool ; 

typedef enum   { 
#ifdef __linux__ 
  DEVNULL , 
#define DEVNULL /dev/null 
#else   
  DEVNULL, 
#define  DEVNULL  _nullable  
#endif 
  SHELL
#define  SHELL SHELL
} SH_ATTR; 



/** Subprocess data structure */ 
typedef  struct  __subprocess_t  Subp_t  ; 
struct __subprocess_t  {

  /**  Store all bin path location   in specified environment variable*/
  char binpaths[MAXBUFF][MAXBUFF]; 

  /** The last index binpath used */
  int  last_bp_index_used  ;  

  
  /*check when unix comand is available  on the current system */  
  int (*check)(const char * __restrict__  __gnu_linux_command); 
};

typedef union subpsh_attr_t  subpsh_attr_t ; 

/**
 *
 */
SUBP Subp_t  * 
subprocess_init(Subp_t * _subpt_instance , char * __local_envar ) ;

/**
 *
 */ 

SUBP int  
Popen(const char * __restrict__ __gnu_linux_command ,  char ** __args ,   subpsh_attr_t *  __out_redirect) ; 
/**
 *
 */
SUBP static char *
binpaths_collections(const char *__restrict__  __envar) ; 

/**
 * 
 */
SUBP static int 
is_set(const char * __restrict__  __gnu_linux_command) ; 




#endif /**__SUBPROC_H*/

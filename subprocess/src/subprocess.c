/** @file  subprocess.c
 *  @brief subprocess  call 
 *  @copyright (c) 2023
 *  @author  Umar Ba (Jukoo) LoopFocus 'Software Craftsmanship' 
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


static char bp_collectors[MAXBUFF][MAXBUFF]={0} ;
static int  last_index ; 


Subp_t * subprocess_init(Subp_t  * subp_instance , char *local_environment_variables) {  
  
  binpaths_collections( local_environment_variables ) ; 
  
  memcpy(subp_instance->binpaths,  bp_collectors , MAXBUFF*MAXBUFF) ; 
  subp_instance->check=  is_set ;  
  return subp_instance ; 
}

static char *  binpaths_collections ( const char* restrict   envar ) { 
  
  char envar_trap[MAXBUFF >> 3] =  {ENVAR_u1 , ENVAR_u2, ENVAR_u3, ENVAR_u4}; 
  char default_sep[1]=  {[0]= DEFSEP } ;  

  
  if (envar != _nullable) 
  { 
    explicit_bzero(envar_trap , MAXBUFF >> 3)  ; 
    (void) memcpy(envar_trap , envar , strlen(envar)) ; 
  }

  char *envar_values = getenv(envar_trap) ; 
  if (envar_values ==  _nullable)  
  {
    errx(~0 ,  "No Values Found for  %s\n", envar_trap) ; 
  }
  
  int  next=0 ; 
  char *binpath = strtok(envar_values ,  default_sep) ; 
  
  while (  binpath != _nullable )
  {
    memcpy( (bp_collectors + next ) ,  binpath , strlen(binpath)) ; 
    next++;
    binpath= strtok(_nullable , default_sep) ; 
  }

  if ( strlen(bp_collectors[0])  > 0 ) return  *bp_collectors  ;  
  return _nullable ; 
}




static int  is_set(const char *  gl_cmd) { 
  
  if  (gl_cmd ==_nullable) return  ~0;  
  
  char endpoint[MAXBUFF >>3] =  {[0]=0x2f} ; 
  memcpy( (endpoint+1) , gl_cmd , strlen(gl_cmd) ) ; 
  
  char xbin_location[MAXBUFF >> 3] = {0} ; 
  int  path_index =0   ; 
  
  while (bp_collectors[path_index] != 0)   
  {
    memcpy(xbin_location , bp_collectors[path_index] , strlen(bp_collectors[path_index])); 
    strcat(xbin_location ,endpoint) ;

    if (__elf_check(xbin_location)) 
    {
      last_index = path_index ; 
      return path_index ;   
    }
    
    memset(xbin_location , 0 , MAXBUFF>>3) ; 
    path_index++ ; 
  }

  return ~path_index ;  
}

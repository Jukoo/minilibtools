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



static void binpaths_collections ( const char*  envar ) { 
  
  char envar_trap[MAXBUFF >> 3] = _gnu_linux_envar_path_reference ; 
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
  char *binpath = strtok(envar_values ,  _gnu_linux_envar_path_sep_symbol) ; 
  
  while (  binpath != _nullable )
  {
    memcpy( (bp_collectors + next ) ,  binpath , strlen(binpath)) ; 
    next++;
    binpath= strtok(_nullable , _gnu_linux_envar_path_sep_symbol) ; 
  }

   
}

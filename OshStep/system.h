/*
 * system.h
 *
 * This file is used to initialize things about our system
 * In particular, we define _sbrk for our system in order to
 * use malloc() and free()
 *
 * Created: 2/16/2015 4:56:37 PM
 *  Author: hawthm
 */ 


#ifndef SYSTEM_H_
#define SYSTEM_H_

#ifdef DUEREV1
#include "DueRev1.h"
#endif

/*
#include <sys/types.h>
#include <cstddef>
#include <errno.h>
#include <assert.h>
#include <cstring>


extern unsigned char* _sheap;
extern unsigned char* _eheap;
extern unsigned char* _ram_end_;

extern "C" caddr_t _sbrk(ptrdiff_t __incr)
{
    static unsigned char* heap = NULL;
    unsigned char* prev_heap;
    
    if(heap == NULL)
    {
        heap = (unsigned char*)&_sheap;
    }
    prev_heap = heap;
    
    if((heap + __incr) > (unsigned char*)&_eheap)
    //if((heap + __incr) > (unsigned char*)&_ram_end_)
    {
        errno = ENOMEM;
        assert(strerror(errno));
        //__BKPT(0);
        return (caddr_t) 0;
    }
    
    heap += __incr;
    return(caddr_t) prev_heap;
}
*/

#endif /* SYSTEM_H_ */
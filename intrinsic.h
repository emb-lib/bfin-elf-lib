//******************************************************************************
//*
//*    Blackfin/bfin-elf support library
//*    
//*    Copyright (c) 2016, Harry E. Zhurov
//*
//******************************************************************************

#ifndef INTRINSIC_H
#define INTRINSIC_H

//------------------------------------------------------------------------------
//

//------------------------------------------------------------------------------
inline uint32_t read_cycles_reg() 
{
    uint32_t rval; 
    __asm__ __volatile__ ("%0 = CYCLES;" : "=d"(rval)); 
    return rval;
}
//------------------------------------------------------------------------------
inline uint32_t __cli() 
{
    uint32_t rval; 
    __asm__ __volatile__ ("cli %0;" : "=d"(rval));
    return rval;
}
//------------------------------------------------------------------------------
inline void __sti(uint32_t x) 
{
    __asm__ __volatile__ ("sti %0;" : : "d"(x));
}
//------------------------------------------------------------------------------

#endif  // INTRINSIC_H

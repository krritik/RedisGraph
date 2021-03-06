//------------------------------------------------------------------------------
// GB_code_compatible: return true if domains are compatible
//------------------------------------------------------------------------------

// SuiteSparse:GraphBLAS, Timothy A. Davis, (c) 2017-2018, All Rights Reserved.
// http://suitesparse.com   See GraphBLAS/Doc/License.txt for license.

//------------------------------------------------------------------------------

// Two domains are compatible for typecasting between them if both are built-in
// types (of any kind) or if both are the same user-defined type.  This
// function does not have the type itself, but just the code.  If the types are
// available, GB_Type_compatible should be called instead.

#include "GB.h"

bool GB_code_compatible         // check if two types can be typecast
(
    const GB_Type_code acode,   // type code of a
    const GB_Type_code bcode    // type code of b
)
{

    if (acode == GB_UDT_code || bcode == GB_UDT_code ||
        acode == GB_UCT_code || bcode == GB_UCT_code)
    { 
        // both a and b must be user-defined.  They should be the same
        // user-defined type, but the caller does not have the actual type,
        // just the code.
        return (acode == bcode) ;
    }
    else
    { 
        // any built-in domain is compatible with any other built-in domain
        return (true) ;
    }
}


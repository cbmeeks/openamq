/*---------------------------------------------------------------------------
    http_driver_null.h - http_driver_null component

    This class implements a driver module to ignore all methods.  This
    is used for testing stability in the server and clients.
    Generated from http_driver_null.icl by smt_object_gen using GSL/4.
    
    Copyright (c) 1996-2009 iMatix Corporation
    All rights reserved.
    
    This file is licensed under the BSD license as follows:
    
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:
    
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.
    * Neither the name of iMatix Corporation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
    
    THIS SOFTWARE IS PROVIDED BY IMATIX CORPORATION "AS IS" AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL IMATIX CORPORATION BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
    BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

    These header files use macros to implement a split inclusion in which all
    safe definitions (those that do not depend on the presence of other
    definitions) are done first, and all unsafe definitions are done in a
    second pass through the same headers.

    The first header file included from the main C program defines itself as
    the "root" and thus controls the inclusion of the safe/unsafe pieces of
    the other headers.
 *---------------------------------------------------------------------------*/

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 1)
# ifndef INCLUDE_HTTP_DRIVER_NULL_SAFE
#   define INCLUDE_HTTP_DRIVER_NULL_SAFE
#   define INCLUDE_HTTP_DRIVER_NULL_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_HTTP_DRIVER_NULL_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _http_driver_null_t http_driver_null_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_NULL)
#    define HTTP_DRIVER_NULL_HISTORY_LENGTH 32
#endif

#define HTTP_DRIVER_NULL_ALIVE          0xFABB
#define HTTP_DRIVER_NULL_DEAD           0xDEAD

#define HTTP_DRIVER_NULL_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL http_driver_null\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != HTTP_DRIVER_NULL_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "http_driver_null at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, HTTP_DRIVER_NULL_ALIVE, self->object_tag);\
        http_driver_null_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "http_driver_module.h"
#   include "http.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "http_driver_null_agent.h"

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_HTTP_DRIVER_NULL_ACTIVE
#   if defined (ICL_IMPORT_HTTP_DRIVER_NULL_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_HTTP_DRIVER_NULL_UNSAFE
#   define INCLUDE_HTTP_DRIVER_NULL_UNSAFE
#   define INCLUDE_HTTP_DRIVER_NULL_ACTIVE

#   include "http_driver_module.h"
#   include "http.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "http_driver_null_agent.h"
//  Global variables

extern Bool
    http_driver_null_animating;

//  Structure of the http_driver_null object

struct _http_driver_null_t {
    volatile int
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_NULL)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [HTTP_DRIVER_NULL_HISTORY_LENGTH];
    int
        history_line  [HTTP_DRIVER_NULL_HISTORY_LENGTH];
    char
        *history_type [HTTP_DRIVER_NULL_HISTORY_LENGTH];
    int
        history_links [HTTP_DRIVER_NULL_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
smt_thread_t
    *thread;
ipr_looseref_list_t
    *http_driver_module_list;       //  List of portals
Bool
    http_driver_module_stopped;     //  Is this portal stopped?
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
int
    http_driver_null_announce (
http_driver_null_t * self,              //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
smt_log_t * log                         //  Not documented
);

#define http_driver_null_new()          http_driver_null_new_ (__FILE__, __LINE__)
http_driver_null_t *
    http_driver_null_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    http_driver_null_terminate (
void);

http_driver_module_t *
    http_driver_null__http_driver_module_new (
void * self_v,                          //  Untyped server reference
char * path                             //  Not documented
);

http_driver_module_t *
    http_driver_null__http_driver_module_factory (
char * path                             //  Not documented
);

int
    http_driver_null__http_driver_module_unbind (
http_driver_null_t * self,              //  Reference to object
http_driver_module_t * portal           //  Portal reference
);

int
    http_driver_null_get (
http_driver_null_t * self,              //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
http_driver_context_t * context         //  Not documented
);

int
    http_driver_null_head (
http_driver_null_t * self,              //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
http_driver_context_t * context         //  Not documented
);

int
    http_driver_null_post (
http_driver_null_t * self,              //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
http_driver_context_t * context         //  Not documented
);

int
    http_driver_null_put (
http_driver_null_t * self,              //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
http_driver_context_t * context         //  Not documented
);

int
    http_driver_null_delete (
http_driver_null_t * self,              //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
http_driver_context_t * context         //  Not documented
);

int
    http_driver_null_move (
http_driver_null_t * self,              //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
http_driver_context_t * context         //  Not documented
);

int
    http_driver_null_copy (
http_driver_null_t * self,              //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
http_driver_context_t * context         //  Not documented
);

void
    http_driver_null_selftest (
void);

#define http_driver_null_destroy(self)  http_driver_null_destroy_ (self, __FILE__, __LINE__)
int
    http_driver_null_destroy_ (
http_driver_null_t * ( * self_p ),      //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define http_driver_null_unlink(self)   http_driver_null_unlink_ (self, __FILE__, __LINE__)
void
    http_driver_null_unlink_ (
http_driver_null_t * ( * self_p ),      //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    http_driver_null_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define http_driver_null_free(self)     http_driver_null_free_ (self, __FILE__, __LINE__)
void
    http_driver_null_free_ (
http_driver_null_t * self,              //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define http_driver_null_show(item,opcode,trace_file)  http_driver_null_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    http_driver_null_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define http_driver_null_link(self)     http_driver_null_link_ (self, __FILE__, __LINE__)
http_driver_null_t *
    http_driver_null_link_ (
http_driver_null_t * self,              //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define http_driver_null_new_in_scope(self_p,_scope)  http_driver_null_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    http_driver_null_new_in_scope_ (
http_driver_null_t * * self_p,          //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_HTTP_DRIVER_NULL_ACTIVE
#   if defined (ICL_IMPORT_HTTP_DRIVER_NULL_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_HTTP_DRIVER_NULL_INLINE)
#   define INCLUDE_HTTP_DRIVER_NULL_INLINE
#   define INCLUDE_HTTP_DRIVER_NULL_ACTIVE

#   include "http_driver_module.h"
#   include "http.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "http_driver_null_agent.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_HTTP_DRIVER_NULL_ACTIVE
#   if defined (ICL_IMPORT_HTTP_DRIVER_NULL_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_HTTP_DRIVER_NULL_ROOT
#   endif
# endif
#endif

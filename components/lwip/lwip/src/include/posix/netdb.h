/**
 * @file
 * This file is a posix wrapper for lwip/netdb.h.
 */

/*
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 */

#ifndef _LWIP_NETDB_H
#define _LWIP_NETDB_H

#include "lwip/netdb.h"

#ifdef ESP_PLATFORM
int getnameinfo(const struct sockaddr *addr, socklen_t addrlen,
                char *host, socklen_t hostlen,
                char *serv, socklen_t servlen, int flags);

#endif

// Lua RTOS additions
struct hostent *gethostbyname(const char *name);
struct hostent *gethostbyaddr(const void *addr, socklen_t len, int type);
const char *hstrerror(int err);

#include "lwip/sockets.h"

#define EAI_OVERFLOW 208

 struct servent {
      char  *s_name;       /* official service name */
      char **s_aliases;    /* alias list */
      int    s_port;       /* port number */
      char  *s_proto;      /* protocol to use */
   };

/*
 * Error return codes from getaddrinfo()
 */
 #define EAI_ADDRFAMILY   1      /* address family for hostname not supported */
 #define EAI_NODATA       7      /* no address associated with hostname */
 #define EAI_SOCKTYPE    10      /* ai_socktype not supported */
 #define EAI_SYSTEM      11      /* system error returned in errno */
 #define EAI_BADHINTS    12
 #define EAI_PROTOCOL    13
 #define EAI_MAX         14

/*
 * Constants for getnameinfo()
 */
#define    NI_MAXHOST  1025
#define    NI_MAXSERV  32

/*
 * Flag values for getnameinfo()
 */
#define    NI_NOFQDN   0x00000001
#define    NI_NUMERICHOST  0x00000002
#define    NI_NAMEREQD 0x00000004
#define    NI_NUMERICSERV  0x00000008
#define    NI_DGRAM    0x00000010
#define NI_WITHSCOPEID 0x00000020

#ifndef AF_UNIX
#define    AF_UNIX     1
#endif

int
 getnameinfo(const struct sockaddr *sa, socklen_t salen,
           char *host, size_t hostlen,
           char *serv, size_t servlen, int flags);

const char *gai_strerror(int ecode);

struct servent *getservbyname(const char *name, const char *proto);

#endif

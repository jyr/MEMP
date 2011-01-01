/* 
   +----------------------------------------------------------------------+
   | PHP Version 5                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2010 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Authors: The typical suspects                                        |
   |          Marcus Boerger <helly@php.net>                              |
   |          Pollita <pollita@php.net>                                   |
   +----------------------------------------------------------------------+
*/

/* $Id: php_dns.h 293036 2010-01-03 09:23:27Z sebastian $ */

#ifndef PHP_DNS_H
#define PHP_DNS_H

#if HAVE_RES_NMKQUERY && HAVE_RES_NSEND && HAVE_DN_EXPAND && HAVE_DN_SKIPNAME
#define HAVE_DNS_FUNCS 1
#endif

PHP_FUNCTION(gethostbyaddr);
PHP_FUNCTION(gethostbyname);
PHP_FUNCTION(gethostbynamel);

#if HAVE_RES_SEARCH && !(defined(__BEOS__) || defined(PHP_WIN32) || defined(NETWARE))
PHP_FUNCTION(dns_check_record);
# if HAVE_DN_SKIPNAME && HAVE_DN_EXPAND
PHP_FUNCTION(dns_get_mx);
# endif

# if HAVE_DNS_FUNCS
PHP_FUNCTION(dns_get_record);
PHP_MINIT_FUNCTION(dns);
# endif
#endif

#ifndef INT16SZ
#define INT16SZ		2
#endif

#ifndef INT32SZ
#define INT32SZ		4
#endif

#endif /* PHP_DNS_H */

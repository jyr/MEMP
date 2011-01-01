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
   | Author: Moriyoshi Koizumi <moriyoshi@php.net>                        |
   +----------------------------------------------------------------------+
 */

/* $Id: php_mbregex.h 293036 2010-01-03 09:23:27Z sebastian $ */
 
#ifndef _PHP_MBREGEX_H
#define _PHP_MBREGEX_H

#if HAVE_MBREGEX

#include "php.h"
#include "zend.h"
#include "oniguruma/oniguruma.h"

/* {{{ PHP_MBREGEX_GLOBALS */
#define PHP_MBREGEX_GLOBALS \
	OnigEncoding default_mbctype; \
	OnigEncoding current_mbctype; \
	HashTable ht_rc; \
	zval *search_str; \
	zval *search_str_val; \
	unsigned int search_pos; \
	php_mb_regex_t *search_re; \
	OnigRegion *search_regs; \
	OnigOptionType regex_default_options; \
	OnigSyntaxType *regex_default_syntax;
/* }}} */

/* {{{ PHP_MBREGEX_FUNCTION_ENTRIES */
#define PHP_MBREGEX_FUNCTION_ENTRIES \
	PHP_FE(mb_regex_encoding,	NULL) \
	PHP_FE(mb_regex_set_options,	NULL) \
	PHP_FE(mb_ereg,			third_arg_force_ref) \
	PHP_FE(mb_eregi,			third_arg_force_ref) \
	PHP_FE(mb_ereg_replace,			NULL) \
	PHP_FE(mb_eregi_replace,			NULL) \
	PHP_FE(mb_split,					NULL) \
	PHP_FE(mb_ereg_match,			NULL) \
	PHP_FE(mb_ereg_search,			NULL) \
	PHP_FE(mb_ereg_search_pos,		NULL) \
	PHP_FE(mb_ereg_search_regs,		NULL) \
	PHP_FE(mb_ereg_search_init,		NULL) \
	PHP_FE(mb_ereg_search_getregs,	NULL) \
	PHP_FE(mb_ereg_search_getpos,	NULL) \
	PHP_FE(mb_ereg_search_setpos,	NULL) \
	PHP_FALIAS(mbregex_encoding,	mb_regex_encoding,	NULL) \
	PHP_FALIAS(mbereg,	mb_ereg,	NULL) \
	PHP_FALIAS(mberegi,	mb_eregi,	NULL) \
	PHP_FALIAS(mbereg_replace,	mb_ereg_replace,	NULL) \
	PHP_FALIAS(mberegi_replace,	mb_eregi_replace,	NULL) \
	PHP_FALIAS(mbsplit,	mb_split,	NULL) \
	PHP_FALIAS(mbereg_match,	mb_ereg_match,	NULL) \
	PHP_FALIAS(mbereg_search,	mb_ereg_search,	NULL) \
	PHP_FALIAS(mbereg_search_pos,	mb_ereg_search_pos,	NULL) \
	PHP_FALIAS(mbereg_search_regs,	mb_ereg_search_regs,	NULL) \
	PHP_FALIAS(mbereg_search_init,	mb_ereg_search_init,	NULL) \
	PHP_FALIAS(mbereg_search_getregs,	mb_ereg_search_getregs,	NULL) \
	PHP_FALIAS(mbereg_search_getpos,	mb_ereg_search_getpos,	NULL) \
	PHP_FALIAS(mbereg_search_setpos,	mb_ereg_search_setpos,	NULL)
/* }}} */

typedef struct _zend_mbstring_globals * zend_mbstring_globals_ptr;

#define PHP_MBREGEX_MAXCACHE 50

PHP_MINIT_FUNCTION(mb_regex);
PHP_MSHUTDOWN_FUNCTION(mb_regex);
PHP_RINIT_FUNCTION(mb_regex);
PHP_RSHUTDOWN_FUNCTION(mb_regex);
void _php_mb_regex_globals_ctor(zend_mbstring_globals_ptr pglobals TSRMLS_DC);
void php_mb_regex_set_options(OnigOptionType options, OnigSyntaxType *syntax, OnigOptionType *prev_options, OnigSyntaxType **prev_syntax TSRMLS_DC);
void _php_mb_regex_globals_dtor(zend_mbstring_globals_ptr pglobals TSRMLS_DC);
OnigEncoding php_mb_regex_name2mbctype(const char *pname);
const char *php_mb_regex_mbctype2name(OnigEncoding mbctype);

PHP_FUNCTION(mb_regex_encoding);
PHP_FUNCTION(mb_ereg);
PHP_FUNCTION(mb_eregi);
PHP_FUNCTION(mb_ereg_replace);
PHP_FUNCTION(mb_eregi_replace);
PHP_FUNCTION(mb_split);
PHP_FUNCTION(mb_ereg_match);
PHP_FUNCTION(mb_ereg_search);
PHP_FUNCTION(mb_ereg_search_pos);
PHP_FUNCTION(mb_ereg_search_regs);
PHP_FUNCTION(mb_ereg_search_init);
PHP_FUNCTION(mb_ereg_search_getregs);
PHP_FUNCTION(mb_ereg_search_getpos);
PHP_FUNCTION(mb_ereg_search_setpos);
PHP_FUNCTION(mb_regex_set_options);

#endif /* HAVE_MBREGEX */

#endif /* _PHP_MBREGEX_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */


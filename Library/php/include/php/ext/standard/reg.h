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
   | Author: Rasmus Lerdorf <rasmus@lerdorf.on.ca>                        |
   +----------------------------------------------------------------------+
*/


/* $Id: reg.h 293036 2010-01-03 09:23:27Z sebastian $ */

#ifndef REG_H
#define REG_H

PHPAPI char *php_reg_replace(const char *pattern, const char *replace, const char *string, int icase, int extended);

PHP_FUNCTION(ereg);
PHP_FUNCTION(eregi);
PHP_FUNCTION(eregi_replace);
PHP_FUNCTION(ereg_replace);
PHP_FUNCTION(split);
PHP_FUNCTION(spliti);
PHPAPI PHP_FUNCTION(sql_regcase);

ZEND_BEGIN_MODULE_GLOBALS(reg)
	HashTable ht_rc;
	unsigned int lru_counter;
ZEND_END_MODULE_GLOBALS(reg)

PHP_MINIT_FUNCTION(regex);
PHP_MSHUTDOWN_FUNCTION(regex);
PHP_MINFO_FUNCTION(regex);


#ifdef ZTS
#define REG(v) TSRMG(reg_globals_id, zend_reg_globals *, v)
#else
#define REG(v) (reg_globals.v)
#endif

#endif /* REG_H */

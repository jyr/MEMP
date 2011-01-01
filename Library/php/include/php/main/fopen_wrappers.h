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
   | Author: Jim Winstead <jimw@php.net>                                  |
   +----------------------------------------------------------------------+
 */

/* $Id: fopen_wrappers.h 293036 2010-01-03 09:23:27Z sebastian $ */

#ifndef FOPEN_WRAPPERS_H
#define FOPEN_WRAPPERS_H

BEGIN_EXTERN_C()
#include "php_globals.h"

PHPAPI int php_fopen_primary_script(zend_file_handle *file_handle TSRMLS_DC);
PHPAPI char *expand_filepath(const char *filepath, char *real_path TSRMLS_DC);
PHPAPI char *expand_filepath_ex(const char *filepath, char *real_path, const char *relative_to, size_t relative_to_len TSRMLS_DC);

PHPAPI int php_check_open_basedir(const char *path TSRMLS_DC);
PHPAPI int php_check_open_basedir_ex(const char *path, int warn TSRMLS_DC);
PHPAPI int php_check_specific_open_basedir(const char *basedir, const char *path TSRMLS_DC);

PHPAPI int php_check_safe_mode_include_dir(const char *path TSRMLS_DC);

PHPAPI FILE *php_fopen_with_path(const char *filename, const char *mode, const char *path, char **opened_path TSRMLS_DC);

PHPAPI char *php_strip_url_passwd(char *path);
END_EXTERN_C()

#endif
/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 */

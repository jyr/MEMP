#/bin/sh
/Applications/MEMP/Library/mysql/bin/mysqld_safe --port=3306 --socket=/Applications/MEMP/tmp/mysql/mysql.sock --lower_case_table_names=0 --datadir=/Applications/MEMP/Library/mysql/data --pid-file=/Applications/MEMP/tmp/mysql/mysql.pid --log-error=/Applications/MEMP/logs/mysql_error_log &

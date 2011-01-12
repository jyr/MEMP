#/bin/sh

__show_usage( ) {
 
  echo "Usage: ${0} {start|stop}"
  exit 3
}


case "${1}" in
    start)
        /Applications/MEMP/Library/mysql/bin/mysqld_safe -u root --port=3306 --socket=/Applications/MEMP/tmp/mysql/mysql.sock --lower_case_table_names=0 --datadir=/Applications/MEMP/Library/mysql/data --pid-file=/Applications/MEMP/tmp/mysql/mysql.pid --log-error=/Applications/MEMP/logs/mysql_error_log --tmpdir=/Applications/MEMP/tmp/mysql &
        ;;
    stop)
        /Applications/MEMP/Library/mysql/bin/mysqladmin -u root --socket=/Applications/MEMP/tmp/mysql/mysql.sock shutdown
        ;;
    *)
        __show_usage
        ;;
esac
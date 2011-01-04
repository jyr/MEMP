#/bin/sh

__show_usage( ) {
 
  echo "Usage: ${0} {start|stop|quit|restart|reload|logrotate}"
  exit 3
}

__create_alias( ) {
    if [ ! -d "/usr/local/mysql" ]; then
        ln -s /Applications/MEMP/Library/mysql /usr/local/mysql
    fi
}

__export_library( ){
    if [[ ! $DYLD_LIBRARY_PATH =~ "/usr/local/mysql/lib" ]]; then
        export DYLD_LIBRARY_PATH=/usr/local/mysql/lib:$DYLD_LIBRARY_PATH
    fi
}

case "${1}" in
    start|stop|quit|restart|reload|logrotate)
        __create_alias
        __export_library
        /Applications/MEMP/Library/php/sbin/php-fpm ${1}
        ;;
    *)
      __show_usage 
      ;;
esac
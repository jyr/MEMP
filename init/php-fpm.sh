#/bin/sh

__create_alias( ) {
    if [ ! -d "/usr/local/mysql" ]; then
        ln -s /Applications/MEMP/Library/mysql /usr/local/mysql
    fi
}

__set_privilegies( ) {
   chown -R mysql:mysql /usr/local/mysql/
   chown -R mysql:mysql /Applications/MEMP/tmp/mysql
}

__export_library( ){
    export DYLD_LIBRARY_PATH=/Applications/MEMP/Library/lib:$DYLD_LIBRARY_PATH
}

__show_usage( ) {
 
  echo "Usage: ${0} {start|stop|quit|restart|reload|logrotate}"
  exit 3
}

__create_alias
__set_privilegies
__export_library

case "${1}" in
    start|stop|quit|restart|reload|logrotate)
        /Applications/MEMP/Library/php/sbin/php-fpm ${1}
        ;;
    *)
      __show_usage 
      ;;
esac
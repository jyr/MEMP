#/bin/sh

__show_usage( ) {
 
  echo "Usage: ${0} {start|stop|quit|restart|reload|logrotate}"
  exit 3
}

case "${1}" in
    start|stop|quit|restart|reload|logrotate)
        /Applications/MEMP/Library/php/sbin/php-fpm ${1}
        ;;
    *)
      __show_usage 
      ;;
esac
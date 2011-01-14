#/bin/sh

__init( ) {
    sh /Applications/MEMP/init/php-fpm.sh start
    sh /Applications/MEMP/init/mysql.sh start
    sh /Applications/MEMP/init/nginx.sh start
}

__init

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
    if [[ ! $DYLD_LIBRARY_PATH =~ "/usr/local/mysql/lib" ]]; then
        export DYLD_LIBRARY_PATH=/usr/local/mysql/lib:$DYLD_LIBRARY_PATH
    fi
}

__init( ) {
    sh /Applications/MEMP/init/php-fpm.sh start
    sh /Applications/MEMP/init/mysql.sh start
    sh /Applications/MEMP/init/nginx.sh start
}

__create_alias
__set_privilegies
__export_library
__init

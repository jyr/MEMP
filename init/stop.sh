#/bin/sh

sh /Applications/MEMP/init/php-fpm.sh stop
sh /Applications/MEMP/init/mysql.sh stop
sudo sh /Applications/MEMP/init/nginx.sh stop
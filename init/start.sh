#/bin/sh

sh /Applications/MEMP/init/php-fpm.sh start
sh /Applications/MEMP/init/mysql.sh start
sudo sh /Applications/MEMP/init/nginx.sh start
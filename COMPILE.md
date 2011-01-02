Freetype
---
./configure --prefix=/Applications/MEMP/Library/freetype

Curl
----
./configure --prefix=/Applications/MEMP/Library/curl


JPEG
---
./configure --prefix=/Applications/MEMP/Library/jpeg


Libpng
---
./configure --prefix=/Applications/MEMP/Library/libpng


GD
---
./configure --prefix=/Applications/MEMP/Library/gd


LibXML
---
./configure --prefix=/Applications/MEMP/Library/libxml


LibXSLT
---
./configure --prefix=/Applications/MEMP/Library/libxslt


Gettext
---
./configure --prefix=/Applications/MEMP/Library/gettext


LibMCRYPT
---
./configure --prefix=/Applications/MEMP/Library/mcrypt


MCRYPT
---
./configure --prefix=/Applications/MEMP/Library/mcrypt


PHP
---


./configure --prefix=/Applications/MEMP/Library/php --exec-prefix=/Applications/MEMP/Library/php --enable-cli --enable-gd-jis-conv --enable-gd-native-ttf --enable-mbstring --with-bz2 --with-curl=/Applications/MEMP/Library/curl --with-gd=/Applications/MEMP/Library/gd --with-gettext=shared,/Applications/MEMP/Library/gettext --with-freetype-dir=/Applications/MEMP/Library/freetype --with-jpeg-dir=/Applications/MEMP/Library/jpeg --with-libxml-dir=/Applications/MAMP/Library/libxml --with-xsl=/Applications/MAMP/Library/libxslt --with-mcrypt=shared,/Applications/MEMP/Library/mcrypt --with-mhash --with-mysql=/Applications/MEMP/Library/mysql --enable-sockets --with-mysqli=/Applications/MEMP/Library/mysql/bin/mysql_config  --with-openssl --with-png-dir=/Applications/MEMP/Library/libpng --with-readline --with-ttf --with-xpm-dir=/Applications/MEMP/Library/xpm --with-zlib --with-config-file-path=/Applications/MEMP/conf/php5 --enable-fastcgi --enable-fpm --enable-force-cgi-redirect --with-fpm-conf=/Applications/MEMP/conf/php5/php-fpm --with-fpm-log=/Applications/MEMP/logs/php-fpm.log --with-fpm-pid=/Applications/MEMP/tmp/php/php-fpm.pid --with-libedit --enable-libxml --enable-dom --disable-all

make 

make install

NGINX
---

./configure --prefix=/Applications/MEMP/Library/nginx --sbin-path=/Applications/MEMP/Library/nginx --conf-path=/Applications/MEMP/conf/nginx/nginx.conf --user=nobody --group=nobody --with-http_ssl_module --with-http_stub_status_module --pid-path=/Applications/MEMP/tmp/nginx --with-http_gzip_static_module --with-pcre=/Applications/MEMP/src/pcre-8.11/

make

make install
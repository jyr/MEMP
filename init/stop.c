#include <stdio.h>

int main(){
    system("sh /Applications/MEMP/init/php-fpm.sh stop");
    system("sh /Applications/MEMP/init/mysql.sh stop");
    system("sh /Applications/MEMP/init/nginx.sh stop");
    return 0;
}
#include <stdio.h>

int main(){
    system("sh /Applications/MEMP/init/php-fpm.sh start");
    //system("sh /Applications/MEMP/init/mysql.sh start");
    system("sh /Applications/MEMP/init/nginx.sh start");
    return 0;
}
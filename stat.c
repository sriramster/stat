#include <stdio.h>
#include <stdlib.h>

int get_disk_status()
{
     char *cmd = "sudo -A su -c 'fdisk -l' | awk -f filters/disk.awk";
     system(cmd);
     return 0;
}

int get_general_devstat()
{
     char *cmd = "uname -a | awk -f filters/gen.awk";
     system(cmd);
     return 0;
}

int get_user_details()
{
     char *cmd = "awk -f filters/user.awk < /etc/passwd";
     system(cmd);
     return 0;
}

/* int run_smart_on(char dsk, char opt)  */
/* { */
/* } */

int get_network_stat()
{
     char *cmd = "ip -oneline link show | awk \'{print $2}\' | sed 's/://'";
     system(cmd);
     return 0;
}

int main()
{
     get_disk_status();
     get_general_devstat();
     get_network_stat();
     get_user_details();
     return 0;
}

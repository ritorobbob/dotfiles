/******************************************************************
 ******************************************************************
 ** #include<./cmd.h>     use as follows:				  		 **
 **--------------------------------------------------------------**
 **	char *standardOutputFromCommand;							 **
 **	char command[] = "echo hello";								 **
 **	standardOutputFromCommand = cmd(command);					 **
 **--------------------------------------------------------------**
 **	char *standardOutputFromCommand;							 **
 **	standardOutputFromCommand = cmd("echo 'hello world'");		 **
 ******************************************************************
 *****************************************************************/
#include<cmd.h>

int main(){
	int i = 0;
	char *checkForNM;
	checkForNM = cmd("sudo ls /var/service/NetworkManager");
	printf("%c", *checkForNM);
	char *ans;
	if (*checkForNM == *"s"){
		ans = cmd("echo 'Enable\nDisable' | dmenu -i -p 'nm(enabled): '");
	}else {
		ans = cmd("echo 'Enable\nDisable' | dmenu -i -p 'nm(enabled): '");
	}
	if (*ans == *"s"){
		cmd("rm -fr /var/service/dhcpcd");
		cmd("rm -fr /var/service/wpa_supplicant");
		cmd("ln -s /etc/sv/NetworkManager /var/service");
		cmd("ln -s /etc/sv/dbus /var/service");
		cmd("sv restart NetworkManager");
		cmd("sleep 5");
		cmd("nm-applet &");
	}else{
		cmd("rm -fr /var/service/dbus");
		cmd("rm -fr /var/service/NetworkManager");
		cmd("ln -s /etc/sv/dhcpcd /var/service");
		cmd("sv restart wpa_supplicant");
	}

	return 0;
}

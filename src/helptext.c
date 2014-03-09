// Note: Just #define HELPTEXT would also need trailing slashes...

const char* HELP_TEXT
= _T("Manipulate User, System and Session environment variables in the Registry.\n"
"\n"
"Usage: regenv [action] [-options...] [varname] [value]\n"
//!!TODO: "Usage: winenv [action] [-options...] [varname] [value] [command [args...]]\n\n"
"\n"
"  actions & parameters:\n"
"\n"	
"	set [opts] VARIABLE VALUE     Set VARIABLE to VALUE.\n"
"	del [opts] VARIABLE [VALUE]   Delete VARIABLE (or VALUE from it).\n"
"	                              (If VALUE is given, -s is implied.)\n"
"	check [opts] VARNAME [VALUE]  Is VARNAME set (to VALUE, or does it\n"
"	                              have VALUE, if -s is used, see below)?\n"
"	show [VARNAME]       	      Show variable(s) named VARNAME*.\n"
"	notify                        Tell other processes to refresh their env.\n"
"	help (or /? or -h)            Show help. This is the default action.\n"
"\n"
"  options (Invalid combinations will have undefined results!):\n"
"\n"
"    -n<SELECTOR...> Lookup <varname> at the selected place(s):\n"
"	   U	--> the User namespace (HKCU\\Environment).\n"
"	   S	--> the System namespace (HKLM\\SYSTEM\\CurrentControlSet\n"
"                  	\\Control\\Session Manager\\Environment)\n"
"	   V	--> the Session namespace (HKCU\\Volatile Environment).\n"
"		    This is the default.\n"
//!!TODO: "          E	--> environment of the executed <command>.\n" // becomes default if <command> given
"\n"
"    -s	\"Subvalue\" mode: treat VALUE as a part of VARIABLE, where\n"
"	VARIABLE is assumed to have a list of parts separated by\n"
"	the delimiter specified with the -d option. In this mode:\n"
"	1) set adds VALUE to VARIABLE if VALUE is not part of it,\n"
"	2) del removes VALUE from VARIABLE if it is part of it,\n"
"	3) check examines if VALUE is part of VARIABLE.\n"
"	These operations are not case-sensitive (unless -c is used),\n"
"	and treat '/' and '\\' chars as being equal (unless raw mode\n"
"	is selected with -r).\n"
"\n"
"    -d[CHAR] Use CHAR as the delimiter for -s.\n"
"	If -d or CHAR is omitted, ';' will be used.\n"
"\n"
"    -r	Raw mode: skip slash conversion for -s.\n"
"\n"
"    -c	Case-sensitive mode for -s.\n"
"\n"
"    -a	Append to the current value of VARIABLE. Implies -s.\n"
"   	This is the default.\n"
"\n"
"    -p	Prepend to the current value of VARIABLE. Implies -s.\n"
"\n"
"    -x	Set as REG_EXPAND_SZ string (for delayed %var% substitutions).\n"
"	Or: check -x will prevent auto-expanding the value of VARIABLE.\n"
"\n"
"    -!	Also do 'notify' after 'set' or 'del'.\n"
"\n"
"    -e	Show examples.\n"
"\n"	
"Return Values:\n"
"\n"
"    0	Success (or 'VALUE FOUND' by 'check').\n"
"    1	'VALUE NOT FOUND' by 'check'.\n"
"    2	Unspecified error. (Error messages go to stderr.)\n"
"    5	Access denied.\n"
"\n"
"Notes:\n"
"	- Multiple -options can be combined into one -optionlist sequence.\n"
"	- The U, S, V modifiers can be freely combined.\n"
"	- Calling from the CMD shell, use the \"^%SOMEVAR^%\" escape\n"
"	  syntax (or \"%%SOMEVAR%%\" from batch files) to allow setting\n"
"	  auto-expanding (\"REG_EXPAND_SZ\") values with -x.\n"
"	- Use double quotes around any value which contains spaces.\n"
"	- The 'set' action will create the variable, if needed.\n"
"\n"
"!!!NOTE NOTE NOTE NOTE NOTE!!!\n"
"   - The 'check' action, -r, -i and -d are not implemented yet!\n"
"!!!NOTE NOTE NOTE NOTE NOTE!!!\n"
);


const char* EXAMPLES_TEXT
= _T(
"Examples:\n"
"winenv set -nU INSTALLPATH C:\\SetEnv \n"
"	Set the User variable INSTALLPATH to \"C:\\SetEnv\".\n"
"\n"
"winenv set -nS MEDIA C:\\Media \n"
"	Sets the System variable MEDIA to \"C:\\Media\".\n"
"\n"
"winenv set -sp PATH D:\\Bin \n"
"	Prepends \"D:\\Bin\" to the PATH.\n"
"\n"
"winenv set PATH \"D:\\Bin;%PATH%\"\n"
"	Ditto, but does not check & prevent duplicate D:\\Bin.\n"
"\n"
//!!"winenv -a MUSIC ~MEDIA~\\Music \n\tSets the value of MUSIC to be ALWAYS equal to the value of MEDIA\\Music,\n"
//!!"\teven if the value of MEDIA changes, so MUSIC becomes \"C:\\Media\\Music\".\n"
//!!"\tIf MEDIA becomes \"D:\\Media\" then MUSIC becomes \"D:\\Media\\Music\", etc.\n"
);

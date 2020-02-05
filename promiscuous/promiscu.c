#include "hexchat-plugin.h"
#include <string.h>

#define PNAME "Promiscuous"
#define PDESC "View all conversations in one tab"
#define PVERSION "0.1"

#define SERV "freenode"			/* whose tab? */

static hexchat_plugin *ph;		/* plugin handle */

/* https://stackoverflow.com/a/7666577 */
unsigned char hash(unsigned char *str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
		hash = ((hash << 5) + hash) + c;	/* hash * 33 + c */

	return hash;
}

static int privmsg_cb(char *word[], char *word_eol[], void *userdata)
{
	/* to be shown */
	char nick[16];
	char msg[512] = "\3";

	/* extract nick */
	char i;
	for (i = 1; word[1][i] != '!'; i++) {
		nick[i - 1] = word[1][i];
	}
	nick[i - 1] = 0;

	/* set msg color according to hash of chan */
	char const map[] = { 1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 13, 14 };
	char const color = map[hash(word[3] + 1) % 12];
	msg[1] = '0' + color / 10;
	msg[2] = '0' + color % 10;

	/* extract msg */
	strcpy(msg + 3, word_eol[4] + 2);

	/* it's time */
	hexchat_set_context(ph, hexchat_find_context(ph, SERV, SERV));
	hexchat_emit_print(ph, "Channel Message", nick, msg, NULL);

	/* better not tell other plugins */
	return HEXCHAT_EAT_PLUGIN;
}

void
hexchat_plugin_get_info(char **name, char **desc, char **version,
						void **reserved)
{
	*name = PNAME;
	*desc = PDESC;
	*version = PVERSION;
}

int
hexchat_plugin_init(hexchat_plugin * plugin_handle, char **plugin_name,
					char **plugin_desc, char **plugin_version, char *arg)
{
	/* we need to save this for use with any hexchat_* functions */
	ph = plugin_handle;

	/* tell HexChat our info */
	*plugin_name = PNAME;
	*plugin_desc = PDESC;
	*plugin_version = PVERSION;

	/* what we're interested in */
	hexchat_hook_server(ph, "PRIVMSG", HEXCHAT_PRI_NORM, privmsg_cb, NULL);

	hexchat_print(ph, "PromiscuousPlugin loaded successfully!\n");

	/* return 1 for success */
	return 1;
}

int hexchat_plugin_deinit(hexchat_plugin * plugin_handle)
{
	hexchat_print(ph, "Unloading PromiscuousPlugin");
	return 1;					/* return 1 for success */
}

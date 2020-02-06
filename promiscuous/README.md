# Promiscuous

This plugin is no longer actively maintained.

Promiscuous combines chat messages in different channels into one tab and colors them, useful when you're lurking in a lot of channels. The end result looks something like [this](http://www.allthingsjacq.com/ifMUDfaq/faq1.html) (about 3/5 down the page, the colorful bit. Also the inspiration).

The plugin is optimized for freenode.

## What it offers

- mIRC-based message coloring for server-side `PRIVMSG`s from ALL networks
- everything displayed in one server tab
- same channel, same color (but not the other way around!)

## What it does NOT offer

- [more than 16 colors](https://en.wikipedia.org/wiki/Pigeonhole_principle)
- background colors
- forced coloring (preserves original color codes in messages)
- guaranteed readability (depends on the colors used)
- coloring for anything that is not a server-side `PRIVMSG` (including your own `PRIVMSG`s, join/part messages, etc)
- an additional way to send messages to channels (think of read-only)
- an exclusive tab/window for messages (might require some moby hack for that)
- guaranteed feasibility for networks other than freenode (say, Rizon)
- arbitrary tab for messages (an easy hack, though)
- ON/OFF commands
- @, +, and so on with nicks
- colored nicks in regard to channels
- special care for CTCP stuff (so features like `/me` might show up weird)

I believe most of the above can be achieved with relative ease, but they are either not useful or not as important ~and I'm too lazy~ so that's it for now.

## Installation

First, change the `#define SERV` part to match your need, if necessary (all messages go to this server tab). Then, [compile](https://hexchat.readthedocs.io/en/latest/plugins.html#introduction) (with [this](https://github.com/hexchat/hexchat/blob/master/src/common/hexchat-plugin.h)), and you are ready to go.

## Acknowledgements

The code is based on the sample plugin [here](https://hexchat.readthedocs.io/en/latest/plugins.html#sample-plugin).

The hash function is taken from Stack Overflow, link in the code.

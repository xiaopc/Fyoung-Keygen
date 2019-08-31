# Fyoung-Keygen

A keygen of China Telecom Fyoung Dialer.

## Sketch

Decompile from v2.23 macOS dialer.

The keygen can generate the true username of PPPoE dial.

&copy; 2018 xiaopc, all rights reserved & profitable use forbidden. 

**Legal notice: you should realize that ALL THE CONSEQUENCES, INCLUDING LEGAL LIABILITY, WERE ON YOUR OWN IF YOU USE THIS PROGRAM!**

## Compile

The keygen is designed for routers, you would like to use specific toolchain, e.g. mipsel-openwrt-linux-uclibc-gcc.

```bash
gcc -c MD5.c -std=c99
gcc -c fyoung.c -std=c99
gcc -o fyoung fyoung.o MD5.o
```

## Usage

### OpenWRT/LEDE

*Here's a [detailed introduction in Chinese by Mr. Xiao](https://mrxiao.net/openwrt-cross-compile.html), thanks.*

In router's `ppp.sh` (maybe locating at `/lib/netifd/proto/`) , after where username & password variables are generated , e.g.:

```bash
json_get_vars ipv6 demand keepalive keepalive_adaptive username password pppd_options pppname unnumbered
```

Add:

```bash
username=`/usr/sbin/fyoung $username $password`
```

*Notice: <kbd>\`</kbd> is grave accent mark, while <kbd>\'</kbd> is single quotation mark. [Learn more](https://en.wikipedia.org/wiki/Grave_accent#Use_in_programming).*

When dialing, add `tyfy` before your username(if not, it will return the original username).

### Other routers based on Linux (including ASUS/Padavan)

Your router firmware may not run `pppd` by shell, so it can't be configured easily by changing a script.

However, `pppd` can load a `*.so` plugin. The problem would be solved if we provide a plugin-based version.

Unfortunately, we have not started this work(for now).

(btw, it's difficult to set up the environment for compiling plugins)

You are welcome to open a [pr](../../pulls)!

## Others

Sorry, we can not support your device.

You should consider buy another router, or just build this on your local device then dial manually.

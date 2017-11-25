# Fyoung-Keygen
A keygen of China Telecom Fyoung SCU Jiangan Dialer

## Sketch

Decompile from v2.23 macOS dialer(single dialing).

The keygen can generate the true username of PPPOE dial.

**Notice: This keygen doesn't handle the heartbeat packets, so the connection may be aborted once in a while.**

&copy; 2017 xiaopc, all rights reserved & profitable use forbidden. 

## Compile

The keygen is designed for routers, you may want to use specific toolchain, e.g. mipsel-openwrt-linux-uclibc-gcc.

```bash
gcc -c MD5.c -std=c99
gcc -c fyoung.c -std=c99
gcc -o fyoung fyoung.o MD5.o
```

## Usage

In router's `ppp.sh` (mine locates at `/lib/netifd/proto/`) , after where username & password was recived, such as:

```bash
json_get_vars ipv6 demand keepalive keepalive_adaptive username password pppd_options pppname unnumbered
```

Add:

```
username=`/usr/sbin/fyoung $username $password`
```

When dialing, add `tyfy` before your username(if not, it will return original username).
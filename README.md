# Fyoung-Keygen
A keygen of China Telecom Fyoung SCU Jiangan Dialer

## Compile

The keygen is designed for routers, you may want to use MIPS toolchain,

e.g. mipsel-openwrt-linux-uclibc-gcc.

```bash
gcc -c MD5.c -std=c99
gcc -c fyoung.c -std=c99
gcc -o fyoung fyoung.o MD5.o
```

## Usage

In router's `ppp.sh` (mine locates at `/lib/netifd/proto/`) , after username & password read, such as:

```bash
json_get_vars ipv6 demand keepalive keepalive_adaptive username password pppd_options pppname unnumbered
```

Add:

```
username=`/usr/sbin/fyoung $username $password`
```


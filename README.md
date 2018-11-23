# 😀 linux ping 辣鸡版
---
> FBI warning: 这个程序你需要在 linux 上运行，而不是 windows，请不要尝试在 windows 上编译或运行之

所谓 `ping`，大家都不会陌生，`ping` 是试探某个 `IP` 或域名是否存在 `alive` 的主机的程序，原生的 `ping` 在各个操作系统上都有实现，原理都是使用 `ICMP` 包。

这里我写了一个 `linux` 系统上的 `ping` 程序，作为 `NUAA 网络通信实现技术` 的课设，基本功能与原生 `ping` 一直，但是少了很多控制参数。

# 💻 编译
项目工程采用了 `cmake` 来进行管理，在使用之前，你需要先安装 `cmake` (Version > 3.7) 和编译套件，安装指令以 `debian/ubuntu` 为例:

```
sudo apt-get install cmake
sudo apt-get install build-essential
```

完成之后，进入克隆下来的项目根目录：

```
cd ./ping
```

使用 `cmake` 生成 `makefile`：

```
cmake .
```

开始编译：

```
make
```

# 🏃 运行 / Usage
基本运行：

```
sudo ./ping ipAddress [-n] [sendTime] [-l] [icmpDataLength]
```

参数说明：

* `[-n] [sendTime]`: 使用 `-n` 来指定试探次数
* `[-l] [icmpDataLength]`：使用 `-l` 来指定 `ICMP` 数据段的长度

# 😘 关于
* 江湖艺名：John Kindem
* `NUAA ID`: 161520311

觉得不错的话记得点个小星星 ⭐

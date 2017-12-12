二进制差量工具工具bsdiff 服务端编译

- 下载
```
wget http://www.daemonology.net/bsdiff/bsdiff-4.3.tar.gz
tar zxvf bsdiff-4.3.tar.gz
cd bsdiff-4.3
```
- 编译

修改Makefile 在倒数第一行 第三行 加TAB

然后执行make

make 报错请先安装ZIP2

执行下面命令安装(RHEL/CENTOS)

yum install bzip2-devel

编译完成后，会在目录下生成2个二进制文件：

bsdiff

bspatch

这2个二进制文件可以直接使用


也可以拷贝到/usr/local/sbin/下

cp bsdiff /usr/local/sbin/

cp bspatch /usr/local/sbin/

: bsdiff -h
bsdiff: usage: bsdiff oldfile newfile patchfile

: bspatch -h
bspatch: usage: bspatch oldfile newfile patchfile
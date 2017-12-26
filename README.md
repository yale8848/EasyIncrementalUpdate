# EasyIncrementalUpdate

Android增量升级库，通过native层合并apk实现增量更新升级。

## 如何使用
引入jcenter库
```
implementation 'ren.yale.android:intremetalupdate:1.0.2'
```
代码添加
```
boolean ret = EasyIncrementalUpdate.patch(context,"new apk path","patch file")
```
或者
```
boolean ret = EasyIncrementalUpdate.patch("old apk path","new apk path","patch file")
```

> 可以根据ret的值判断是否成功，如果失败的话，可以全量更新，失败的原因可以在logcat TAG=EasyIncrementalUpdate 的日志

## 原理

服务器端通过开源差分工具[bsdiff](http://www.daemonology.net/bsdiff/)实现差分生成patch文件,客户端下载patch文件,
和本地原apk合并生产新的apk

## 服务器端差分工具使用

### windows
- 下载server/windows/[bsdiff.exe](server/windows/bsdiff.exe),下载server/windows/[bspatch.exe](server/windows/bspatch.exe)

差分命令
```
bsdff.exe old.apk new.apk patch
```
合并命令(可以用来测试)
```
bspatch.exe old.apk new.apk patch
```

### linux_x86-64
- 下载server/linux_x86-64/[bsdiff](server/linux_x86-64/bsdiff),下载server/linux_x86-64/[bspatch](server/linux_x86-64/bspatch)

差分命令
```
bsdff old.apk new.apk patch
```
合并命令(可以用来测试)
```
bspatch old.apk new.apk patch
```







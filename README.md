# EasyIncrementalUpdate

Android增量升级库，通过native层合并apk实现增量更新升级。

## 如何使用
- 引入jcenter库
```
implementation 'ren.yale.android:intremetalupdate:1.1.0'
```
- 代码添加

```
boolean ret = EasyIncrementalUpdate.patch(context,"new apk path","patch file")
```

或者

```
String oldApk = EasyIncrementalUpdate.getApkSourceDir(context);
boolean ret = EasyIncrementalUpdate.patch(oldApk,"new apk path","patch file")
```

> 可以根据ret的值判断是否成功，如果失败的话，可以全量更新，失败的原因可以看logcat TAG=EasyIncrementalUpdate的日志

- ndk abi 选择

在app/build.gradle中，请根据自己的需求选择

```
    defaultConfig {
        ...
        ndk {
            abiFilters 'x86', 'x86_64', 'armeabi', 'armeabi-v7a', 'arm64-v8a','mips'
        }
    }

```


## 原理

服务器端通过开源差分工具[bsdiff](http://www.daemonology.net/bsdiff/)实现差分生成patch文件,客户端下载patch文件,
和本地原apk合并生产新的apk

## 服务器端差分工具使用

### windows
- 下载server/windows/[bsdiff.exe](server/windows/bsdiff.exe),下载server/windows/[bspatch.exe](server/windows/bspatch.exe)

差分命令
```
bsdiff.exe old.apk new.apk patch
```
合并命令(可以用来测试)
```
bspatch.exe old.apk new.apk patch
```

### linux_x86-64
- 下载server/linux_x86-64/[bsdiff](server/linux_x86-64/bsdiff),下载server/linux_x86-64/[bspatch](server/linux_x86-64/bspatch)

差分命令
```
bsdiff old.apk new.apk patch
```
合并命令(可以用来测试)
```
bspatch old.apk new.apk patch
```

## 开源协议

```
MIT License

Copyright (c) 2017 Yale

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```







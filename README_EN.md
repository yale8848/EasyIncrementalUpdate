# EasyIncrementalUpdate

[![](https://img.shields.io/badge/jcenter-1.1.2-519dd9.svg)](https://bintray.com/yale8848/maven/easyincremetalupdate)

Android binary patch lib, merge APK with native code. This lib can use incremental update app, let download APK size more smaller.

## How Use
- Add jcenter lib
```
implementation 'ren.yale.android:intremetalupdate:1.1.2'
```
- Add code

```
boolean ret = EasyIncrementalUpdate.patch(context,"new apk path","patch file")
```

or

```
String oldApk = EasyIncrementalUpdate.getApkSourceDir(context);
boolean ret = EasyIncrementalUpdate.patch(oldApk,"new apk path","patch file")
```

> According to ret value judge whether successful,if false,you can download whole APK,and you can see error info with TAG=EasyIncrementalUpdate in LogCat.

- NDK abi chose

you can use abiFilters in app/build.gradle

```
    defaultConfig {
        ...
        ndk {
            abiFilters 'x86', 'x86_64', 'armeabi', 'armeabi-v7a', 'arm64-v8a','mips'
        }
    }

```


## Principle

use open source code [bsdiff](http://www.daemonology.net/bsdiff/) crate patch file in server, then client download patch file add merge to a new file.


## Server tools

### windows
- download server/windows/[bsdiff.exe](server/windows/bsdiff.exe),download server/windows/[bspatch.exe](server/windows/bspatch.exe)

diff
```
bsdiff.exe old.apk new.apk patch
```
patch
```
bspatch.exe old.apk new.apk patch
```

### linux_x86-64
- download server/linux_x86-64/[bsdiff](server/linux_x86-64/bsdiff),download server/linux_x86-64/[bspatch](server/linux_x86-64/bspatch)

diff
```
bsdiff old.apk new.apk patch
```
patch
```
bspatch old.apk new.apk patch
```

## Issue

[Issue](https://github.com/yale8848/EasyIncrementalUpdate/issues)

## How to contributing

[How to contributing](CONTRIBUTING.md)

## License

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







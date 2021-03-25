# MGL_RPi
Minatsu Game Library for Raspberry Pi without X11

# コンパイルの準備
デフォルトのSDL2ライブラリを削除して、SDL2をソースコードからインストールする。

参考: https://choccyhobnob.com/sdl2-2-0-8-on-raspberry-pi/
```
$ sudo apt remove -y --force-yes libsdl2-dev
$ sudo apt autoremove -y
$ sudo apt install libfontconfig-dev qt5-default automake mercurial libtool libfreeimage-dev libopenal-dev libpango1.0-dev libsndfile-dev libudev-dev libtiff5-dev libwebp-dev libasound2-dev libaudio-dev libxrandr-dev libxcursor-dev libxi-dev libxinerama-dev libxss-dev libesd0-dev freeglut3-dev libmodplug-dev libsmpeg-dev libjpeg-dev libdrm-dev libgbm-dev
$ hg clone http://hg.libsdl.org/SDL
$ cd SDL
$ ./autogen.sh
$ ln -s sdl2-config.cmake.in sdl2-config-version.cmake.in
$ ./configure --host=arm-raspberry-linux-gnueabihf --disable-pulseaudio --disable-esd --disable-video-wayland --disable-video-x11 --disable-video-opengl --disable-video-rpi --enable-video-kmsdrm
$ make
$ sudo make install
```

# サンプルのコンパイルのしかた
```
$ git clone --recursive https://github.com/MinatsuT/MGL_RPi.git
$ cd MGL_RPi
$ make
```

# 実行のしかた
```
$ ./sample1
```
コンソールから実行した場合はESCキー、ssh等でリモート起動の場合はCtrl+Cで終了します。
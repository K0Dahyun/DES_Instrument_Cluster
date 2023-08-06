## Cross Compile
Now, we need to design the dashboard in the Qt development environment. 
However, the Raspberry Pi has a low-end specification for Qt development. 
Therefore, we develop Qt on a high-spec laptop, compile it, and then transfer only the executable file to the Raspberry Pi. 
In reality, we faced difficulties in setting up this cross-compilation environment. 
Be aware that the setup process varies depending on each OS version.

## PRECONDITION

| Host        | Target       |
| :-------------:|:-------------: |
| DELL G15 5520 | Raspberry Pi 4 |
| Ubuntu 20.04 LTS | Raspberry Pi 4 Linux 64-bit OS |


## Reference
[QT CROSS-COMPILE SETTINGS
SCRIPTS FOR RASPBERRY PI 4](https://www.interelectronix.com/kr/qt-raspberry-pi-4yong-keuloseu-keompail-seoljeong-seukeulibteu.html)

[Cross-Compile Qt 6 for Raspberry Pi](https://wiki.qt.io/Cross-Compile_Qt_6_for_Raspberry_Pi)

[QT 5.15 CROSS COMPILE FOR RASPBERRY COMPUTE MODULE 4 ON UBUNTU 20 LTS
](https://www.interelectronix.com/qt-515-cross-compilation-raspberry-compute-module-4-ubuntu-20-lts.html)


## Raspberry(Target machine)
1. First add development sources to /etc/apt/sources.list. To do this, add the following line:
   ```c
   deb-src http://raspbian.raspberrypi.org/raspbian/ buster main contrib non-free rpi
   ```
2. Then update the system with the following commands:
   ```c
   sudo apt-get update
   sudo apt-get dist-upgrade
   sudo reboot
   sudo rpi-update
   sudo reboot
   ```
3. And then install the required Qt and development packages:
   ```c
   sudo apt-get build-dep qt5-qmake
   sudo apt-get build-dep libqt5gui5
   sudo apt-get build-dep libqt5webengine-data
   sudo apt-get build-dep libqt5webkit5
   sudo apt-get install libudev-dev libinput-dev libts-dev libxcb-xinerama0-dev libxcb-xinerama0 gdbserver
   ```
4. Then create a directory for RaspberryQt:
   ```c
   sudo mkdir /usr/local/qt5.15
   sudo chown -R pi:pi /usr/local/qt5.15
   ```


## Ubuntu(Host Machine)

1. First of all, bring Ubuntu up to date and install some required libraries:
   ```c
    sudo apt-get update
    sudo apt-get upgrade
    sudo apt-get install gcc git bison python gperf pkg-config gdb-multiarch
    sudo apt install build-essential
  ```
2. Create directory structure for the raspberry libraries
  ```c
    sudo mkdir ~/Documents/Qt-CrossCompile-RaspberryPi/raspberrypi4
    sudo mkdir ~/Documents/Qt-CrossCompile-RaspberryPi/raspberrypi4/build
    sudo mkdir ~/Documents/Qt-CrossCompile-RaspberryPi/raspberrypi4/tools
    sudo mkdir ~/Documents/Qt-CrossCompile-RaspberryPi/raspberrypi4/sysroot
    sudo mkdir ~/Documents/Qt-CrossCompile-RaspberryPi/raspberrypi4/sysroot/usr
    sudo mkdir ~/Documents/Qt-CrossCompile-RaspberryPi/raspberrypi4/sysroot/opt
    sudo chown -R 1000:1000 ~/Documents/Qt-CrossCompile-RaspberryPi/raspberrypi4
    cd ~/Documents/Qt-CrossCompile-RaspberryPi/raspberrypi4
  ```
3. Download Qt Resources and Modify mkspec to use our compiler
   ```c
     sudo wget http://download.qt.io/archive/qt/5.15/5.15.2/single/qt-everywhere-src-5.15.2.tar.xz
     sudo tar xfv qt-everywhere-src-5.15.2.tar.xz
  
     cp -R qt-everywhere-src-5.15.2/qtbase/mkspecs/linux-arm-gnueabi-g++ qt-everywhere-src-5.15.2/qtbase/mkspecs/linux-arm-gnueabihf-g++
     sed -i -e 's/arm-linux-gnueabi-/arm-linux-gnueabihf-/g' qt-everywhere-src-5.15.2/qtbase/mkspecs/linux-arm-gnueabihf-g++/qmake.conf
   ```
4. Download Cross-compiler
   ```c
     sudo apt install gcc-aarch64-linux-gnu g++-aarch64-linux-gnu
   ```
5. Rsync of raspberry libraries
   ```c
     rsync -avzS --rsync-path="rsync" --delete <pi_username>@<pi_ip_address>:/lib/ sysroot/lib
    rsync -avzS --rsync-path="rsync" --delete <pi_username>@<pi_ip_address>:/usr/include/ sysroot/usr/include
    rsync -avzS --rsync-path="rsync" --delete <pi_username>@<pi_ip_address>:/usr/lib/ sysroot/usr/lib
    rsync -avzS --rsync-path="rsync" --delete <pi_username>@<pi_ip_address>:/opt/vc/ sysroot/opt/vc
   ```
6. Clean up the symbolic links 
  ```c
    sudo apt install symlinks
    cd ~
    symlinks -rc sysroot
  ```
7. Compiling Qt
   ```c
     cd build
     ../qt-everywhere-src-5.15.2/configure -release -opengl es2  -eglfs -device linux-rasp-pi4-aarch64 -device-option CROSS_COMPILE=aarch64-linux-gnu- -sysroot ~/Documents/Qt-CrossCompile-RaspberryPi/raspberrypi4/sysroot -prefix /usr/local/qt5.15 -extprefix ~/Documents/Qt-CrossCompile-RaspberryPi/raspberrypi4/qt5.15 -opensource -confirm-license -skip qtscript -skip qtwayland -skip qtwebengine -nomake tests -make libs -pkg-config -no-use-gold-linker -v -recheck
  ```
8. After a few minutes, the script should be finished and the following EGLFS conditions should be set or not set.
  ```c
    QPA backends:
      DirectFB ............................... no
      EGLFS .................................. yes  [SHOULD BE YES]
      EGLFS details:
        EGLFS OpenWFD ........................ no
        EGLFS i.Mx6 .......................... no
        EGLFS i.Mx6 Wayland .................. no
        EGLFS RCAR ........................... no
        EGLFS EGLDevice ...................... yes  [SHOULD BE YES]
        EGLFS GBM ............................ yes
        EGLFS VSP2 ........................... no
        EGLFS Mali ........................... no
        EGLFS Raspberry Pi ................... no   [SHOULD BE NO]
        EGLFS X11 ............................ yes
      LinuxFB ................................ yes
      VNC .................................... yes
  ```
9. If everything is OK, then run the make and make install commands.
    ```c
      make -j4
      make install
    ```
10. Install compiled files on the Raspberry
  ```c
  rsync -avz --rsync-path="sudo rsync" qt5.15 pi@192.168.1.7:/usr/local/
  ```
   

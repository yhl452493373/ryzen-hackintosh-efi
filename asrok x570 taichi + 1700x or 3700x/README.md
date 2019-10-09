我的测试系统版本：macOS 10.14.6 Mojave

BIOS设置：
BIOS SETTING:

把CSM关掉
change CSM to disable

超频啥的根据自己需求来改

目前支持：Mojave 10.14.6 (18G84, 18G87, 18G95, 18G103)以及Catalina 10.15

根据自己的情况，复制10.14或10.15下的CLOVER目录到EFI目录下，之后按正常安装方式安装。如果安装10.15后第一次启动时键盘鼠标没反应，则用10.15的kexts-off下的VoodooI2C.kext、VoodooI2CHID.kext、VoodooPS2Controller.kext替换kexts下的
AppleACPIPS2Nub.kext、ApplePS2Controller.kext、ApplePS2SmartTouchPad.kext，之后按重启键或长按电源键重启


注意：睡眠任然有问题，进入系统后禁用睡眠。另外进入系统后如果是英文，自行在系统偏好设置-语言与地区中把中文移动到第一个，然后重启即可

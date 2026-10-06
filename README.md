# Introduction 
This project was created to learn more about the BeagleBone Black and, more generally, the communication protocols commonly used in embedded systems. It is a complementary project that should be done with a Beagle V Fire. In this scenario, the Beaglebone black took the role of the I2C Master, while the Beagle V Fire took the role of the target. Moreover, the Beagle V Fire contains a design, which is implemented by another person, not me, a college, and is used to control the USER LEDs available on the board.

# Installation Requirements
Before compiling, please install the following packages, depending on your setup.

## Debian-based
```bash
sudo apt-get install build-essential cmake git gcc
```

## RHEL-based
```bash
sudo dnf group install c-development
sudo dnf group install "development-tools"
sudo dnf install cmake
```

## ARM tool chain
Also, the project was compiled and tested using arm-gnu-toolchain-15.3; please consider using this.<br>

**IMPORTANT: If you do not have ANY ARM-compatible compiler on your system, you must install one; otherwise, this project won't compile, as the Beablebon black platform uses the Sitara am335x, an ARM processor.**<br>

To download the ARM toolchain I was using for the purpose of this project, please download the following from the ARM repositories using the following command (or navigate to the site: https://gitlab.arm.com/tooling/gnu-toolchains-for-arm/-/tree/releases/15.3.rel1).

```bash
wget https://gitlab.arm.com/api/v4/projects/tooling%2Fgnu-toolchains-for-arm/packages/generic/gnu-toolchain/15.3.rel1/arm-gnu-toolchain-15.3.rel1-x86_64-arm-none-eabi.tar.xz
```
```bash
tar -xf arm-gnu-toolchain-15.3.rel1-x86_64-arm-none-eabi.tar.xz
```
```bash
export PATH="PATH_TO_DOWNLOAD_FOLDER/arm-gnu-toolchain-15.3.rel1-x86_64-arm-none-eabi/bin:PATH"
```



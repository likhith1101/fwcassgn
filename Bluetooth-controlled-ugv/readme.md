# To copy repository
svn co https://github.com/likhith1101/fwcassgn/trunk/Bluetooth-controlled-ugv


# To build ESP32 firmware

cd esp32_pwmctrl
pio run
# To flash ESP32 firmware, connect usb-uart adapter
pio run -t nobuild -t upload
# If using termux, use scp to send .pio/build/esp32doit-devkit-v1/firmware.bin to PC

# To build m4 firmware
cd m4_pwmctrl/GCC_Project
# modify line 140 of config.mk to setup path to pygmy-sdk or qorc-sdk
# default path is /data/data/com.termux/files/home/pygmy-dev/pygmy-sdk 
make
# If using termux, Use scp to send output/m4_pwmctrl.bin to PC

# To build fpga source
cd fpga_pwmctrl/rtl
ql_symbiflow -compile -d ql-eos-s3 -P pu64 -v *.v -t AL4S3B_FPGA_Top -p quickfeather.pcf -dump jlink binary
# If using termux, use scp to send AL4S3B_FPGA_Top.bin to PC

# To flash eos s3 soc, connect usb cable to vaman board
sudo python3 <Type path to tiny fpga programmer application> --port /dev/ttyACM0  --appfpga AL4S3B_FPGA_Top.bin --m4app m4_pwmctrl.bin --mode m4-fpga --reset

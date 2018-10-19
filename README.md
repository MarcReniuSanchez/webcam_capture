# Webcam Capture

This project uses `OpenCV` library to open, read and show image data from a webcam device.

## Dependencies / Libraries

- `C++`
- `libopencv-dev`
- `CMake`

```bash
$ sudo apt-get install g++ cmake libopencv-dev
```

## Installation

- Make sure you have installed all dependencies showed in the previous section.

- Create a `build` folder and compile the project

```bash
$ mkdir build && cd build
$ cmake ..
$ make
```

- Done!

## Usage

To start the executable, `./webcam_capture`.
If the device has access to multiple webcams, you can choose which one to use adding a numeral as a parameter, for example `./webca-m_capture 1` ( the code will detect if the device exists).

To exit/close the executable, press `q` in the keyboard, or `Ctrl + C` in the terminal.

## Tips

- https://wiki.archlinux.org/index.php/webcam_setup
- http://www.linuxintro.org/wiki/Set_up_a_Webcam_with_Linux

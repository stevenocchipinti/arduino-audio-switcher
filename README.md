Arduino Audio Switcher
======================

This codebase has two parts:

1. Web front-end
2. Arduino


Web front-end
-------------

To start a dev environment:

```
yarn
yarn start
```


Arduino
-------

While you can use the Arduino IDE or similar, I'm attempting to use an alpha
build of the `arduino-cli` for this project.

- Download `arduino-cli` from here: https://github.com/arduino/arduino-cli
- Ensure `arduino-cli` available in the `$PATH`
- Copy `arduino/config.h.example` to `arduino/config.h` and enter wifi
  credentials


Building, compiling and uploading
---------------------------------

:warning: Currently `build` works but `upload` doesn't. :man_shrugging:

To get the completed code on to the arduino:

```
yarn
yarn build
yarn upload
```

Note, there are also commands to build each step individually, see
`package.json` for each of the scripts.

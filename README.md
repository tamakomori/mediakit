MediaKit
=======

`MediaKit` is a library designed to abstract modern gaming platforms
and provide common interfaces for the upper layer program. The library
includes 10 functional components covering asset file access, save
data access, image manipulation, font rendering, audio processing,
graphics rendering, sound mixing, input handling, and system
features. The codebase is modularized to support multiple platforms:
Windows, macOS, Linux, iOS, Android, Web browsers, and gaming
consoles.

## Layers

`MediaKit` acts as a HAL (hardware abstraction layer) for user
games. It absorbs differences of platforms to make the upper layer
code single and common.

```
+-----------------------------------------------+
| Upper Layer Code (Platform-Independent)       |
+-------------+---------+-----------------------+
| Windows HAL | iOS HAL | (Platform HALs) ...   |
+-------------+---------+-----------------------+
```

## Callbacks

The following callbacks form the skeleton of the application because
HAL provides a C entrypoint `main()`.

|Callback Function    |Details                                                        |
|---------------------|---------------------------------------------------------------|
|on_hal_init_render() |This callback must return the window title and the size.       |
|on_hal_ready()       |This callback may prepare the rendering objects.               |
|on_hal_frame()       |This callback must do a frame rendering.                       |

## Components

`MediaKit` is composed of 10 distinct functional components that form
the core of its architecture. Each component serves a specific purpose
in the framework, from handling basic file operations to complex
graphics rendering. The implementation of these essential components
is managed through a variety of platform-dependent modules, ensuring
optimal performance across different operating systems and
environments.

|Component |Description                   |
|----------|------------------------------|
|file      |Asset access.                 |
|stor      |Save data access.             |
|image     |Image manipulation.           |
|font      |Font drawing.                 |
|wave      |Audio decoding.               |
|render    |Graphics rendering.           |
|mixer     |Audio playback.               |
|input     |Key and gamepad input.        |
|sys       |System features.              |
|shader    |Shader parser.                |

## The modules of the implementation

Each component in our library is implemented by a platform-specific C
module to adopt across operating systems. The table below maps modules
to their supported platforms, showing our cross-platform
implementation strategy and helping developers identify which modules
handle specific functionality.

|Module     |Description                           |Linux  |Windows|macOS  |iOS    |Android|Web    |
|-----------|--------------------------------------|-------|-------|-------|-------|-------|-------|
|stdfile    |file component for standard C.        |v      |v      |v      |v      |       |v      |
|ndkfile    |file component for Android NDK.       |       |       |       |       |v      |       |
|stdstor    |stor component for standard C.        |v      |v      |v      |v      |       |v      |
|ndkstor    |stor component for Android NDK.       |       |       |       |       |v      |       |
|image      |image component.                      |v      |v      |v      |v      |v      |v      |
|stdfont    |font component for standard C.        |v      |v      |v      |v      |v      |v      |
|glrender   |render component for OpenGL.          |v      |       |       |       |v      |v      |
|vkrender   |render component for Vulkan.          |       |       |       |       |       |       |
|dx11render |render component for DirectX 11.      |       |v      |       |       |       |       |
|dx12render |render component for DirectX 12.      |       |v      |       |       |       |       |
|metalrender|render component for Metal.           |       |       |v      |v      |       |       |
|alsamixer  |mixer component for ALSA.             |v      |       |       |       |       |       |
|dsmixer    |mixer component for DirectSound 5.    |       |v      |       |       |       |       |
|aumixer    |mixer component for AudioUnit.        |       |       |v      |v      |       |       |
|almixer    |mixer component for OpenAL.           |       |       |       |       |v      |v      |
|linuxmain  |sys component for Linux.              |v      |       |       |       |       |       |
|winmain    |sys component for Windows.            |       |v      |       |       |       |       |
|nsmain     |sys component for macOS.              |       |       |v      |       |       |       |
|uimain     |sys component for iOS.                |       |       |       |v      |       |       |
|ndkmain    |sys component for NDK.                |       |       |       |       |v      |       |
|emmain     |sys component for Emscripten.         |       |       |       |       |       |v      |
|shaderv1   |shader component. (version 1)         |v      |v      |v      |v      |v      |v      |

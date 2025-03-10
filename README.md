# Welcome to Pxit!

<img align="left" style="width:128px; margin-right: 16px; image-rendering: pixelated" src="./logo.png" width="128px">

**Pxit is a simple windowing library to make building software enjoyable again!**

Inspired by a lot of other libraries (GLFW, OpenGL, SDL, Vulkan, imgui, raylib), Pxit was designed with focus on **simplicity** and **ease of use** for new and experienced programmers.

### Ready for some examples?
---
<br/>

<div style="background-color: #ff4400aa; padding: 16px">
<h3 style="margin: 0px"><b> ⚠️ DISCLAIMER (WIP) ⚠️ </b></h3>
<hr/>
This library is a work in progress and has a lot of updates and testing left to do.
There will be daily updates to this library and hopefully will become a mature API
soon. Please stay tuned for new updates!
</div>

## Basic window
Below is an example on how to create a basic window with pxit
```c
#include <pxit/pxit.h>

int main()
{
    WindowCreateInfo create_info = {};
    create_info.Width   = 800;
    create_info.Height  = 600;
    create_info.pTitle  = "My Window";
    CreateWindow(&create_info, NULL);

    while (ReadEvents());
}
```
<br>
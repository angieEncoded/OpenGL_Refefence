# The Cherno course and notes
- Linking
  - Right click Project -> Properties -> C\C++ -> General -> Additional Include Directories
  ``` $(SolutionDir)Dependencies\GLFW\include ```
  - Right click Project -> Properties -> Linker -> General -> Additional Library Directories
  ``` $(SolutionDir)Dependencies\GLFW\lib-vc2022 ```
  - Right click Project -> Properties -> Linker -> Input -> Additional Dependencies
  ``` glfw3.lib; opengl32.lib;User32.lib;Gdi32.lib;Shell32.lib ```
- Handling broken links
  - Build the project
  - See a bat shit scary error message like such:
    ```1>glfw3.lib(win32_monitor.obj) : error LNK2019: unresolved external symbol __imp__CreateDCW@16 referenced in function __glfwPlatformGetGammaRamp```
  - Copy the almost-words part of the symbol it's looking for
    ```CreateDCW```
  - Search that in google and get to the msdn page
  ```https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createdcw```
  - Scroll down to the requirements where it tells you the library file it wants
  ```Gdi32.lib```
  - Now you can paste that right into the the Additional Dependencies from above

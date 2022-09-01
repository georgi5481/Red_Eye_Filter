# Red_Eye_Filter entry task for Ocado technology

For compiling cross platform :
 Check your OS first.     
     

If on Windows (tested on Windows 11): 
    - You need to make sure you already have installed CMake at least 3.5.1.  If you do not have it installed please download it. Link : 
    https://cmake.org/download/
    -Make sure you have installed MinGW on your Windows. If you do not have it installed please download it. Link : 
    https://techdecodetutorials.com/download/ 
    -Please set the Setup Environment Variables Paths in Windows 11 (in case you have the same problem as me setting the MinGW generator). Please read the following article for more information :
    https://techdecodetutorials.com/how-to-install-mingw-c-c-compiler-in-windows-11/
    
    
Please place the to .bin files in the release folder. Or download them from the link: 
https://drive.google.com/file/d/1nb1PiP0FOEng8BxY4CdfOA2SSGVX2O6j/view

To compile on Linux:
Open terminal and change to the directory of the empty release folder provided in the project. Example path: "/usr/The/current/path/Red_Eye_Filter/Release/".
And write in the terminal:    
cmake ..    
make -j
(It will use the automatically selected generator - Unix Makefiles, unless specified otherwise)

To compile on Windows:
Open cmd and change to the directory of the release folder. Example path: "C:\The\current\path\Red_Eye_Filter\Release>".
And write in the console:     
cmake -G "MinGW Makefiles" ..
make -j

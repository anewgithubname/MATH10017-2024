
# Table of Contents

- [Table of Contents](#table-of-contents)
- [Download the labpack](#download-the-labpack)
- [Extract the zip file using 7zip](#extract-the-zip-file-using-7zip)
    - [7zip is a popular decompression tool and has been preinstalled on all lab computers. However, if you have not installed 7zip on your computer, you can download and install it here: https://www.7-zip.org/. You can use windows to decompress the labpack, but it will be slow.](#7zip-is-a-popular-decompression-tool-and-has-been-preinstalled-on-all-lab-computers-however-if-you-have-not-installed-7zip-on-your-computer-you-can-download-and-install-it-here-httpswww7-ziporg-you-can-use-windows-to-decompress-the-labpack-but-it-will-be-slow)
- [Using the labpack](#using-the-labpack)
- [Compiling “Hello, world!”](#compiling-hello-world)
- [Compiling from the terminal](#compiling-from-the-terminal)



<a id="orgfc940b1"></a>

# Download the labpack

Click [here](https://uob-my.sharepoint.com/:u:/g/personal/sl9885_bristol_ac_uk/EUHEsCCFDeFMlX_1UAocAh4By7JVjJoBHhcFMVyEXwghxA) to find the labpack on sharepoint; you may have to enter your ID and password.

Click &ldquo;download the entire zip file&rdquo;.

![img](./cap5.PNG)

Save the file.

![img](./cap6.PNG)

Wait until the download is complete before trying to open it.
If it says &ldquo;Download Failed&rdquo;, click the circular arrow to restart the download.

Open the file in the file explorer:

![img](./cap8.PNG)


<a id="orgc0e3084"></a>

# Extract the zip file using 7zip

### 7zip is a popular decompression tool and has been preinstalled on all lab computers. However, if you have not installed 7zip on your computer, you can download and install it here: https://www.7-zip.org/. You can use windows to decompress the labpack, but it will be slow. 

----- 
Right click on the labpack and unzip it using 7zip (choose &ldquo;Extract here&rdquo;):

![img](./cap10.PNG)

It will take about 5 minutes to unzip.


<a id="org4c5f3b0"></a>

# Using the labpack

Open the labpack:

![img](./cap12.PNG)

Double-click on the &ldquo;lab<sub>1</sub>&rdquo; .bat file to launch VSCode:

![img](./cap13.PNG)

(If it says you can&rsquo;t open it, click &ldquo;more info&rdquo;, then say &ldquo;open anyway&rdquo;.)

Accept the trust settings:

![img](./cap14.PNG)


<a id="orgf4bff3e"></a>

# Compiling &ldquo;Hello, world!&rdquo;

Double click on &ldquo;main.c&rdquo; to see the code for &ldquo;Hello, world!&rdquo;.

From the top menu, choose &ldquo;Start Debugging&rdquo; from the &ldquo;Run&rdquo; category:

![img](./cap16.PNG)

Choose &ldquo;C++ (GDB/LLDB)&rdquo;:

![img](./cap17.PNG)

Choose &ldquo;gcc&rdquo;:

![img](./cap18.PNG)

After a while, you should see a menu on the bottom half of VSCode.
Select &ldquo;TERMINAL&rdquo; to see the output of the program:

![img](./cap19.PNG)


<a id="orgbce88a6"></a>

# Compiling from the terminal

Type &ldquo;ls&rdquo; (letter l, not number 1) in the terminal and hit &ldquo;enter&rdquo;:

![img](./cap20.PNG)

This shows files in the current directory (folder): main.c is the hello world program we compiled, and main.exe is the program that the compiler output.

To compile from the command line, type `gcc main.c -o main.exe` in the terminal and hit enter.
To run the program, type `./main.exe`.

![img](./cap21.PNG)


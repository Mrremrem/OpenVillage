# OpenVillage
A village game thing
![Github intro image thingy](/Assets/Media/Github_Intro_Image.png)

# Intro
Hey thanks for stopping by! So I made a simple, open tile game that features a lot of flowers (a grand total of three at the moment). You can move around the world that exists far from the vast oceans and explore all sorts of grass and colorful flowers that stand for nature. Oh and you can also make your own world if you want to take control environmentally/politically (currently in a text file, check out Assets/Media/Maps for an example). So you can see that this project is not just an ordinary project--it is unique in both creativity from me and (in the near, near future) you. Please watch your step as I take you to the compiling section.

# Compiling
## Compile in Linux
### That's right, [Richard](https://old.reddit.com/r/copypasta/comments/7lt7i0/no_richard_its_linux_not_gnulinux/), I said Linux.
Anyway, to compile this for the distro you're using, you're gonna want to get these packages from whichever [package manager](https://en.wikipedia.org/wiki/Package_manager) you're using <br />
* [CMake](https://cmake.org/) (For my organization skills. Highly recommend using the GUI version even if you're a [wm](https://en.wikipedia.org/wiki/Window_manager) user like *moi*)<br />
* [SFML](https://www.sfml-dev.org/) For the graphics (Most distros will have SFML prebuilt in their repository)<br />
* And your favorite C++ compiler ([I'm using Clang++](https://clang.llvm.org/))<br />
Then you'd want to use CMake to, well, do the magic:<br />

```
cmake CMakeLists.txt
cmake --build .
```

Please send me any error logs. I don't have another machine to test this yet! [(other than my Nintendo Switch)](https://www.youtube.com/watch?v=rVuNvIrsAg8&t=1s) Best wishes <3
## Compiling for Windows/Mac users
### ¯\\_ (ツ)_/¯
I'm guessing it's the same as the one above for Linux (I'm not using either at the moment). I'll probably just give out binary files for each sometime in the following months (I'm going back to school this week!) Also, I'm obligatoried/obligated (is that even a word?) to say that I've successfully picked up that emoticon's arm and placed it back correctly! ...Anyway I'll get to it when the time comes :P

# Designs and Problems I've encountered
I started writing all of the problems/ideas I had in mind while making OpenVillage and I thought it'd be wise to write it all out for future reference. If anyone's interested in reading or wanting to avoid repeating history, [(here's a doc that has everything.)] (https://docs.google.com/document/d/1mOTh3PXjUBtSpxSRjTBltybuhi8stifmhpHf8aiQ744/edit?usp=sharing)

# spatula
![](spatula.svg)
Spatula is a shell script that automatically generates programming environments based on a config file.
## Synopsis
spatula [ProjectName]
## Description
Spatula works by echoing out data into a file. It is a very basic program, and can be easily modified.
## Installing
Just use the current release. However, if you want to install it manually:
Take the ```spatula.1``` file and put it in ```/usr/share/man/man1/``` and put the ```spatula``` file in ```/usr/bin/```. When in /usr/bin/, do 
```
chmod +x ./spatula
```
Then in /opt/spatula/ put spatula.cfg

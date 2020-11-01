# Installation #

The *Calculus* library can be installed in two different ways: cloning this repository using Git on your host, or downloading the repository as a ZIP file and installing it from the Arduino IDE.  For either procedure you need to know where your IDE stores user-installed libraries.

1. Open the Arduino IDE.
2. From the menu click *File* -> *Preferences*.
3. Make note of the "Sketchbook location:" field.  For example, on a Windows system it might say `C:\Users\the_doctor\Arduino`.  In this case, libraries are stored in `C:\Users\the_doctor\Arduino\libraries`.
4. Jot your sketchbook location down somewhere and tack `\libraries` (Windows) or `/libraries` (Max OS X or Linux) onto the end.  You will need this later.

## Install using Git ##

Git is available for all the same operating systems (Windows, Mac OS X, Linux) which can run the Arduino IDE.  Git graphical user interfaces for most if not all of these operating systems exist, but they're different enough that it's not practical to include instructions for all of them.  What *is* available on all systems is the Git command line interface.  So here are the instructions for using the Git CLI.

1. If you haven't already, download and install Git for your operating system.  Git can be downloaded from [https://git-scm.com/downloads](https://git-scm.com/downloads).
2. Open a command shell on your host.  On my Windows system, I use Git Bash, which installs with Git.
3. Change to your `libraries` directory.  From Git Bash, that might look like:

	`$ cd /c/Users/the_doctor/Arduino/libraries`
1. From a web browser, go to this library's repository at [https://github.com/twrackers/Calculus-library](https://github.com/twrackers/Calculus-library).
2. Click on the green `Code` button, then under "Clone" click on the little clipboard symbol on the right.  This copies the URL of the repository to your clipboard.
1. In your command shell, type "git clone ", then paste the URL from the previous step into your command line.  You should see:

	`$ git clone https://github.com/twrackers/Calculus-library.git`
1. Hit `Enter` to clone the repository into your `libraries` directory.
2. If your Arduino IDE is running, close it now.
3. If you type `ls -l`, you will see a list of your libraries, including one named `Calculus-library-main`.  It needs to be renamed:
 
	`$ mv Calculus-library-main Calculus`
1. You can now start the Arduino IDE again.  If from the menu you click *Sketch* -> *Include Library*, you should be able to scroll down to find `Calculus`.

## Install ZIP file from Arduino IDE ##

1. From a web browser, go to this library's repository at [https://github.com/twrackers/Calculus-library](https://github.com/twrackers/Calculus-library).
2. Click on the green `Code` button, then click `Download ZIP`.  Save the downloaded file somewhere where you'll be able to find it.
3. If your Arduino IDE isn't already running, start it now.
4. From the menu, click *Sketch* -> *Include Library* -> *Add .ZIP Library...*.  This will open a file chooser window.
5. Locate the ZIP file you downloaded, then open it.  This will install the library to your `libraries` directory.
6. Close the Arduino IDE for now.
7. Navigate to your `libraries` directory.  You will see a directory named `Calculus-library-main`.  Rename it to simply `Calculus`.
8. You can now start the Arduino IDE again.  If from the menu you click *Sketch* -> *Include Library*, you should be able to scroll down to find `Calculus`.
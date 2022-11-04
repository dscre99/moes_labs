'QUICK' SETUP GUIDE TO COMPILE AND LINK SYSTEMC LIBRARY (Ubuntu)

-- INSTALLING SYSTEMC LIBRARY --
1- Download SystemC 2.3.2 from the following link (be careful with the version!)

	https://www.accellera.org/downloads/standards/systemc
	
2- Decompress the package using the command

	$tar -xvf systemc-2.3.2.tar.gz

3. Change to the top level directory systemc-2.3.2

	$cd systemc-2.3.2

4. Make a directory “objdir” in the directory systemc-2.3.2

	$mkdir objdir

5. Change to objdir

	$cd objdir

6. now type:

	$export CXX=g++

7. Run configure from objdir (same path on PoliTo's machined predefined in Lab files):

	$../configure --prefix=/software/SystemC/systemc-2.2.0
	
	or you need to make your own directory (but remember
	to change the path in the Makefile.defs file in the labs directories)
	
	$../configure --prefix=/software/SystemC/systemc-2.3.2
	
	or you can use default installation directory path. I'll use this configuration from now on
	
	$../configure --prefix=/usr/local/systemc-2.3.3

8. And then:

	$sudo make

9. Install by typing command:

	$sudo make install
	
10. Use following command to export variable SYSTEMC_HOME:

	$export SYSTEMC_HOME=/usr/local/systemc-2.3.3
	
11. As last step it is needed to add the SystemC library path to the dynamic libraries environment variable. Use the following command:

	$export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/usr/local/systemc-2.3.3/lib-linux64/
	
  In alternative (if the previous does not solve the run-time library binding) manually create a link to the systemc-2.3.3.so dynamic library. Move to the libraries folder in the system:
  
  	$sudo ln -s /usr/local/systemc-2.3.3/lib-linux64/libsystemc-2.3.3.so .
  	
  finally create the soft link:
  
  	$sudo ln -s /usr/local/systemc-2.3.3/lib-linux64/libsystemc-2.3.3.so .


-- UNINSTALLING SYSTEMC LIBRARY --
Repeat steps from 1 to 7 of the install guide.

8. Run the following command:

	$sudo make uninstall
	
9. Remove remaining files from the installation directory:

	$rm -rf /usr/local/systemc-2.3.3	


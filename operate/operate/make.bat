del *.obj *.exe /F
call path.bat
cl operate.cpp
operate.exe >operate.log
operate.exe 


set PATH=%NXP_MBD_S32K3_GCC_PATH%\bin;%PATH%

cd .

if "%1"=="" ("D:\AppGallery\Software\MATLAB\R2023b\bin\win64\gmake"  -f S32K344_LED.mk -j all) else ("D:\AppGallery\Software\MATLAB\R2023b\bin\win64\gmake"  -f S32K344_LED.mk -j %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1
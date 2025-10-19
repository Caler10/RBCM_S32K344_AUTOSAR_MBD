
set PATH=%NXP_MBD_S32K3_GCC_PATH%\bin;%PATH%

cd .

if "%1"=="" ("D:\AppGallery\MATLAB\R2024b\bin\win64\gmake"  -f RBCM_Model.mk -j all) else ("D:\AppGallery\MATLAB\R2024b\bin\win64\gmake"  -f RBCM_Model.mk -j %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1
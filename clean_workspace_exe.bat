@echo off
cd /d %~dp0  REM 切换到当前脚本所在目录

REM 删除当前目录下的所有 .exe 文件
del *.exe /q /s

echo Delete .exe files ok!
pause

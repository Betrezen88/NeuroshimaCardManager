# NeuroshimaCardManager

### Technology

Qt version: 5.15.2

### How to deploy app ?

##### Windows

Qt documentation site: https://doc.qt.io/qt-5/windows-deployment.html

1. Build project.
2. Create deploy folder.
3. Copy binary file to deploy folder
4. Open console.
5. Go to Qt framework folder and find proper windeployqt version (example: C:\Qt\5.14.1\mingw73_64\bin)
6. Run windeployqt.exe

	windeployqt --qmldir /path/to/project/source/qml/files /path/to/binary/file

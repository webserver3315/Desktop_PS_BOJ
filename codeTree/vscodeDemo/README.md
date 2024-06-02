- [Setting Reference](https://skyqnaqna.tistory.com/entry/VS-Code%EC%97%90%EC%84%9C-WSL-2%EC%99%80-C-%EC%82%AC%EC%9A%A9%ED%95%98%EA%B8%B0)
- you should open vscode in wsl2, using ctrl P + "WSL2: Connect to WSL2 in New Window"
- see .vscode/launch.json and .vscode/tasks.json for setup detail

- Simply Run
    - Build: Ctrl Shift B
    - Run: ./BINFILE input.txt > result.txt; diff result.txt output.txt;
- Debug: F5
    - Step: F10
    - **Make sure you have gdb by 'which gdb'**
